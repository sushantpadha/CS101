#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;
using std::unordered_map;
using std::map;

template <typename mapType>
void print_freqs(const vector<string>& text) {
	mapType counts;
	for(const auto& w: text) 
		++counts[w];
	for(const auto& entry: counts)
		cout << entry.first << ": " << entry.second << endl;
}

void sort_and_print_freqs(vector<string>& text) { 
	sort(text.begin(),text.end(),std::greater<string>()); // descending order
	string prevw=""; int count = 0; bool started = false;
	for(const auto& w : text) {
		if(prevw != w) { // time to flush prevw
			if(started) // don't print the first time
				cout << prevw << ": " << count << endl;
			prevw = w; count = 0;
		}
		++count;
		started = true;
	}
	if(started) // print the last one (unless empty text)
		cout << prevw << ": " << count << endl;
}

int main(int argc, char** argv) {

	vector<string> text(argv+1,argv+argc); // read text from commandline arguments
	if(text.size()==0) { // if no commandline arguments, read text from stdin
		string w; 
		for(cin >> w; !cin.fail(); cin >> w)
			text.push_back(w);
	}
	print_freqs<map<string,int>>(text);
	cout << endl;
	print_freqs<unordered_map<string,int>>(text);
	cout << endl;
	sort_and_print_freqs(text);
}
