#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/*
Heap
Written By: Starfy100
Program will read in a string of numbers from user or file
Program will place each number into a heap and the sort into a max heap
After the max heap is formed, the resulting tree is printed
Once the tree is printed, items will be removed from the tree
Items are removed from largest to smallest and then placed in an output


To remove element, swap root (largest) with the most recently added
Then remove the once-root
Then recursively max-heapify to make the root the largest item again, repeat


To print tree, tab once for every layer of the tree
The resulting tree will be formed sideways
 */


//TO DO: Read from file, output in order of largest to smallest, print tree

void drawtree(int* heaparray){ //prints the tree

}

void printarray(int* heaparray){
  int p = 0;
  cout << "printing heap array" << endl;
  while (heaparray[p] != 0){
    cout << heaparray[p] << " ";
    p++;
  }
  cout << endl;  
}

void max(int* heaparray, int h){ //rearranges the heap such that each parent node is larger than or equal to the value of its child
  
  if(heaparray[h] != 0) { //if array @ h is not null

    if (heaparray[(2*h)+1] != 0){ //if left child is not null 
      if (heaparray[h] < heaparray[(2*h) + 1]){
	//if left child of parent position h is greater, swap position
	cout << "left child is greater than parent, swap" << endl;
	int temp = heaparray[h];
	heaparray[h] = heaparray[(2*h) + 1];
	heaparray[(2*h)+1] = temp;
	
	h = 0; //restart from the top
	max(heaparray, h);
	
      }
      
      ///*
      else {
	//if the parent is greater, move on
	h++;
	max(heaparray, h);
      }
      //*/
    }
    
    if(heaparray[(2*h)+2] != 0){ //if right child is not null
      if (heaparray[h] < heaparray[(2*h) + 2]){ 
	//if right child of parent position h is greater, swap position 
	cout << "right child is greater than parent, swap" << endl;
	int temp = heaparray[h];
	heaparray[h] = heaparray[(2*h)+2];
	heaparray[(2*h)+2] = temp;
	
	h = 0; //restart from the top	
	max(heaparray, h);

      }
      ///*
      else{
	//if the parent is greater, move on
	h++;
	max(heaparray, h);
      }
      //*/
      
    }

  } 
  
}

void uparse(char* userexp, int* heaparray, int i, int h){ //reads user input to place in an array
 
  for (i = 0; i < 505; i++) {
    if (userexp[i] != 32 && userexp[i] != 0) {
      //if userexp is not a space or null
      //temp is userexp
      
      heaparray[h] = (int)userexp[i] - 48; //convert char userexp to int heaparray
      int temp = 0;
      
    ///*
    while (userexp[i+1] != 32 && userexp[i+1] != 0){
      temp = (int)userexp[i+1] - 48;
      heaparray[h] = (heaparray[h] * 10) + temp;
      //cout << "adding" << endl;
      i++;
    }
    //*/
    
    //cout << heaparray[j] << endl;
    h++;
    i++;
    }
    else {
      i++;
    }
    
  }
    
}


void fparse(int* heaparray){ //reads in file input to place in an array
  cout << "enter file name" << endl;
  //cin file name
  char filename;

  
  //read and copy numbers to heaparray
  
}

void printnum(int* outputarray){ //prints numbers in order of largest to smallest
  //print numbers as they are pulled off of the array
  int p = 0;
  cout << "printing output array" << endl;
  while (outputarray[p] != 0){
    cout << outputarray[p] << " ";
    p++;
  }
  cout << endl;  
  
}

void pullroot(int* heaparray, int* outputarray, int o, int h){
  //removes the largest value (root) from the heap
  //removes via swap and recursive max-heapify
  //the removed item will be printed


  ///*
    int r = 0;
  while (heaparray[r+1] != 0){ 
  r++;
  }
  
  //swap first and last items
  int temp;
  temp = heaparray[0];
  heaparray[0] = heaparray[r];
  heaparray[r] = 0;

  outputarray[o] = temp;
  max(heaparray, h);
  //*/
}


int main(){
  char userinput;
  bool running = true;
  int* heaparray = new int[101]; //array to store the heap numbers 
  char* userexp = new char[505]; //array to store the user input

  int* outputarray = new int [101]; //array to store the output numbers
    
  int i = 0; //keeps track of position in userexp array, used in uparse() 
  int o = 0; //keeps track of position in output array, used in pullroot()

  int h = 0; //keeps track of position in heaparray, used in max()
    
  while (running == true){
    cout << "What do you want to do? (qUIT, eNTER, pRINT, mAX)" << endl;
   
    cin >> userinput;
    cin.get();
    
    if (userinput == 'q'){ //quits the program
      cout << "entered 'q'" << endl;
      running = false;
    }
    
    else if (userinput == 'e'){ //
      cout << "entered 'e'" << endl;
      cout << "read in from user or file?" << endl;
      cin >> userinput;
      cin.get();

      if (userinput == 'u'){
	cout << "entered 'u'" << endl;
	
	
	//cin.getline(userexp, 505);
	//cin >> userexp;
	cout << "enter each number followed by a space" << endl;
	cin.getline(userexp, 505);
	i = 0;
	h = 0;
	uparse(userexp, heaparray, i, h);
	cout << "after uparse" << endl;
	//cout << "sorting" << endl;
	//h = 0;
	//max(heaparray, h);
      }
      
      else if (userinput == 'f'){
	cout << "reading in from file" << endl;
	//fparse(heaparray);
	//max(heaparray);
      }  
    }

    
    else if (userinput == 'p'){
      //drawtree();
      cout << "entered 'p'" << endl;
      cout << "printing heaparray" << endl;
      printarray(heaparray);
      //printnum();
    }
    
    else if (userinput == 'm'){
      cout << "entered 'm'" << endl;
      cout << "maxing heap" << endl;
      max(heaparray, h);
    }

    else if (userinput == 'r'){
      cout << "entered 'r'" << endl;
      cout << "pulling root" << endl;
      h = 0;
      pullroot(heaparray, outputarray, o, h);
    }
    
  }
  

  
  return 0;
}
