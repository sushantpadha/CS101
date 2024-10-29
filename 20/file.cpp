#include <iostream>
#include <fstream>
using std::string;


void join(string fname1, string fname2, string outname) {
  std::ifstream f1 (fname1);
  std::ifstream f2 (fname2);
  std::ofstream fout (outname);
  while(f1 || f2) {
    int x, y;
    if (f1)
      (f1 >> x) && fout << x;
    if (f2)
      (f2 >> y) && fout << '\t' << y;
    fout << std::endl;
  }
}

int main(int argc, char** argv) {
	if(argc!=4) {
		std::cerr << "Usage: " << argv[0] << " file1 file2 outfile" << std::endl;
		exit(1);
	}
	join(argv[1],argv[2],argv[3]);
}
