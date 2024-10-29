#include "geo.h"

std::string geo::P::to_string() {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")"; 
}


void geo::move(geo::P& p, const geo::P& delta) {
    p.x += delta.x; p.y += delta.y;
}

