#include "tetris-blocks.h"
#include <cassert>

std::string block_name(block_t blk) {
    const std::string names[8] = { "empty", "I", "O", "L", "J", "T", "S", "Z" };
    return names[blk];
}

std::string move_name(move_t mv) {
    const std::string names[6] = { "Down", "CW-rotate", "ACW-rotate", "Left", "Right", "Drop" };
    return names[mv];
}

tetromino block::pattern(block_t b, direction d) {
    if(b==L) {
        if (d==0)
            return tetromino {{ {0,1}, {1,1}, {2,1}, {2,2} }}; 
        if (d==1)
            return tetromino {{ {1,0}, {1,1}, {1,2}, {2,0} }}; 
        if (d==2)             
            return tetromino {{ {0,0}, {0,1}, {1,1}, {2,1} }}; 
        //if (d==3)
        return tetromino {{ {0,2}, {1,0}, {1,1}, {1,2} }}; 
    }
    if(b==J) {
        if (d==0)
            return tetromino {{ {0,1}, {0,2}, {1,1}, {2,1} }}; 
        if (d==1)
            return tetromino {{ {1,0}, {1,1}, {1,2}, {2,2} }}; 
        if (d==2)
            return tetromino {{ {0,1}, {1,1}, {2,0}, {2,1} }}; 
        //if (d==3)
        return tetromino {{ {0,0}, {1,0}, {1,1}, {1,2} }}; 
    }
    if(b==S) {
        if (d==0)
            return tetromino {{ {0,1}, {1,1}, {1,2}, {2,2} }}; 
        if (d==1)
            return tetromino {{ {1,1}, {1,2}, {2,0}, {2,1} }}; 
        if (d==2)
            return tetromino {{ {0,0}, {1,0}, {1,1}, {2,1} }}; 
        //if (d==3)
        return tetromino {{  {0,1}, {0,2}, {1,0}, {1,1} }}; 
    }
    if(b==Z) {
        if (d==0)
            return tetromino {{ {0,2}, {1,1}, {1,2}, {2,1} }}; 
        if (d==1)
            return tetromino {{ {1,0}, {1,1}, {2,1}, {2,2} }}; 
        if (d==2)
            return tetromino {{ {0,1}, {1,0}, {1,1}, {2,0} }}; 
        //if (d==3)
        return tetromino {{ {0,0}, {0,1}, {1,1}, {1,2} }}; 
    }
    if(b==T) {
        if (d==0)
            return tetromino {{ {0,1}, {1,1}, {1,2}, {2,1} }}; 
        if (d==1)
            return tetromino {{ {1,0}, {1,1}, {1,2}, {2,1} }}; 
        if (d==2)
            return tetromino {{ {0,1}, {1,0}, {1,1}, {2,1} }}; 
        //if (d==3)
        return tetromino {{ {0,1}, {1,0}, {1,1}, {1,2} }}; 
    }
    if(b==I) {
        if (d==0)
            return tetromino {{ {0,2}, {1,2}, {2,2}, {3,2} }}; 
        if (d==1)
            return tetromino {{ {2,0}, {2,1}, {2,2}, {2,3} }}; 
        if (d==2)
            return tetromino {{ {0,1}, {1,1}, {2,1}, {3,1} }}; 
        //if (d==3)
        return tetromino {{ {1,0}, {1,1}, {1,2}, {1,3} }}; 
    }
    if(b==O) {
        return tetromino {{ {0,0}, {1,0}, {0,1}, {1,1} }}; 
    }
    throw std::invalid_argument("Invalid block");
}

// for each block type, for each move, room needed to make the move mv
// This may include the room currently occupied as well
vector<point> block::relFullRoom(block_t b, direction d, move_t mv) {
    assert(mv!=drp);
    if(mv==dwn || mv==rgt || mv==lft) {
        vector<point> v(pattern(b,d)); // tetromino allows casting to a vector of points
        point delta(mv); // translate the move into the corresponding shift
        for (auto& p: v) p += delta;
        return v;
    }
    // else a rotation
    if(b==O)
        return { {0,0}, {0,1}, {1,0}, {1,1}};

    if(b==I) {
        if ((d==0 && mv==rotCW) || (d==1 && mv==rotACW))
            return  {  {0,3},  {1,3},  {2,3},/*{3,3},*/
                       {0,2},  {1,2},  {2,2},  {3,2},
                     /*{0,1},  {1,1},*/{2,1},  {3,1},
                     /*{0,0},  {1,0},*/{2,0},  {3,0}   };
        if ((d==1 && mv==rotCW) || (d==2 && mv==rotACW))
            return  {/*{0,3},  {1,3},*/{2,3},  {3,3},   
                     /*{0,2},  {1,2},*/{2,2},  {3,2},
                       {0,1},  {1,1},  {2,1},  {3,1},
                       {0,0},  {1,0},  {2,0},/*{3,0}*/ };
        if ((d==2 && mv==rotCW) || (d==3 && mv==rotACW))
            return  {  {0,3},  {1,3},/*{2,3},  {3,3},*/
                       {0,2},  {1,2},/*{2,2},  {3,2},*/
                       {0,1},  {1,1},  {2,1},  {3,1},
                     /*{0,0},*/{1,0},  {2,0},  {3,0}   };
        //(d==3 && mv==rotCW) || (d==0 && mv==rotACW)
        return  {/*{0,3},*/{1,3},  {2,3},  {3,3},   
                   {0,2},  {1,2},  {2,2},  {3,2},
                   {0,1},  {1,1},/*{2,1},  {3,1},*/
                   {0,0},  {1,0},/*{2,0},  {3,0}*/ };
    }
    if(b==L || b==J || b==T) {
        if ((d==0 && mv==rotCW) || (d==1 && mv==rotACW))
            return  {  {0,2},  {1,2},  {2,2},
                       {0,1},  {1,1},  {2,1},
                     /*{0,0},*/{1,0},  {2,0}   };
        if ((d==1 && mv==rotCW) || (d==2 && mv==rotACW))
            return  {/*{0,2},*/{1,2},  {2,2},
                       {0,1},  {1,1},  {2,1},
                       {0,0},  {1,0},  {2,0}   };
        if ((d==2 && mv==rotCW) || (d==3 && mv==rotACW))
            return  {  {0,2},  {1,2},/*{2,2},*/
                       {0,1},  {1,1},  {2,1},
                       {0,0},  {1,0},  {2,0}   };
        //(d==3 && mv==rotCW) || (d==0 && mv==rotACW)
        return  {  {0,2},  {1,2},  {2,2},
                   {0,1},  {1,1},  {2,1},
                   {0,0},  {1,0},/*{2,0}*/ };
    }

    if(b==S) {
        if ((d==0 && mv==rotCW) || (d==1 && mv==rotACW))
            return  {  {0,2},  {1,2},  {2,2},
                       {0,1},  {1,1},  {2,1},
                     /*{0,0},  {1,0},*/{2,0}   };
        if ((d==1 && mv==rotCW) || (d==2 && mv==rotACW))
            return  {/*{0,2},*/{1,2},  {2,2},
                     /*{0,1},*/{1,1},  {2,1},
                       {0,0},  {1,0},  {2,0}   };
        if ((d==2 && mv==rotCW) || (d==3 && mv==rotACW))
            return  {  {0,2},/*{1,2},  {2,2},*/
                       {0,1},  {1,1},  {2,1},
                       {0,0},  {1,0},  {2,0}   };
        //(d==3 && mv==rotCW) || (d==0 && mv==rotACW)
        return  {  {0,2},  {1,2},  {2,2},
                   {0,1},  {1,1},/*{2,1},*/
                   {0,0},  {1,0},/*{2,0}*/ };
    }

    if(b==Z) {
        if ((d==0 && mv==rotCW) || (d==1 && mv==rotACW))
            return  {  {0,2},  {1,2},  {2,2},
                     /*{0,1},*/{1,1},  {2,1},
                     /*{0,0},*/{1,0},  {2,0}   };
        if ((d==1 && mv==rotCW) || (d==2 && mv==rotACW))
            return  {/*{0,2},  {1,2},*/{2,2},
                       {0,1},  {1,1},  {2,1},
                       {0,0},  {1,0},  {2,0}   };
        if ((d==2 && mv==rotCW) || (d==3 && mv==rotACW))
            return  {  {0,2},  {1,2},/*{2,2},*/
                       {0,1},  {1,1},/*{2,1},*/
                       {0,0},  {1,0},  {2,0}   };
        //(d==3 && mv==rotCW) || (d==0 && mv==rotACW)
        return  {  {0,2},  {1,2},  {2,2},
                   {0,1},  {1,1},  {2,1},  
                   {0,0},/*{1,0},  {2,0}*/ };
    }
    throw std::invalid_argument("Invalid block");
}

// remove the points occupied by the block from the room
vector<point> block::relRoom(block_t b, direction d, move_t mv) {
    auto room = relFullRoom(b,d,mv);
    auto self = pattern(b,d);
    for(int i=0; i<4; i++) { // there are 4 points in a tetromino
        point p(self.pts[i][0],self.pts[i][1]);
        auto it = std::find(room.begin(),room.end(),p);
        if(it!=room.end())
            room.erase(it);
    }
    return room;
}

void block::move(move_t mv) {
    origin += point(mv);
    if(mv==rotCW) ++dir;
    if(mv==rotACW) --dir;
    occupied = origin+pattern(blk,dir); // shift pattern by origin
}

