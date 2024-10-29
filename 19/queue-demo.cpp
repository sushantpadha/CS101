#include <iostream>
#include "queue.h"
using std::cout; using std::cin; using std::endl;

#define TRACE 1
#define INFO if(TRACE) (std::cerr << "#Line " << __LINE__ << ": ")


int main() {
	queue Q1, Q2;           // two queues
	if(!(Q1 || Q2)) cout << "Q1 and Q2 are empty\n";
	Q1 << 1 << 2 << 3;      // enqueue 1, 2, 3 into Q1
	INFO << "Q1 is now " << Q1 << endl;
	Q2 = Q1;                // copy (assign) contents of Q1 to Q2
	INFO << "Q2 is now " << Q2 << endl;
	int x, y;
	Q2 >> x >> y;           // dequeue into x and then into y
	INFO << "Q2 is now " << Q2 << endl;
	Q2 += Q1;               // append contents of Q to the end of Q.
	cout << "Q1: " << Q1 << " and Q2: " << Q2 << endl; // print the queues
	queue* q = new queue(99);
	*q << 8;
	INFO << "*q : " << *q << endl;
	(Q1 = *q) += Q2;
	INFO << "Q1 is now " << Q1 << endl;
	delete q;
} 
