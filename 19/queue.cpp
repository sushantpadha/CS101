#include <iostream>
#include "queue.h"
using std::endl; 

#define DBG 1
#define LOG if(DBG) (std::cerr << "-->In function " << __func__ << ": ")

struct queue::node { int val; node* next = nullptr; };

void queue::enqueue(int v) {
	tail = (tail? tail->next : head) = new node;
	tail->val = v;
}

bool queue::dequeue(int& v) {
	if(!head) return false;
	v = head->val;
	node* tmp = head;
	head = head->next;
	delete tmp;
	if(!head) tail=nullptr;
	return true;
}

void queue::print(ostream& os) const {
	for(node* p = head; p; p = p->next)
		os << p->val << (p->next?" ":"");
}

void queue::clear() {
	int v;
	while (dequeue(v)) {}
}


void queue::copy(const queue& src, queue& dest) {
	dest.clear(); // redundant if called from the copy constructor
	for(const node* n = src.head; n; n = n->next)
		dest.enqueue(n->val);
}


queue::~queue() {
	LOG << "Destroying a queue: " << *this << endl;
	clear();
}

queue::queue() {
	LOG << "Created an empty queue!\n"; 
}

queue::queue(int v) {
	enqueue(v); 
	LOG << "Created a non-empty queue: " << *this << endl;
}

queue::queue(const queue& q) { 
	copy(q,*this); 
	LOG << "Copy constructed a queue: " << *this << endl;
}

queue& queue::operator= (const queue& q) {
	LOG << "Changing " << *this << " to " << q << endl;
	copy(q,*this); 
	return *this;
}


queue& queue::operator+= (const queue& q) {
	LOG << "Adding " << q << " to " << *this << endl;
	queue tmp = q;
	( tail ? tail->next:head ) = tmp.head;
	if(tmp.tail) tail = tmp.tail;
	tmp.head = tmp.tail = nullptr;
	LOG << "Finished adding. Got " << *this << endl;
	return *this;
}
