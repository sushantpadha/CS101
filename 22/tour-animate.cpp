#include <simplecpp>

/**** Implementing the Knight's image ***/

class Knight : public Polygon {  // this uses inhertiance: defining the class Knight as derived from the class Polygon
	static constexpr double vertices[14][2] = { {-5,-25}, {10,-15}, {10,-5}, {5,0}, {15,5}, {15,15}, {-15,15}, {-15,5}, {-5,0}, {-8,-2}, {-2,-12}, {-12,-8}, {-16,-12}, {-5,-20}};
public:
	Knight(double x, double y) : Polygon(x,y,vertices,14) {
		this->setColor(COLOR("brown"));
		this->setFill();
	}
};

constexpr double Knight::vertices[14][2]; // this needs to be declared like a global variable, for space to be allocated for it.

/**** End: Implementing the Knight's image ***/

enum piece { none, mark, knight };

class square {
	piece P = none;
	double x, y;
	Sprite* img = nullptr;
	void draw() {
		if(img) { delete img; img = nullptr; }
		if(P==mark) img = new Text(x,y,"o");
		else if (P==knight) img = new Knight(x,y);

	}
public:
	void init(double x1, double y1, double sqr_side, bool light) { 
		x=x1; y=y1; P=none; 
		auto clr = light? COLOR("white"): COLOR("orange") ;
		auto r = Rectangle(x,y,sqr_side,sqr_side);
		r.setFill(true);
		r.setColor(clr);
		r.imprint();
	}
	void setpiece(piece p) {  P = p; draw(); }
};

class board {
	int n = 8;
	double side, sqr_side, margin=10;
	int currx=-1, curry=-1;
	vector<vector<square>> P;
	Line* edge;
	double X(int x) { return margin+(x+0.5)*sqr_side; }
	double Y(int y) { return side+margin-(y+0.5)*sqr_side; }
public:
	board(int num, double s) : n(num), side(s), sqr_side(side/n) {
		initCanvas("Chess Tour", side+2*margin, side+2*margin);
		edge = new Line(0,0,0,0);
		edge->setColor(COLOR("brown"));
		P.resize(n);
		for(int i=0; i<n; i++) {
			P[i].resize(n);
			for(int j=0; j<n; j++) {
				P[i][j].init(X(i),Y(j),sqr_side,(i+j)%2);
			}
		}
	}
	~board() { delete edge; }

	void moveto(int x, int y) {
		if(x<0 || x>=n || y <0 || y>=n)
			throw std::domain_error("Invalid coordinate");
		if(currx>=0 && curry>=0) {
			edge->imprint();
			edge->reset(X(currx),Y(curry),X(x),Y(y));
			P[currx][curry].setpiece(mark);
		}
		currx = x; curry = y;
		P[currx][curry].setpiece(knight);
	}
		
};


int main(int argc, char** argv) {
	if(argc!=2) {
		cerr << "Usage: " << argv[0] << " board-size" << endl;
		exit(1);
	}
	int N = std::stoi(argv[1]);
	board b(N,500);
	// cout << "Click to start the animation." << endl;
	// getClick();
	char x, y;
	for(cin >> x >> y; cin; cin >> x >> y) {
		int i = x-'a', j = y-'1';
		b.moveto(i,j);
		wait(0.3);
	}
	cout << "Click to exit." << endl;
	getClick();
}
