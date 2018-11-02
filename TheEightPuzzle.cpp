#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdlib>
using namespace std;


unsigned short solved[3][3]= {{1,2,3},{4,5,6},{7,8,0}};

//////Three possible outcomes of search:
/////1. to report success
/////2. to report failure (which is actually a success)
/////3. to run until you run out of memory or time and kill the program 


//How do I define how my priority queue orders my nodes? what defines priority for the node class? 
//////might need to overload both the < and > operators, since this is needed for the priority queue
//////also might need to add some sort of hueristic data member as part of the node class for priority queue comparison
//////need to have my operators update the node's heuristic data member


//Node Definition
struct node
{
  unsigned short arr[3][3];
  unsigned short weight = 1; 
  unsigned int heuristic = 0; //must have a function to calculate this 
  node(){} //default constructor
  ~node(){}
  node(const node& n)
  { //copy constructor
    weight = n.weight;
    heuristic = n.heuristic;
    for (short i=0; i<3; i++){
      for (short j=0; j<3; j++){
        arr[i][j] = n.arr[i][j];
      }
    }
  }
  
  void print()
  {
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
  
  
  void buildArray(unsigned short a, unsigned short b, unsigned short c,
                  unsigned short d, unsigned short e, unsigned short f,
                  unsigned short g, unsigned short h, unsigned short i)
  {
    arr[0][0] = a;
    arr[0][1] = b;
    arr[0][2] = c;
    arr[1][0] = d;
    arr[1][1] = e;
    arr[1][2] = f;
    arr[2][0] = g;
    arr[2][1] = h;
    arr[2][2] = i;
  }
  
  bool operator < (const node rhs) const 
  { 
    return (heuristic > rhs.heuristic);
  }
  node & operator= (const node &rhs)
  {
    if (this != &rhs)
    {
      heuristic = rhs.heuristic;
      for (short i=0; i<3; i++){
        for (short j=0; j<3; j++){
        arr[i][j] = rhs.arr[i][j];
        }
      }
      
    }
    return *this;
  }
};




///////////////////////////////////////////////////////////////////////////////
///////////////////////Helper Function Delcarations////////////////////////////
bool goalTest(node* n);
void buildPuzzle(node* n);
void buildDefault(node* n);
bool UniformCostSearch(node* n);
void queingFunction(priority_queue<node*>& q, node* currNode);
void findBlank(node* currNode, unsigned short& row, unsigned short& col);
void UP(unsigned short& row, unsigned short& col, node* n);
//////////////////////End Helper Declarations//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool goalTest(node* n)
{
  for (short i=0; i<3; i++){
    for (short j=0; j<3; j++){
      if (solved[i][j] != n->arr[i][j]){
          return false;
      }
    }
  }
  return true;
}
void buildPuzzle(node* n)
{
  unsigned short a, b, c, d, e, f, g, h, i;
  cout << "Enter each element of the puzzle separately," << endl;
  cout << "and the number 0 as the blank space." << endl;
  cout << "\"Error\" prints if value entered is not a number" << endl;
  cin >> a;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> a;
  }
  cin >> b;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> b;
  }
  cin >> c;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> c;
  }
  cin >> d;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> d;
  }
  cin >> e;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> e;
  }
  cin >> f;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> f;
  }
  cin >> g;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> g;
  }
  cin >> h;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> h;
  }
  cin >> i;
  while(cin.fail()) {
    cout << "Error" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> i;
  }
  n->buildArray(a, b, c,
                    d, e, f, 
                    g, h, i);
}
void buildDefault(node* n)
{
  n->buildArray(1, 2, 0, 4, 5, 3, 7, 8, 6);
}
bool UniformCostSearch(node* n)
{
  priority_queue<node*>  q;
  node* currNode;
  q.push(n); //add initial state to the queue
  while(!q.empty()){
    currNode = q.top();
    q.pop(); //pop the top element
    if(goalTest(currNode)){
      n = currNode;
      return true; 
    }
    else{
      queingFunction(q, currNode);
    }
    
  }
  
  
  
  return false;
}


void queingFunction(priority_queue<node*>& q, node* currNode){
  bool flagUp = true, flagDown = true, flagLeft = true, flagRight = true; 
  unsigned short row, col;
  findBlank(currNode, row, col);
  if (row == 0){
    flagUp = false;
    if (col == 0){
      flagLeft = false;
    }
    else if(col == 2){
      flagRight = false;
    }
  }
  else if (row == 1){
    if (col == 0){
      flagLeft = false;
    }
    else if (col == 2){
      flagRight = false;
    }
  }
  else if (row == 2){
    flagDown = false;
    if (col == 0){
      flagLeft = false;
    }
    else if (col == 2){
      flagRight = false;
    }
  }
  if (flagUp){
    node* n = new node(*currNode);
    //UP(row, col, n);
  }
  if (flagDown){
    
  }
  if (flagLeft){
    
  }
  if (flagRight){
    
  }
}

void findBlank(node* currNode, unsigned short& row, unsigned short& col)
{
  for (short i=0; i<3; i++){
    for (short j=0; j<3; j++){
      if (currNode->arr[i][j] == 0){
        row = i;
        col = j;
        return;
      }
    }
  }
}

void UP(unsigned short& row, unsigned short& col, node* n)
{
  unsigned short temp = n->arr[row-1][col];//store above element
  n->arr[row-1][col] = 0; //move blank up
  n->arr[row][col] = temp;//move element down
}




int main (){
  
  int isDefault = -1;
  node* n = new node();
    
  cout << "Welcome to Rogelio Macedo's 8-puzzle solver. \n";
  cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
  cout << "(Enter -1 to quit)\n\n";
  cin >> isDefault;
  while (isDefault != -1){
    if (isDefault == 1){
      cout << "You selected 1.\n";
      buildDefault(n);
      n->print();
    }
    else if (isDefault == 2){
      cout << "You selected 2.\n";
      buildPuzzle(n);
      n->print();
      
    }
    else if (isDefault == -1){
      cout << "Bye!\n";
      return 0;
    }
    cout << endl;
    node x(*n);
    x.print();
    
    if(UniformCostSearch(n))
      n->print();
    else
      cout << "Failure, there is no solution found." << endl;
    cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
    cout << "(Enter -1 to quit)\n\n";
    cin >> isDefault;
  }
  
  return 0;
}