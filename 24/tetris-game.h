#include "tetris-board.h"
#include "tetris-anim.h"
#include "tetris-input.h"
#include "dice.h"

class game {

    // configuration parameters
    const int nPolls = 15;  // maxium number of inputs within one unit_time
    const double unit_time = 1,  blink_time = 0.5; 
    const double speedup = 0.0005; //sub_unit_time reduces to (unit_time/nPolls)/(1+speedup*score)
                                   //
    board Tet;
    boardDrawer drawer;
    playerInput input;

public:
    game(int wd=10, int ht=22, int hid=2) : Tet(wd,ht), drawer(500, hid, &Tet) {}

    block_t nextBlock() {
        static dice<short> D(1,nBlocks);
        return static_cast<block_t>(int(D.roll()));
    }

    int play();
};
