#ifndef _GEO_H
#define _GEO_H
#include <string>
namespace geo {

struct P { // geo::P
    int x,y; 
    std::string to_string();
};

void move(P&,const P&); // this is geo::move
              // in here geo::P can be referred
              // to as simply P 

}
#endif

