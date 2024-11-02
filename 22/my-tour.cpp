#include <functional>
#include <iostream>
#include <ostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>
using std::stack, std::cin, std::cout, std::cerr, std::endl, std::vector,
    std::unordered_set, std::ostream, std::string;

/* Version 1.0 */

/* Version 1.1 (minor optimizations)

 * factor out the check for "if reachable position valid and not in visited", to
 * hopefully improve speed a bit?

 * also remove the generation code just hardcode values for reachable

 * remove unnecessary getter methods by using `friend`

 * cache these reachable calls
*/

#define __DBG_FLAG__ 0

#define LOG           \
    if (__DBG_FLAG__) \
    cerr

// macro for logging when debug is enabled
#define DBG(x)          \
    LOG << #x << " = "; \
    PRINT_DBG(x);       \
    LOG << " ";

template <typename T>
void __dbg__(const T& value) {
    LOG << value;
}

template <typename T>
void __dbg__(const vector<T>& vec) {
    LOG << "[";
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        __dbg__(vec[i]);
        LOG << ", ";
    }
    __dbg__(vec[vec.size() - 1]);
    LOG << "]";
}
#define NL LOG << '\n'

#define TRACK LOG << __LINE__ << ": tour (" << tour.size() << ") = " << tour << endl;

////////////////////////////////////////////////////////////////////////////////

constexpr int BOARD_SIZE = 8;
constexpr int MAX_BOARD_SIZE = 9;
constexpr char START_POSITION[3] = "a1";
const bool CACHE_REACHABLE_POSITIONS = true;

////////////////////////////////////////////////////////////////////////////////

// Valid positions [1, board_size] for both rank and file
// Silently converts invalid positions to (0, 0) or "--" and bool(...) evaluates to
// "a3" means row 3 col 1, or (1, 3)
// false
class Posn {
    // rank (4 in a4). varies 1 to bsize, or 0 if invalid
    int row = 0;
    // file (a in a4). varies 1 to bsize, or 0 if invalid
    int col = 0;
    string name = "--";
    int bsize = BOARD_SIZE;
    bool isValid = true;

    // flag to enable reachable positions caching
    static bool cacheReachablePosns;

    // flag for when cache initializing is on going
    static bool initializingCache;
    // for every bsize, for every row, for every col, the list of reachable posns
    static vector<vector<vector<vector<Posn>>>> reachablePosnsCache;
    // for every bsize whether the cache is initialized
    static vector<bool> isCacheInitialized;

    // TODO: highly oversimplified string validation
    // assuming 1 <= boardsize <= 9
    static bool validateString(const string& s) {
        if (s.size() != 2) {
            throw std::invalid_argument(
                "Position must be of the form XN, where X is a lowercase alphabet and "
                "N is a single-digit numeral.");
        }
        return true;
    }

    // FILLING STATIC VARIABLES
    // fill reachable positions for given boardsize
    static void fillReachablePosnsBoard(int boardsize) {
        if (isCacheInitialized[boardsize - 1])
            return;

        for (int r = 1; r <= boardsize; r++) {
            for (int c = 1; c <= boardsize; c++) {
                fillReachablePosnsPosn(
                    r, c, boardsize, reachablePosnsCache[boardsize - 1][r - 1][c - 1]);
            }
        }

        isCacheInitialized[boardsize - 1] = true;
    }

    // fill reachable positions for given position (valid ones only)
    static void fillReachablePosnsPosn(int row, int col, int boardsize,
                                       vector<Posn>& list) {
        if (!list.empty())
            throw std::invalid_argument(
                "list of reachable positions already computed. exiting.\n");

        // hardcode for speed
        constexpr int files[8] = {2, 2, -2, -2, 1, 1, -1, 1};
        constexpr int ranks[8] = {1, -1, 1, -1, 2, -2, 2, -2};

        // check all positions
        for (int i = 0; i < 8; i++) {
            const int file = col + files[i];
            const int rank = row + ranks[i];
            // keep only valid ones
            if (file < 1 || file > boardsize || rank < 1 || rank > boardsize)
                continue;
            list.push_back({file, rank, boardsize});
        }
    }

public:
    // CONSTRUCTORS
    // default constructor `file`, `rank` and `boardsize`
    Posn(int file = 0, int rank = 0, int boardsize = BOARD_SIZE)
        : col(file), row(rank), bsize(boardsize) {
        // check for invalid input
        if (row > bsize || row < 1 || col > bsize || col < 1) {
            row = col = 0;
            isValid = false;
        }
        // for valid input
        else {
            name.resize(2);
            name[0] = (char)'a' - 1 + col;
            name[1] = (char)'0' + row;
        }
        // ensure only one time cache initializing per recursive call
        if (!initializingCache) {
            initializingCache = true;
            fillReachablePosnsBoard(boardsize);
            initializingCache = false;
        }
    }

    // initialize static variables
    static void initializeStatic(bool cache = CACHE_REACHABLE_POSITIONS) {
        cacheReachablePosns = cache;
        reachablePosnsCache.resize(MAX_BOARD_SIZE);

        for (int bsize = 1; bsize <= MAX_BOARD_SIZE; bsize++) {
            reachablePosnsCache[bsize - 1] =
                vector<vector<vector<Posn>>>(bsize, vector<vector<Posn>>(bsize));
        }
    }

    // constructor using string for position and `boardsize`
    Posn(string s, int boardsize = BOARD_SIZE)
        : Posn(validateString(s) ? s[0] - 'a' + 1 : 0, s[1] - '0', boardsize) {}

    // return vector of reachable positions for the instance
    vector<Posn> reachable() const {
        // if cache has been enabled and corressponding cache initialized, return from
        // cache
        if (cacheReachablePosns && isCacheInitialized[bsize - 1])
            return reachablePosnsCache[bsize - 1][row - 1][col - 1];

        // else compute it and return
        vector<Posn> result;
        fillReachablePosnsPosn(row, col, bsize, result);
        return result;
    }

    // required for hashing for unordered_set
    // (for our purposes, we assume board size will always be compatible)
    bool operator==(const Posn& other) const {
        return row == other.row && col == other.col;
    }

    // returns whether position is valid
    operator bool() const { return isValid; }

    friend ostream& operator<<(ostream& out, const Posn& p);
    friend class PosnHasher;
};

// define static members outside the class
bool Posn::cacheReachablePosns = CACHE_REACHABLE_POSITIONS;
bool Posn::initializingCache = false;
vector<vector<vector<vector<Posn>>>> Posn::reachablePosnsCache;
vector<bool> Posn::isCacheInitialized(MAX_BOARD_SIZE, false);

ostream& operator<<(ostream& out, const Posn& p) { return (out << p.name); }

// custom hasher class for storing visited posns in set
// https://chatgpt.com/share/67252ba9-36bc-800d-9d4a-75de30df8e91
class PosnHasher {
public:
    size_t operator()(const Posn& p) const {
        return std::hash<int>{}(p.row) ^ (std::hash<int>{}(p.col) * 31);
    }
};

// Class for storing variables related to tour and implementing basic methods
class Tour {
    vector<Posn> t_stack;
    unordered_set<Posn, PosnHasher> t_set;
    bool done;
    int maxlength;
    int bsize;

public:
    // DEFAULT CONSTRUCTOR
    Tour(int tour_length, int board_size)
        : t_stack({}),
          t_set({}),
          maxlength(tour_length),
          bsize(board_size),
          done(false) {}

    // return const lref to last element in tour
    const Posn& tail() const { return t_stack.back(); }

    // return length of tour traversed currently
    int size() const { return t_stack.size(); }

    // return all positions reachable from tail position (including visited ones)
    vector<Posn> reachable() const { return tail().reachable(); }

    // return whether a position has been visited in current tour
    bool isVisited(const Posn& p) const { return t_set.find(p) != t_set.end(); }

    // remove last visited position
    void pop() {
        Posn p = tail();
        t_stack.pop_back();
        t_set.erase(p);
    }

    // add a position to the tour
    // CAUTION: assumes `p` is not in tour
    void add(const Posn& p) {
        t_stack.push_back(p);
        t_set.insert(p);

        // check if desired tour length has been achieved
        if (size() == maxlength)
            done = true;
    }

    // return whether tour is empty
    bool empty() const { return t_stack.empty(); }

    // return whether desired tour length has been achieved
    operator bool() const { return done; }

    friend ostream& operator<<(ostream& out, const Tour& t);
};

ostream& operator<<(ostream& out, const Tour& t) {
    for (const Posn& c : t.t_stack) {
        out << c << " ";
    }
    return out;
}

// perform recursive DFS on tour using backtracking
void DFS(Tour& tour) {
    for (const Posn& p : tour.reachable()) {
        // base case
        if (tour)
            return;

        // reduce
        if (tour.isVisited(p))
            continue;
        tour.add(p);
        TRACK;

        // recurse
        DFS(tour);
    }

    // backtrack
    if (!tour) {
        tour.pop();
        TRACK;
    }
}

// find the tour of `length` with `board_size` from `startposn`
Tour find_tour(int length, int board_size, string startposn) {
    Tour tour(length, board_size);

    tour.add(startposn);

    DFS(tour);

    return tour;
}

int main(int argc, char** argv) {
    // take command line arguments
    int M = 25, N = BOARD_SIZE;
    bool cacheReachablePosns = CACHE_REACHABLE_POSITIONS;
    string startposn = START_POSITION;

    if (argc > 5) {
        std::cerr << "Usage: " << argv[0] << " [tour-length = " << M
                  << "] [board-size = " << N << "] [start-position = " << startposn
                  << "] [cache-reachable-posns = "
                  << (CACHE_REACHABLE_POSITIONS ? "1" : "0") << "]" << std::endl;
        exit(1);
    }
    if (argc >= 2)
        M = std::stoi(argv[1]);
    if (argc >= 3)
        N = std::stoi(argv[2]);
    if (argc >= 4) {
        startposn[0] = argv[3][0];
        startposn[1] = argv[3][1];
    }
    if (argc == 5) {
        cacheReachablePosns = std::stoi(argv[4]);
    }

    // initialize static variables
    Posn::initializeStatic(cacheReachablePosns);

    // find tour
    Tour tour = find_tour(M, N * N, startposn);

    // print tour
    if (!tour) {
        cerr << "Tour not found!\n";
        return 1;
    }

    cout << tour << endl;

    return 0;
}
