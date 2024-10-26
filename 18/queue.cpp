#include <iostream>
using std::cout; using std::cin; using std::endl;

struct node { int val; node* next = nullptr; };

struct queue {
  node* head = nullptr;
  node* tail = nullptr;
  void enqueue(int v) {
	  //if(!tail)
	  //  tail = head = new node;
	  //else 
	  //  tail = tail->next = new node;
	  tail = (tail? tail->next : head) = new node;
	  tail->val = v;
  }
  bool dequeue(int& v) {
	  if(!head) return false;
	  v = head->val;
	  node* tmp = head;
	  head = head->next;
	  delete tmp;
	  if(!head) tail=nullptr;
	  return true;
  }
  void print() {
	  for(node* p = head; p; p = p->next)
		  cout << p->val << " ";
	  cout << endl;
  }
  void clear() {
	  int v;
	  while (dequeue(v)) {}
  }
};

void queue_demo() {
  queue Q; char c; int v;
  cout << "Type '< n' to enqueue the number n, and '>' to dequeue. x to quit: ";
  cin >> std::skipws;
  for(cin >> c; c != 'x'; cin >> c)
	  if(c == '<' && (cin >> v, !cin.fail())) Q.enqueue(v);
	  else if(c=='>') Q.dequeue(v) && cout << v << " ";
  cout << "\nWhen finished, the contents of the queue are: ";
  Q.print(); cout << endl;
  Q.clear();
} 

void queue_leak_demo() {
	queue Q;
	for(int i=0; i < 10000000; i++)
		Q.enqueue(1);
    Q.clear();
}

int main() {
	for(int i=0; i < 100; i++)
		queue_leak_demo();
	cout << "Finished. Press Enter to exit.\n";
	char c; cin >> std::noskipws >> c;
	queue_demo();
} 