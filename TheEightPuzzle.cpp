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
};




int main (){
  
  int isDefault = -1;
    
  cout << "Welcome to Rogelio Macedo's 8-puzzle solver. \n";
  cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
  cout << "(Enter -1 to quit)\n\n";
  cin >> isDefault;
  while (isDefault != -1){
    if (isDefault == 1){
      cout << "You selected 1.\n";
    }
    else if (isDefault == 2){
      cout << "You selected 2.\n";
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
      node n;
      n.buildArray(a, b, c,
                    d, e, f, 
                    g, h, i);
      n.print();
    }
    
    else if (isDefault == -1){
      cout << "Bye!\n";
      return 0;
    }
   
    
    /////////////NODE TESTING////////////
    cout << "printing default node n" << endl;
    node n; 
    n.print();
    cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
    cout << "(Enter -1 to quit)\n\n";
    cin >> isDefault;
  }
  
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