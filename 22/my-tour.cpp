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

#define __DBG_ENABLED 0

#define LOG            \
    if (__DBG_ENABLED) \
    cerr

#define DBG(x)         \
    if (__DBG_ENABLED) \
    cout << #x << "=" << x << " "
#define nl             \
    if (__DBG_ENABLED) \
    cout << '\n'

#define TRACK LOG << __LINE__ << ": tour (" << tour.size() << ") = " << tour << endl;

constexpr int BOARD_SIZE = 8;

// Valid positions [1, board_size] for both rank and file
// Silently converts invalid positions to (0, 0) or "--" and bool(...) evaluates to
// "a3" means row 3 col 1, or (1, 3)
// false
class Posn {
    // rank (4 in a4). varies 1 to bsize, or 0 if invalid
    int row;
    // file (a in a4). varies 1 to bsize, or 0 if invalid
    int col;
    string name;
    int bsize;
    bool isValid;

public:
    Posn(int file = 0, int rank = 0, int boardsize = BOARD_SIZE)
        : col(file), row(rank), bsize(boardsize), isValid(true), name("--") {
        // check for invalid input
        if (row > bsize || row < 1 || col > bsize || col < 1) {
            row = col = 0;
            isValid = false;
        } else {
            name.resize(2);  // Ensure the size is 2 before modifying characters
            name[0] = (char)'a' - 1 + col;
            name[1] = (char)'0' + row;
        }
    }

    Posn(string s, int boardsize = BOARD_SIZE)
        : Posn(validateString(s) ? s[0] - 'a' + 1 : 0, s[1] - '0', boardsize) {}

    // assuming 1 <= boardsize <= 9
    static bool validateString(const string& s) {
        if (s.size() != 2) {
            throw std::invalid_argument(
                "Position must be of the form XN, where X is a lowercase alphabet and "
                "N is a single-digit numeral.");
        }
        return true;
    }

    // return vector of valid, reachable positions
    vector<Posn> reachable() {
        vector<Posn> result;

        // generate all possible positions using 3 nested for loops
        for (int i = 1; i <= 2; i++) {
            for (int i_sgn = -1; i_sgn <= 1; i_sgn += 2) {
                for (int j_sgn = -1; j_sgn <= 1; j_sgn += 2) {
                    Posn p(col + i * i_sgn, row + (3 - i) * j_sgn);
                    // keep only valid ones
                    if (p)
                        result.push_back(p);
                }
            }
        }

        return result;
    }

    // for our purposes, we assume board size will always be compatible
    bool operator==(const Posn& other) const {
        return row == other.row && col == other.col;
    }

    const string& getName() const { return name; }
    const int& getRow() const { return row; }
    const int& getCol() const { return col; }

    operator bool() const { return isValid; }

    friend ostream& operator<<(ostream& out, const Posn& p);
};

ostream& operator<<(ostream& out, const Posn& p) { return (out << p.getName()); }

// https://chatgpt.com/share/67252ba9-36bc-800d-9d4a-75de30df8e91
struct PosnHasher {
    size_t operator()(const Posn& p) const {
        return std::hash<int>{}(p.getRow()) ^ (std::hash<int>{}(p.getCol()) * 31);
    }
};

class Tour {
    vector<Posn> t_stack;
    unordered_set<Posn, PosnHasher> t_set;
    bool done;
    int length;

public:
    Tour() : t_stack({}), t_set({}), length(0), done(false) {}

    Tour(int tour_length, int board_size, string startposn)
        : t_stack({startposn}), t_set({startposn}), length(tour_length), done(false) {}

    Posn& tail() { return t_stack.back(); }

    int size() { return t_stack.size(); }

    // return all positions reachable from tail position, not in visited
    vector<Posn> reachable() {
        vector<Posn> r = tail().reachable();
        vector<Posn> result;
        for (const Posn& pos : r) {
            if (!isVisited(pos)) {
                result.push_back(pos);
            }
        }

        // LOG << tail() << " reachable -> ";
        // for (auto p : result) LOG << p << " ";
        // LOG << endl;

        return result;
    }

    bool isVisited(const Posn& p) const { return t_set.find(p) != t_set.end(); }

    // remove last visited posn
    void pop() {
        Posn p = tail();
        t_stack.pop_back();
        t_set.erase(p);
    }

    // CAUTION: assumes `p` is not in tour
    void add(const Posn& p) {
        t_stack.push_back(p);
        t_set.insert(p);

        // check if desired tour length has been achieved
        if (size() == length)
            done = true;
    }

    bool empty() const { return t_stack.empty(); }

    operator bool() { return done; }

    const vector<Posn>& getTour() const { return t_stack; }

    friend ostream& operator<<(ostream& out, const Tour& t);
};

ostream& operator<<(ostream& out, const Tour& t) {
    for (const Posn& c : t.getTour()) {
        out << c << " ";
    }
    return out;
}

void DFS(Tour& tour) {
    for (const Posn& p : tour.reachable()) {
        // base case
        if (tour)
            return;
        // reduce
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

Tour find_tour(int length, int board_size, string startposn) {
    Tour tour(length, board_size, startposn);

    DFS(tour);

    return tour;
}

int main(int argc, char** argv) {
    // take command line arguments
    int M = 25, N = BOARD_SIZE;
    string startposn = "a1";
    if (argc > 4) {
        std::cerr << "Usage: " << argv[0] << " [tour-length = " << M
                  << "] [board-size = " << N << "] [start-position = " << startposn
                  << "]" << std::endl;
        exit(1);
    }
    if (argc >= 2)
        M = std::stoi(argv[1]);
    if (argc >= 3)
        N = std::stoi(argv[2]);
    if (argc == 4) {
        startposn[0] = argv[3][0];
        startposn[1] = argv[3][1];
    }

    // find tour
    Tour tour = find_tour(M, N * N, startposn);

    if (!tour) {
        cerr << "Tour not found!\n";
        return 1;
    }

    cout << tour << endl;
    return 0;
}
