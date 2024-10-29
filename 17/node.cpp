#include <iostream>
using std::cout; using std::endl; 

struct node { 
  int val;
  node* left;  // nullptr if no child
  node* right; // nullptr if no child
};

void printTree(node* root) {
  if (!root)  // equivalently, if(root != nulptr)
    return;
  cout << " (";
  cout << root->val;
  printTree(root->left); 
  printTree(root->right);
  cout << ") ";
}

int main() {
	node leaf1 = {1, nullptr, nullptr};
	node leaf2 = {2, nullptr, nullptr};
	node parent1 = {3, &leaf1, &leaf2};
	node leaf3 = {4, nullptr, nullptr};
	node leaf4 = {5, nullptr, nullptr};
	node parent2 = {6, &leaf3, &leaf4};
	node rootnode = {7, &parent1, &parent2};
	printTree(&rootnode);
	cout << endl;
}
