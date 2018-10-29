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
  int choice = -1;
  cout << "Welcome to Rogelio Macedo's 8-puzzle solver. \n";
  cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
  cin >> choice;
  if (choice == 1){
    cout << "yaaay you selected 1.\n";
  }
  else if (choice == 2){
    cout << "Okay, 2 was selected.\n";
  }
  
  return 0;
}