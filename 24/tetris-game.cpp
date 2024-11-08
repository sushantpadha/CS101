#include <iostream>
#include "tetris-game.h"


int game::play() {
	double sub_unit_time = unit_time/nPolls;
	int score=0;
	block falling;
	vector<point> up;

	while(Tet.newBlock(nextBlock(),falling)) {
		drawer.updateBlock(falling);
		input.flushMoves();
		bool can_move = true;
		for(int i=0; can_move; (++i) %= (nPolls+1)) {
			wait(sub_unit_time);
			move_t mv = (i==nPolls) ? dwn : input.nextMove(); // after nPoll attempts, move down
			if(mv==none) continue;
			can_move = Tet.move(falling,mv,up);
			drawer.update(up);
		}
		// after landing, check for row collapse
		auto xrows = Tet.collapse();
		int nxrows = xrows.size();
		if(nxrows) {
			score += 100*nxrows*nxrows;
			wait(blink_time); // TODO: replace with a blink animation
			drawer.refresh();
			sub_unit_time = unit_time/(nPolls*(1 + speedup*score));
		}
	}
	return score;
}
