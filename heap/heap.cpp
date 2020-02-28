#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

/*
Heap
Written By: Starfy100
Program will read in a string of numbers from user or file
Program will place each number into a heap and then sort into a max heap
After the max heap is formed, the resulting tree is printed
Once the tree is printed, items can be removed from the tree
Items are removed from largest to smallest and then placed in an output

To remove element, swap root (largest) with the most recently added
Then remove the once-root
Then itertively max-heapify to make the root the largest item again, repeat

To print tree, tab once for every layer of the tree
The resulting tree will be formed sideways
 */

void drawtree(int* heaparray, int layer, int h){ //prints the tree
  //tab (/t) for every laayer
  if (heaparray[(2*h)+1] != 0){ //if right child is not null
    drawtree(heaparray, layer+1, (2*h)+1 );
  }
    for (int i = 0; i < layer; i++){
      //print a 'tab' for every layer of the tree
      cout << '\t';
    }
    cout << heaparray[h] << endl;
  if (heaparray[(2*h)] != 0){
    drawtree(heaparray, layer+1, h*2);
  }
}

void uparse(char* userexp, int* heaparray, int i, int h){
  //reads user input to place in an array
  
  for (i = 0; i < 505; i++) {
    if (userexp[i] != 32 && userexp[i] != 0) {
      //if userexp is not a space or null
      int converted = (int)userexp[i] - 48; //convert char userexp to int heaparray
      int temp = 0; //variable to store subsequent digits
      while (userexp[i+1] != 32 && userexp[i+1] != 0){
	//turn the int into a multi-digit int
	temp = (int)userexp[i+1] - 48;
	converted = (converted * 10) + temp;
	i++;
      }
      
      //travel to the end of array and place
      while (heaparray[h] != 0){
	h++;
      }
      heaparray[h] = converted;   
      while (h > 1 && heaparray[h] > heaparray[(h/2)]){
	//swap h and h/2
	int swap = heaparray[h];
	heaparray[h] = heaparray[(h/2)];
	heaparray[(h/2)] = swap;
	
	h = (h/2);
      }
      h++;
      i++;
    }
    else {
      i++;
    }
  }
}

void fparse(int* heaparray, int i, int h){ //reads in file input to place in an array
  cout << "enter file name" << endl;
  string line;
  char* filename = new char[100];
  char* filedata = new char[505];
 
  cin >> filename;
  cin.get();
  cout << "reading " << endl;
  ifstream myfile (filename);
  if (myfile.is_open()) {
    while (getline (myfile, line)) {
    
      int j = 0;
      while(line[j] != 0){
	filedata[j] = line[j];
	j++;
      }
   
    }
    myfile.close();
  }
  else {
    cout << "unable to open file" << endl;
  }
  //read and copy numbers to heaparray
  for (i = 0; i < 505; i++) {
    if (filedata[i] != 32 && filedata[i] != 0) {
      //if filedata is not a space or null
      int converted = (int)filedata[i] - 48; //convert char userexp to int heaparray
      int temp = 0; //variable to store subsequent digits
      while (filedata[i+1] != 32 && filedata[i+1] != 0){
      //turn the int into a multi-digit int
	temp = (int)filedata[i+1] - 48;
	converted = (converted * 10) + temp;
	i++;
      }
      
      //place at end of array
      while (heaparray[h] != 0){
	h++;
      }
      heaparray[h] = converted;
      while (h > 1 && heaparray[h] > heaparray[(h/2)]){
	//swap h and h/2
	int swap = heaparray[h];
	heaparray[h] = heaparray[(h/2)];
	heaparray[(h/2)] = swap;
	h = (h/2);
      }
      h++;
      i++;
    }
    else {
      i++;
    }
  }  
}

void printnum(int* outputarray){ //prints numbers in order of largest to smallest
  //print numbers once they are all pulled off of the heap
  int p = 0;
  while (outputarray[p] != 0){
    cout << outputarray[p] << " ";
    p++;
  }
  cout << endl;  
}

void pullroot(int* heaparray, int* outputarray, int o, int h){
  //removes the largest value (root) from the heap
  //removes via swap and iterative max-heapify
  //the removed item will be stored in a separate array
  //the separate array will then be printed

  while (heaparray[1] != 0){
    //while the heap is not empty, pull the largest item
    int r = 1;
    while (heaparray[r+1] != 0){ 
      r++;
    }
    //swap first and last items
    int temp = heaparray[1];
    heaparray[1] = heaparray[r];
    heaparray[r] = 0;
    outputarray[o] = temp;
    o++;
    h = 1;
    
    while (heaparray[h] != 0 && (heaparray[h] < heaparray[h*2] || heaparray[h] < heaparray[(h*2)+1]) ) {
      //sort array
      if (heaparray[(h*2)+1] < heaparray[h*2]) {
	//if the left child is larger, swap
	int swap1 = heaparray[h];
	heaparray[h] = heaparray[h*2];
	heaparray[h*2] = swap1;
	h = h*2;
      }
      else if (heaparray[h*2] < heaparray[(h*2)+1]) {
	//if the right child is larger, swap
	int swap2 = heaparray[h];
	heaparray[h] = heaparray[(h*2)+1];
	heaparray[(h*2)+1] = swap2;
	h = (h*2)+1;
      }	
    }
  }  
}


int main(){
  char userinput;
  bool running = true;
  int* heaparray = new int[101]; //array to store the heap numbers 
  char* userexp = new char[505]; //array to store the user input
  int* outputarray = new int [101]; //array to store the output numbers
  
  int i = 0; //keeps track of position in input arrays, used in uparse() & fparse() 
  int o = 0; //keeps track of position in output array, used in pullroot()
  int h = 1; //keeps track of position in heaparray, used in uparse(), fparse(), pullroot() and drawtree()
  int layer = 0; //keeps track of tree layers, used in drawtree()

  while (running == true){
    cout << "What do you want to do? (qUIT, eNTER, pRINT)" << endl;
    cin >> userinput;
    cin.get();
    
    if (userinput == 'q'){ //quits the program
      cout << "entered 'q'" << endl;
      running = false;
    }
    
    else if (userinput == 'e'){ //read from user or file
      cout << "entered 'e'" << endl;
      cout << "read in from user or file?" << endl;
      cin >> userinput;
      cin.get();
      
      if (userinput == 'u'){
	cout << "entered 'u'" << endl;
	cout << "enter each number followed by a space" << endl;
	cin.getline(userexp, 505);
	i = 0;
	h = 1;
	uparse(userexp, heaparray, i, h);
	cout << "input recorded" << endl;
      }
      
      else if (userinput == 'f'){
	cout << "reading in from file" << endl;
	fparse(heaparray, i, h);
	cout << "input recorded" << endl;
      }  
    }
    
    else if (userinput == 'p'){
      cout << "entered 'p'" << endl;

      cout << "printing tree" << endl;
      drawtree(heaparray, layer, h);
      cout << "printing in order of largest to smallest" << endl;
      h = 1;
      pullroot(heaparray, outputarray, o, h);
      printnum(outputarray);
    }
    
  }
  return 0;
}
