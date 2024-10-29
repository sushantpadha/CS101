#include <iostream>
using std::ostream;

class queue {
  struct node;
  node* head = nullptr;
  node* tail = nullptr;
  bool dequeue_error = false;
  void enqueue(int);
  bool dequeue(int&);
  void print(ostream& os) const;
  void clear();
  void copy(const queue& src, queue& dest);
public:
  queue& operator<< (int v) {enqueue(v); return *this;}
  queue& operator>> (int& v) {dequeue_error = !dequeue(v); return *this;}
  bool fail() {return dequeue_error;}
  friend ostream& operator<< (ostream& out, const queue& q) {q.print(out); return out;}
  operator bool() const {return head;}  // cast to boolean to check if queue is empty
  ~queue();
  queue();
  queue(int);
  queue(const queue& q);
  queue& operator+= (const queue& q);
  queue& operator= (const queue& q);
};


