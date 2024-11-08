#ifndef __TETRIS_BOARD__
#define __TETRIS_BOARD__

#include "tetris-blocks.h"
using std::vector;

class updateList {
    vector<point> Lpt;
    vector<block_t> Lblk;
public:
    void clear() { Lpt.clear(); Lblk.clear(); }
    size_t size() { return Lpt.size(); }
    int X(int i) { return Lpt[i].X(); }
    int Y(int i) { return Lpt[i].Y(); }
    block_t blk(int i) { return Lblk[i]; }
    // add updates corresponding to moving a block from start to finish
    void move(const tetromino& start, const tetromino& finish, block_t blk);
	// after extracting points, the list gets reset
	void extractPoints(vector<point>& up) { up = std::move(Lpt); clear(); }
};


class board {
    int cols, rows;
    vector<vector<block_t>> blocks ; // for each cell, the block type. blocks[y][x] for y-th row, x-th col
    bool check(const vector<point>& v) { // check if all points are empty
        for(const auto& p: v) {
            int x = p.X(), y = p.Y();
            if(x<0 || x>= cols || y < 0 || y >= rows || blocks[y][x] != nil ) 
                return false;
        }
        return true;
    }
    bool tryMove(block& B, move_t mv) { // try to make a move on the board, and update the block
        bool can_move = check(B.room(mv));
        if(can_move) B.move(mv);
        return can_move;
    }
    bool drop(block& B) { 
        bool moved = false;
        while(tryMove(B,dwn)) { moved=true;}
        return moved;
    }  // make the block move down as much as possible

    void applyUpdate(updateList& up) {
        for (int i=0; i<up.size(); i++)
            blocks[up.Y(i)][up.X(i)] = up.blk(i);
    }

public:
    board(int c, int r) : cols(c), rows(r), blocks(rows,vector<block_t>(cols,nil)) {}
    int ncols() const {return cols;}
    int nrows() const {return rows;}

    block_t at(int x, int y) const {
        return (blocks.at(y)).at(x);
    }

    // return whether succeeded in creating a new block or not
    bool newBlock(block_t b, block& B);
    // returns false to indicate that the piece has landed
    bool move(block& B, move_t mv, vector<point>& updates);
	// collapse all full rows, and return their original indices
    vector<int> collapse();
};

#endif // __TETRIS_BOARD__
