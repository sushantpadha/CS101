#include <iostream>
#include <vector>
#include <unordered_set>
#include <exception>
using std::vector;
using std::unordered_set;
using std::ostream;

#ifdef DEBUG
#define LOG std::cerr
#else
#define LOG if(0) std::cerr
#endif

// templated on a coordinates class C
// C should have a public function std::vector<C> reachable()
template<class C>
class state {
	C here; // coordinates of this location
	vector<C> whereto; // those remaining to be explored
public:
	state(const C& coords)
		: here(coords), whereto (here.reachable()) {}
	bool stuck() const { return whereto.empty(); }
	C where() const { return here; }
	C next() { C x = whereto.back(); whereto.pop_back(); return x;} // where to go next; remove it from the vector
	friend ostream& operator<< (ostream& out,const state& ex) {
		out << "At: " << ex.here << ". To : [ ";
		for(auto c: ex.whereto) out << c << " ";
		return out << "]" << std::endl;
	}
};

template<class C, class H>
class explorer {
	vector<state<C>> path;  // current path
	unordered_set<C,H> visited;
public:
	explorer(C start) {
		path.push_back({start});  // or, path.push_back(state<C>(start));
		visited.insert(start);
	}

	int path_len() const { return path.size(); }
	operator bool() const { return !path.empty(); }
	bool stuck() const { return path.back().stuck(); }
	void backtrack() { visited.erase(path.back().where()); path.pop_back(); }
	void proceed() {
		C nxt = path.back().next(); // this removes the next destination 
		if(visited.count(nxt)) // check if nxt has already been visited
			return;            // then we are done exploring it
		path.push_back({nxt}); // else create an state for nxt and add it to the path
		visited.insert(nxt);
	}
	vector<C> get_path() const { 
		vector<C> Cpath;
		for(auto& st : path) Cpath.push_back(st.where());
		return Cpath;
	}
	friend ostream& operator<< (ostream& out,const explorer& dora) {
		out << "Length: " << dora.path.size() << "\nState " <<  dora.path.back() << std::endl;
		return out;
	}
};

// try to find a tour of at most n steps, starting from start
// if not found return empty vector
template<class C, class H>
vector<C> find_tour(C start, int n) {
	explorer<C,H> dora(start);
	while(dora && dora.path_len() < n) {
		LOG << "Current path: " << dora << std::endl;
		if(dora.stuck()) {
			LOG << "Nowhere to go. Backtracking." << std::endl;
			dora.backtrack();
		} else
			dora.proceed();
	}
	return dora.get_path();
}


class knight_coords {
	char row, col; // just a byte each
	const int boardsz;
public:
	knight_coords(char r, char c, int sz) : row(r), col(c), boardsz(sz) {
		if(r<0 || r>=boardsz || c <0 || c>=boardsz)
			throw std::domain_error("Invalid coordinate");
	}
	vector<knight_coords> reachable();
	bool operator==(const knight_coords& other) const { return row==other.row && col==other.col; }
	friend ostream& operator<< (ostream& out,const knight_coords& kc) {
		return out << char(kc.col+'a') << kc.row+1;
	}
	friend class hasher;
};

class hasher {
	public:
		std::size_t operator() (const knight_coords& kc) const {
			//return std::hash<int>()( (kc.row << 8) | kc.col );
			return ( (kc.row << 8) | kc.col );
		}
};

vector<knight_coords> knight_coords::reachable() {
	vector<knight_coords> v;
	for(int i: {-1,1}) { // iterate over -1, +1
		for(int j: {-2,2}) { // iterate over -2, +2
			int r = row+i, c = col+j;
			if(r>=0 && r<boardsz && c>=0 && c<boardsz)
				v.push_back(knight_coords(r,c,boardsz));
			r = row+j; c = col+i;
			if(r>=0 && r<boardsz && c>=0 && c<boardsz)
				v.push_back(knight_coords(r,c,boardsz));
		}
	}
	return v;
}



int main(int argc, char** argv) {
	int N = 5, starti=0, startj=0;
	if(argc>3) {
		std::cerr << "Usage: " << argv[0] << " [board-size] [start-position]" << std::endl;
		exit(1);
	}
	if(argc>=2)
		N = std::stoi(argv[1]);
	if(argc==3) {
		startj = argv[2][0]-'a';
		starti = argv[2][1]-'1';
	}

	knight_coords start(starti,startj,N);
	auto tour = find_tour<knight_coords,hasher>(start,N*N);
	if(tour.empty())
		std::cerr << "No tour found!" << std::endl;
	else {
		for(auto& c : tour) 
			std::cout << c << " ";
		std::cout << std::endl;
	}
}



