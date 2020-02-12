#include <iostream>
#include <string.h>
#include "node.h"

using namespace std;

/*
Shunting Yard Algorithm
Written By: Starfy100
Program will read in a user expression
expression will be translated to postfix notation
Using the postfix notation, the expression will be translated into an expression tree
The user can decide if the output will be in pre/post/infix notation
Valid Inputs Are: + - * / ^ ( ) and any integer

Start Date: 1/29/2020
 */


void push(Node* current0, Node* &stackhead) { //adds item to stack
  if (stackhead == NULL){
    //stack is empty, insert item
    Node* temp = new Node();
    temp->setData(current0->getData());
    temp->setLeft(current0->getLeft());
    temp->setRight(current0->getRight());

    stackhead = temp;
  }
  else if (stackhead != NULL){
    //head is not null, item becomes the new head
    Node* temp = new Node();
    temp->setData(current0->getData());
    temp->setLeft(current0->getLeft());
    temp->setRight(current0->getRight());
    
    temp->setNext(stackhead);
    stackhead = temp;
  }
}

void pop(Node* &stackhead){ //removes item from stack in reverse order

  if (stackhead != NULL) {
    //move the head of the stack
    stackhead = stackhead->getNext();
  }
  
  else {
    cout << "no data" << endl;
  }
}

int peek(Node* stackhead){ //looks at the top element of the stack
  //returns an int depending on the element's precdence
  //0 == No Data
  //1 == (
  //2 ==  + or -
  //4 == / or *
  //5 == ^  
  //6 == ) 
  //7 == number
  
  if (stackhead != NULL) { //if the stack head is not NULL, check stack head
    
    if (stackhead->getData() == 40){
      //element is ( 
      return 1;
    }
    else if (stackhead->getData() == 41){
      //element is )
      return 6;
    }
    else if (stackhead->getData() == 94){
      //element is ^
      return 4;
    } 
    else if (stackhead->getData() == 42 || stackhead->getData() == 47){
      //element is / or *
      return 3;
    }
    else if (stackhead->getData() ==  43 || stackhead->getData() == 45){
      //element is + or -
      return 2;
    } 
    else if (stackhead->getData()  >= 48 && stackhead->getData() <= 57){
      //element is number
      return 7;
    }
    
  }
  else {
    //stack has no data
    return 0;
  }
}


void enqueue(Node* current0, Node* &queuehead){ //adds item to the back of the queue
  if (queuehead == NULL){ //queue is empty, item is head of queue
    cout << "queue head is empty" << endl;
    Node* temp = new Node();
    temp->setData(current0->getData());
    temp->setLeft(current0->getLeft());
    temp->setRight(current0->getRight());
    queuehead = temp;
  }
  
  else if (queuehead != NULL){
    //if the queuehead is not null, queue has items
    //add an item to the end of queue
    Node* queuecurrent = new Node();
    queuecurrent = queuehead;
    
    while (queuecurrent->getNext() != NULL){
      //go to the end of the queue
      queuecurrent = queuecurrent->getNext();
    }

    //put new item at the end
    Node* temp = new Node();
    temp->setData(current0->getData());
    temp->setLeft(current0->getLeft());
    temp->setRight(current0->getRight());
    queuecurrent->setNext(temp);   
  } 
}

void dequeue(Node* current0, Node* &queuehead){
  //removes item from the front of the queue
  if (queuehead != NULL) {
    queuehead = queuehead->getNext();
  }
  else {
    //queue has no data
    cout << "no data" << endl;
  }
}


char* printpre(Node* current0){ //print in prefix notation
  if (current0 != NULL){
    cout << (char)current0->getData();
    printpre(current0->getLeft());
    printpre(current0->getRight());
  }
  return 0;
}

///*
void dump(Node* queuehead,Node* stackhead, Node* binaryhead){ //deletes the heads
  queuehead->setNext(NULL); 
  stackhead->setNext(NULL); 
  binaryhead->setNext(NULL);   
}
//*/

char* printin(Node* current0){ //prints in infix notation
  //cout << "printin" << endl;
  if (current0 != NULL){
   printin(current0->getLeft());
   cout << (char)current0->getData();
   printin(current0->getRight());
   //cout << (char)current0->getData();

  }
  return 0;
}


char* printpost(Node* current0){
  //prints in postfix notation
  
  if (current0 != NULL){       
    printpost(current0->getLeft());
    printpost(current0->getRight());
    cout << (char)current0->getData();
  }
  
  return 0;
}


void parse(char* userexp, int i, Node* &inhead, Node* current0){ //converts input into individual items

  
  if (userexp[i] != 32 && userexp[i] != 0){
    //if the user input array[i] is not space and not null (a character)
    //add it to the list

    if (inhead == NULL) {
      //head is null, make new head node
      Node* newnode = new Node();
      inhead = newnode;
      newnode->setData(userexp[i]);
      i++;
      //restart the process with the next item in the user input array
      parse(userexp, i, inhead, current0);
    }
    
    else if (inhead != NULL){
      current0 = inhead;
      while (current0->getNext() != NULL){
	current0 = current0->getNext();
      }
      Node* temp = new Node();
      temp->setData(userexp[i]);
      current0->setNext(temp);
      i++;
      current0 = inhead;
      parse(userexp, i, inhead, current0);
    }
    
  }
  
  else if (userexp[i] == 32 && userexp[i] != 0) {
    //if the user input array[i] is a space and not null, move on
    i++;
    parse(userexp, i, inhead, current0);
  }
  else {
    //if the user input array[i] is null, stop
  }
  
}

void convertpostfix(Node* inhead, Node* &stackhead, Node* &queuehead, Node* current0){

  //order of precedence, highest to lowest: ()  ^  /*  +-
  //if the top item of the stack ha greater or equal precedence
  //enqueue the stack
  
    if (current0->getData() >= 48 && current0->getData() <= 57){
      //item is a number, enqueue
      enqueue(current0, queuehead);
      //move forwards
      if (current0->getNext() != NULL) {
	current0 = current0->getNext();
	convertpostfix(inhead, stackhead, queuehead, current0);
      } 
    }
    
    
    else if (current0->getData() == 40) {
      //item is left parenthesis "("
      push(current0, stackhead);
      //move forwards
      if (current0->getNext() != NULL) {
	current0 = current0->getNext();
	convertpostfix(inhead, stackhead, queuehead, current0);
      }
    }
    
    else if (current0->getData() == 41) {
      //item is right parenthesis ")"
      
      while (peek(stackhead) != 1){
	//while the stackhead is not (, pop
	enqueue(stackhead, queuehead);
	pop(stackhead);
      }
      pop(stackhead);
      
      //move forwards
      if (current0->getNext() != NULL) {
	current0 = current0->getNext();
	convertpostfix(inhead, stackhead, queuehead, current0);
      }
    }
    /*
    else if (current0->getData() == 94) {
      //item is exponent "^"
      cout << "item is exponent ^" << endl; 
      if (peek(stackhead) > peek(current0) || peek(stackhead) == peek(current0)){
	cout << "stackhead has equal or higher precedence" << endl;
	//enqueue(stackhead, queuehead);
	
	while (peek(stackhead) > 1){
	  enqueue(stackhead, queuehead);
	  pop(stackhead);  
	}
	
       
      
	push(current0, stackhead);
	
	if (current0->getNext() != NULL) {
	  current0 = current0->getNext();
	  convertpostfix(inhead, stackhead, queuehead, current0, posthead);
	}
      }
      else if (peek(stackhead) < peek(current0)){
	push(current0, stackhead);
	if (current0->getNext() != NULL) {
	  current0 = current0->getNext();
	  convertpostfix(inhead, stackhead, queuehead, current0, posthead);
	}	
      }
    }
    
    
    else if (current0->getData() == 42 || current0->getData() == 47) {
      //item is times or divide "* or /"
      cout << "item is times or divide" << endl;
      if (peek(stackhead) > peek(current0) || peek(stackhead) == peek(current0) || peek(stackhead) == 5){
	
	//enqueue(stackhead, queuehead);
	while (peek(stackhead) > 1){
	  cout << "queueing stack" << endl;
	  enqueue(stackhead, queuehead);
	  pop(stackhead);
	}
   
       
	push(current0, stackhead);
	if (current0->getNext() != NULL) {
	  current0 = current0->getNext();
	  convertpostfix(inhead, stackhead, queuehead, current0, posthead);
	}
      }
      else if (peek(stackhead) < peek(current0)){
	push(current0, stackhead);
	if (current0->getNext() != NULL) {
	  current0 = current0->getNext();
	  convertpostfix(inhead, stackhead, queuehead, current0, posthead);
	}
      }
    }
    //*/  
  
    else if (current0->getData() == 43 || current0->getData() == 45 || current0->getData() == 42 || current0->getData() == 47 || current0->getData() == 94) {
      //item is an operator

      if (peek(stackhead) > peek(current0) || peek(stackhead) == peek(current0)){
	//if the stackhead is of equal or greater precedence, enqueue the stack
	while (peek(stackhead) > 1){
	  enqueue(stackhead, queuehead);
	  pop(stackhead);
	}
 
	push(current0, stackhead);
	if (current0->getNext() != NULL) { //move on to the next item
	  current0 = current0->getNext();
	  convertpostfix(inhead, stackhead, queuehead, current0);
	}
      }
      
      else if (peek(stackhead) < peek(current0)){
	//if the stack has lower precedence, push current onto stack
	push(current0, stackhead);
	if (current0->getNext() != NULL) {
	  current0 = current0->getNext();
	  convertpostfix(inhead, stackhead, queuehead, current0);
	}
      }
    }
  
    while (peek(stackhead) != 0 && current0->getNext() == NULL){
      enqueue(stackhead, queuehead);
      pop(stackhead);
    }   
}

    
  
void binarytree(Node* current0, Node* &stackhead, Node* binaryhead, Node* queuehead) { //converts postfix notation into a binary tree
  //to build the tree, function pushes numbers onto the stack until it reaches an operator
  //when an operator is found, the top two items are popped and made the right and left nodes
  //(the first popped becomes the right, and the second popped becomes the left)


  if (current0 != NULL) {
    if (current0->getData() >= 48 && current0->getData() <= 57){
      //if the current is a number, push it to the stack
   
      push(current0, stackhead);
      
      if (current0->getNext() != NULL){ //moves on to the next item
	current0 = current0->getNext();
	binarytree(current0, stackhead, binaryhead, queuehead);
      }
    }

	
    else if (current0->getData() == 42 || current0->getData() == 43 || current0->getData() == 45 || current0->getData() == 47 || current0->getData() == 94) {
      //if the current is equal to an operator
      //pop the top two items on the stack
      
      current0->setRight(stackhead);      
      pop(stackhead);
      current0->setLeft(stackhead);
      pop(stackhead);
      push(current0, stackhead);
    
      if (current0->getNext() != NULL){ //moves on to the next item
	current0 = current0->getNext();
	binarytree(current0, stackhead, binaryhead, queuehead);
      }
    } 
  }
}

  

int main(){
  char* userexp = new char[100];
  char userinput;
  bool running = true;

  int i = 0; //for use in moving along array userexp, in void parse()
  
  Node* inhead = NULL; //head for the parsed infix notated list
  Node* queuehead = NULL; //head for the queue 
  Node* stackhead = NULL; //head for the stack
  Node* binaryhead = NULL; //head for the binary tree
  Node* current0 = inhead; //the current node in a list

  
  while (running == true){
    cout << endl;
    cout << "what do you want to do? (eNTER, pRINT, qUIt)" << endl;
    cin >> userinput;
    cin.get();
    
    if (userinput == 'e'){ //records user expression
      
      cout << "enter expression" << endl;
      cin.getline(userexp, 100);
      //cin.get();
      
      cout << "You typed: " << userexp << endl;
      parse(userexp, i, inhead, current0);
      cout << "converting to postfix notation" << endl;
      current0 = inhead;
      convertpostfix(inhead, stackhead, queuehead, current0);
      cout << "converting to binary tree" << endl;
      current0 = queuehead;
      binarytree(current0, stackhead, binaryhead, queuehead);
    }
    
    else if (userinput == 'p') { //triggers print
      //cout << "how do you want to print? i, t, e" << endl;
      //cout << "(Infix, Postfix or Prefix notation)" << endl;

      cout << "iNFIX, POStFIX, PReFIX" << endl;

      cin >> userinput;
      cin.get();

      if (userinput == 'i'){ //triggers infix print
	current0 = stackhead;
	printin(current0);
      }
      
      else if (userinput == 't'){//triggers postfix print
	current0 = stackhead;
	printpost(current0);
      }
      
      else if (userinput == 'e'){ //triggers prefix print
	current0 = stackhead;
	printpre(current0);
      }
      
    }
     
    else if (userinput == 'd'){ //dumps all input data
      cout << "Dumping (not implemented yet)" << endl;
      
    }
    else if (userinput == 'q'){ //quits the program
      running = false;
    }
    
  }
  return 0;
}
