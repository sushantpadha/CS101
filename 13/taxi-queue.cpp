#include <iostream>
using std::cout; using std::cin;
using std::cerr; using std::endl; 
using std::string;

const int qCapacity = 6;
struct taxi { 
	string id; 
	void read() { cin >> id; }  // read until whitespace
};
struct customer { 
	string dest; 
	void read() { cin >> dest; }  // read until whitespace
};
struct taxiQueue { 
	taxi Q[qCapacity];
	int begin, end;
	bool full;
	bool enqueue(const taxi&);
	bool dequeue(taxi&);
	void clear();
	void inspect();
};

void taxiQueue::clear () {
	begin = end = 0;
	full = false;
}

void taxiQueue::inspect() {
	bool started = false;
	for(int i=begin; i != end || (full && !started); started = true, i = (i+1)%qCapacity)
		cout << Q[i].id << " ";
	cout << endl;
}

bool taxiQueue::enqueue (const taxi& t) {
	if(full) return false;
	Q[end] = t; // copy to  the end of the queue
	end =  (end+1) % qCapacity;
	if (end == begin) full = true;
	return true;
}

bool taxiQueue::dequeue (taxi& t) {
	if (end == begin && !full) return false;
	t = Q[begin]; // copy the front element into t
	begin = (begin+1) % qCapacity;  // advance begin
	full = false; // we cannot be full after dequeuing
	return true;
}
	
void assign(const taxi& t, const customer& c) {
	cout << "Customer going to " << c.dest << " assigned taxi " << t.id << endl;
}

int main() {
	char input;
	taxiQueue tq; // our taxi queue
	tq.clear();   // it will have junk, until cleared
	for (cin >> input; !cin.fail(); cin >> input) {
		if (input == 'T') {
			taxi t; t.read();
			bool ok = tq.enqueue(t);
			if (!ok)
				cerr << "Could not add taxi " << t.id << " to the stand!" << endl;
		} else if (input == 'C'){
			customer c; c.read();
			taxi t;
			bool ok = tq.dequeue(t);
			if(ok)
				assign(t,c);
			else
				cerr << "Could not find a taxi for customer going to " << c.dest << endl;
		} else
			break;
		cout << "Taxis in the stand: ";
		tq.inspect();
	}
}

