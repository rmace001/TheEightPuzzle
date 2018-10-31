#include <iostream>
#include <vector>
using namespace std;

//////Three possible outcomes of search:
/////1. to report success
/////2. to report failure (which is actually a success)
/////3. to run until you run out of memory or time and kill the program 

struct node {
  unsigned short arr[3][3];
  
  void print(){
    for (short i=0; i<3; i++){
      for (short j=0; j<3; j++){
        if (j<2){
          cout << arr[i][j] << " ";
        }
        else{
          cout << arr[i][j] << endl;
        }
      }
    }
  }
};




int main (){
  int isDefault = -1;
  cout << "Welcome to Rogelio Macedo's 8-puzzle solver. \n";
  cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
  cout << "(Enter -1 to quit)\n\n";
  cin >> isDefault;
  if (isDefault == 1){
    cout << "You selected 1.\n";
  }
  else if (isDefault == 2){
    cout << "You selected 2.\n";
  }
  
  else if (isDefault == -1){
    cout << "Bye!\n";
    return 0;
  }
  
  
  /////////////NODE TESTING////////////
  cout << "printing default node n" << endl;
  node n; 
  n.print();
  
  
  // Node n;
  // n.x = 1;
  // cout << n.x << endl;
  //tested fact that struct datamembers can be referenced using dot operator
  
  // Node n(4);
  // cout << n.x << endl;
  //structs can have custom constructors
  
  ///////////END NODE TESTING///////////
  
  
  
  return 0;
}