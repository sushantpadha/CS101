#ifndef __TETRIS_BLOCKS__
#define __TETRIS_BLOCKS__

#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
using std::vector;

enum block_t {nil, I, O, L, J, T, S, Z };
enum move_t {none, drp, dwn, rotCW, rotACW, lft, rgt};
const int nBlocks = 7; // not counting nil 
// Testing aid
// const int nMoves = 5; // not counting none and drp
std::string block_name(block_t);
std::string move_name(move_t);

class point; // forward declaration

// a tetromino has 4 squares
struct tetromino {
    signed char pts[4][2];  // the position of the 4 squares
    operator vector<point> () const; // to cast into a vector of 4 points
};


class point {
    signed char x, y;
public:
    point& operator+=(const point& p) { x += p.x; y += p.y; return *this; }
    point(signed char a=0, signed char b=0) : x(a), y(b) {}
    point(move_t mv) {
        if(mv == drp)
            throw std::invalid_argument("Invalid move");
        mv==dwn ? (x=0,y=-1) : mv==rgt? (x=1,y=0) : mv== lft? (x=-1,y=0) : (x=0,y=0);
    }
    // point + tetromino gives tetromino
    tetromino operator+(const tetromino& t) const {
        tetromino newt;
        for(int i: {0,1,2,3} ) {
                newt.pts[i][0] = t.pts[i][0] + x;
                newt.pts[i][1] = t.pts[i][1] + y;
        }
        return newt;
    }
    bool operator==(const point& pt) const { return x==pt.x && y==pt.y; }
    int X() const { return x; }
    int Y() const { return y; }
};

inline tetromino::operator vector<point> () const {
    return vector<point> ({ {pts[0][0], pts[0][1]}, {pts[1][0], pts[1][1]}, {pts[2][0], pts[2][1]}, {pts[3][0], pts[3][1]} });
}

class direction {
    char d=0; // direction is 0,1,2,3
public:
    direction& operator++() { (++d) %= 4; return *this;}
    direction& operator--() { (d+=3) %= 4; return *this;}
    bool operator==(const int& i) { return d==i;}
};

class block {
    static tetromino pattern(block_t,direction); // a static function to compute the pattern occupied
    static vector<point> relRoom(block_t, direction d, move_t); // empty cells needed to make a move
    static vector<point> relFullRoom(block_t, direction d, move_t); // empty cells needed to make a move, plus own cells
    block_t blk;
    point origin;       // position of left-bottom corner of block's grid, in the board (can be negative)
    direction dir;      // orientation of the block within its grid
    tetromino occupied; // cells occupied, relative to left bottom corner
public:
    block() = default;  // uninitialized block (useful when passing by reference to be populated)
    block(block_t b, point o) : blk(b), origin(o), occupied(origin+pattern(blk,dir)) {}
    block& operator= (const block& B) { blk=B.blk; origin=B.origin; dir=B.dir; occupied=B.occupied; return *this;}
    block_t blocktype() const { return blk; }
    tetromino where() const { return occupied; }
    vector<point> room(move_t mv) { // list of squares needed to make a move
        auto v = relRoom(blk,dir,mv);
        for(auto& p: v) p += origin;
        return v;
    }
    void move(move_t mv); // carry out a move (to be used after checking the board for room)
    static int size(block_t b) {
        if(b==nil) throw std::invalid_argument("Invalid block");
        return b==O ? 2 : I ? 4 : 3; 
    }
};

#endif // __TETRIS_BLOCKS__
