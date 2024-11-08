#include "tetris-board.h"

// add updates corresponding to moving a block from start to finish
void updateList::move(const tetromino& start, const tetromino& finish, block_t blk) {
	vector<point> vstart, vfinish;
	vstart = vector<point>(start);
	vfinish = vector<point>(finish);
	for (auto& p : vstart) {
		Lpt.push_back(p); // change each point in starting position to nil
		Lblk.push_back(nil);
	}
	for (auto& p : vfinish) {  // add each point in finish position
		bool erased = false;   
		for (int i=0; i < size(); i++)     // check if this position was set to nil above
			if(Lpt[i] == p) {  Lpt.erase(Lpt.begin()+i); Lblk.erase(Lblk.begin()+i); erased=true; break; } // if so just remove that update
		if(!erased) {  // else add an update to set this point to blk
			Lpt.push_back(p); // change each point in starting position to nil
			Lblk.push_back(blk);
		}
	}
}    

bool board::newBlock(block_t b, block& B) { 
	B = block(b,point((cols-block::size(b))/2,rows-block::size(b))); 
	auto v = vector<point>(B.where());
	if(!check(v)) return false;
	// add block to the board
	for(auto& p: v)
		blocks[p.Y()][p.X()] = b;
	return true;
}

// returns false to indicate that the piece has landed
bool board::move(block& B, move_t mv, vector<point>& updates) {
	tetromino start = B.where();
	bool moved = (mv==drp ? drop(B) : tryMove(B,mv) );
	if(moved) {
		updateList up;
		tetromino finish = B.where();
		up.move(start,finish,B.blocktype());
		applyUpdate(up); // update board's state also using up
		up.extractPoints(updates);  // up is not used again
	}
	bool landed = (mv==drp) || (mv==dwn && !moved);
	return !landed;
}

vector<int> board::collapse() {
	vector<int> rowlist; // rows to remove, bottom-most at the back
	for(int y=rows-1; y>=0; --y) {
		bool full = true;
		for(int x=0; x<cols; x++) {
			if(blocks[y][x] == nil) {
				full = false;
				break;
			}
		}
		if(full)
			rowlist.push_back(y);
	}
	if(!rowlist.empty()) {
		// push the other rows down
		int newr = 0;
		for(int oldr=0, listr = rowlist.size()-1; oldr < rows; ++oldr) {
			if(listr >=0 && oldr==rowlist[listr]) { // do not copy to newr
				--listr;
				continue; 
			}
			if(oldr==newr) {  // no need to copy, just advance newr
				++newr; continue; 
			}
			// copy oldr to newr, and advance newr
			blocks[newr] = blocks[oldr];
			newr++;
		}
		// now fill remaining rows with empty cells
		for(; newr < rows; ++newr)
			blocks[newr] = vector<block_t>(cols,nil);
	}

	return rowlist;
}


