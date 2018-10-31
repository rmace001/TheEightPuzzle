#include <iostream>
#include <vector>
using namespace std;

//////Three possible outcomes of search:
/////1. to report success
/////2. to report failure (which is actually a success)
/////3. to run until you run out of memory or time and kill the program 
/*
need to think of: 
-edge case: when a number is on the edge and you cant perform an operator (go_up(), down(), etc)
-unsigned shorts can be a value of 0 and if you subtract 1 from it, it warps around and gives you a very large positive number
-must think about a way to code my goal test
-There could be a chance that the problem resides in only figureing out how to add nodes to a queue
---That is, need to figure my heuristic function for A*
---This function should return the node with the cheapest cost
---
-Initial state
--given: 3x3 array
-Operators
--given: move blank up
          blank down
          blank left
          blank right
function generalSearch(EightPuzzle, UniformCostQueueing){
  -make the queue in the order we need for this, and induce the initial state
  a queue of arrays? 
  
  
}

what if whe had a struct node with a 4x4 array and an associted rank variable.
this rank is meant for the heuristic and therefore the queing function. 

*/


//////////////////////UNIFORM COST SEARCH//////////////////////////////
/*
*/



//////////////////////A* with misplaced tile heuristic/////////////////
/*
What I need is to:
 - build Heurisitc() function for misplaced tile
*/

//////////////////////A* with manhatan distance heuristic//////////////
/*
*/

struct Node {
  int x; 
  Node(int var){
    x = var;
  }
};





int main (){
  // int isDefault = -1;
  // cout << "Welcome to Rogelio Macedo's 8-puzzle solver. \n";
  // cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
  // cout << "(Enter -1 to quit)\n\n";
  // cin >> isDefault;
  // if (isDefault == 1){
  //   cout << "You selected 1.\n";
  // }
  // else if (isDefault == 2){
  //   cout << "You selected 2.\n";
  // }
  
  
  // else if (isDefault == -1){
  //   cout << "Bye!\n";
  //   return 0;
  // }
  
  /////////////NODE TESTING////////////
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