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


void drawtree(int* heaparray){ //prints the tree

}

void printarray(int* heaparray){
  int p = 0;
  
  while (heaparray[p] != 0){
    cout << heaparray[p] << endl;
    p++;
  }
  
}

void max(int* heaparray){ //rearranges the heap such that each parent node is larger than or equal to the value of its child
  int h = 0;
  /*
    if (heaparray[h] < heaparray[2h + 1]){
    //if left child of parent position h is greater, swap position
    
    max(heaparray);
    }

    else if (heaparray[h] < heaparray[2h+2]){ 
    //if right child of parent position h is greater, swap position 
    
    max(heaparray);
    }



  */
}

void uparse(char* userexp, int* heaparray, int i, int j){ //reads user input to place in an array
  ///*
  //int* userexp = new int[505];
  
  //cout << "enter each number followed by a space" << endl;
  //cin.getline(userexp, 505);
  //cin >> (userexp);

  
  //heaparray[0] = userexp;

  /*
  int j = 0;
  while (userexp != 0) {
    heaparray[j] = userexp
  }

  //*/
  //cout << heaparray[0] << endl;
  //cout << userexp << endl;
  //*/

  //int j = 0;
  cout << userexp[i] << endl;
  
  if (userexp[i] != 32 && userexp[i] != 0) {
    //if userexp is not a space or null
    //temp is userexp
    
    int temp = userexp[i];
    i++;
    
    while (userexp[i] != 32 && userexp != 0){
      temp = (temp * 10) + userexp[i];
      cout << "adding" << endl;
      i++;
    }
    
    
    heaparray[j] = temp;
    j++;
  }




  
  uparse(userexp, heaparray, i, j);  
  

    /*

  if (userexp[i] != 32 && userexp[i] != 0){
    //if user input at postion i is not space/blank 
    //add to first open position in array      

    int j = 0;
    while(heaparray[j] != 0){
      j++; 
    }
    heaparray[j] = userexp[i];
    i++;
    uparse(userexp, heaparray, i); 
  }
  
  else if (userexp[i] == 32){
    i++;
    uparse(userexp, heaparray, i);
  }
  
  //*/
  
}


void fparse(int* heaparray){ //reads in file input to place in an array
  cout << "enter file name" << endl;
  //cin file name
  char filename;

  
  //read and copy numbers to heaparray
  
}

void printnum(int* heaparray){ //prints numbers in order of largest to smallest
  //print numbers as they are pulled off of the array
  
  
}

void pullroot(int* heaparray){ //removes the largest value (root) from the heap
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
  heaparray[r] = temp;

  //*/
}


int main(){
  char userinput;
  bool running = true;
  int* heaparray = new int[101]; //array to store the heap numbers 
  char* userexp = new char[505];
  int i = 0; //keeps track of position in userexp array, used in uparse() 
  int j = 0;
    
  while (running == true){
    cout << "What do you want to do?" << endl;
   
    cin >> userinput;
    cin.get();


    
    if (userinput == 'q'){ //quits the program
      running = false;
    }
    
    else if (userinput == 'e'){ //

      cout << "read in from user or file?" << endl;
      cin >> userinput;
      cin.get();

      if (userinput == 'u'){
	//cout << "enter each number followed by a space" << endl;
	
	
	//cin.getline(userexp, 505);
	//cin >> userexp;
	cout << "enter each number followed by a space" << endl;
	cin.getline(userexp, 505);
	uparse(userexp, heaparray, i, j);
	cout << "after uparse" << endl;
	//max(heaparray);
      }
      
      else if (userinput == 'f'){
	cout << "reading in from file" << endl;
	//fparse(heaparray);
	//max(heaparray);
      }  
    }

    
    else if (userinput == 'p'){
      //drawtree();
      cout << "printing heaparray" << endl;
      printarray(heaparray);

      //printnum();

    }
    
    
    
  }
  

  
  return 0;
}
