#include "tetris-blocks.h"
#include <simplecpp>


class playerInput {

	const KeySym DOWNKEY = XK_d, LEFTKEY = XK_Left, RIGHTKEY = XK_Right,  ROTCWKEY = XK_Up, ROTACWKEY = XK_Down, DROPKEY = XK_space;


	bool validKey(XKeyEvent& ev) {
		auto k = XLookupKeysym(&ev,0);
		return (k==DOWNKEY || k==LEFTKEY || k==RIGHTKEY || k== ROTCWKEY || k==ROTACWKEY || k==DROPKEY);
	}

	move_t moveFromKey(XKeyEvent& ev) {
		auto k = XLookupKeysym(&ev,0);
		if(k==LEFTKEY) return lft;
		if(k==RIGHTKEY) return rgt;
		if(k==ROTCWKEY) return rotCW;
		if(k==ROTACWKEY) return rotACW;
		if(k==DROPKEY) return drp;
		return dwn;
	}

public:
	void flushMoves() {
		XEvent ev;
		while(checkEvent(ev)) {}
	}
	move_t nextMove() {
		XEvent ev;
		// look for next valid key available
		while (checkEvent(ev) ) {
			if(keyPressEvent(ev) && validKey(ev.xkey)) {
				return moveFromKey(ev.xkey);
			}
		}
		return none;
	}
};

