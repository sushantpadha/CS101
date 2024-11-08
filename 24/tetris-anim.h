#include <simplecpp>
#include "tetris-board.h"

class boardDrawer {

    const board* Brd; // will only use nrows(), ncols() and at() 
    int nrows, ncols;
    double boxsz, height, width;
    vector<vector<Rectangle*>> boxes; // for each cell, the coloured box

    Rectangle* mkBox(int row, int col) {
        return new Rectangle((col+0.5)*boxsz,height-(row+0.5)*boxsz,boxsz,boxsz);
    }

    Color getColor(int x, int y) {
        static const char* colours[] = { "black", "cyan", "white", "yellow", "blue", "magenta", "green", "red"};
        return COLOR(colours[Brd->at(x,y)]);
    }

public:
    boardDrawer (double h, int nhide, const board* B)
                : Brd(B), nrows(Brd->nrows() - nhide), ncols(Brd->ncols()),
                  boxsz(h/nrows), height(h), width(boxsz*ncols),
                  boxes(nrows,vector<Rectangle*>(ncols,nullptr)) {
        initCanvas("Tetris",width,height);
        for(int y=0; y<boxes.size(); y++) {
            for(int x=0; x<boxes[y].size(); x++) {
                boxes[y][x] = mkBox(y,x);
                boxes[y][x]->setColor(getColor(x,y));
                boxes[y][x]->setFill();
            }
        }
    }

    void refresh() {
        for(int y=0; y<boxes.size(); y++) {
            for(int x=0; x<boxes[y].size(); x++) {
                boxes[y][x]->setColor(getColor(x,y));
            }
        }
    }

    void update(const vector<point>& L) {
        for(auto& p: L) {
            int x = p.X(), y = p.Y();
            if(y>=nrows) continue;
            boxes[y][x]->setColor(getColor(x,y));
        }
    }

    void updateBlock(const block& piece) {
        update(vector<point>(piece.where()));
    }
};
