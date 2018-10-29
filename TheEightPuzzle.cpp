#include <iostream>
#include <vector>
using namespace std;

//////////////////////UNIFORM COST SEARCH//////////////////////////////
/*
*/

//////////////////////A* with misplaced tile heuristic/////////////////
/*
*/
//////////////////////A* with manhatan distance heuristic//////////////





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
  
  return 0;
}