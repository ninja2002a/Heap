
#include <iostream>

using namespace std;

class Node {

 public:
  Node();
  
  void setNext(Node* user); //sets the next node
  Node* getNext(); //returns the next node

  void setLeft(Node* user); //sets the left node
  Node* getLeft(); //returns the left node

  void setRight(Node* user); //sets the right node
  Node* getRight(); //returns the right node

  void setData(int user); //sets character value
  int getData(); //returns character value
  
 private:
  Node* next;
  Node* left;
  Node* right;
  int data;

};
