#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;




struct node
{
	unsigned short arr[3][3];
	unsigned short weight;
	unsigned int heuristic; //must have a function to calculate this 
	node() : weight(0), heuristic(0) {} //default constructor,                     MAY NEED TO RETURN A CONST OBJECT
	~node() {}
	
	node(const node& n)
	{ //copy constructor
		weight = n.weight;
		heuristic = n.heuristic;
		for (short i = 0; i<3; i++) {
			for (short j = 0; j<3; j++) {
				arr[i][j] = n.arr[i][j];
			}
		}
	}

	void print()
	{
		for (short i = 0; i<3; i++) {
			for (short j = 0; j<3; j++) {
				if (j<2) {
					cout << arr[i][j] << " ";
				}
				else {
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
/*
	bool operator < (const node rhs) const
	{
		return ((weight+heuristic) < (rhs.weight+rhs.heuristic));
	}
	bool operator > (const node rhs) const
	{
		return ((weight + heuristic) > (rhs.weight + rhs.heuristic));
	}
	*/
	node & operator= (const node &rhs)
	{
		if (this != &rhs)
		{
			heuristic = rhs.heuristic;
			weight = rhs.weight;
			for (short i = 0; i<3; i++) {
				for (short j = 0; j<3; j++) {
					arr[i][j] = rhs.arr[i][j];
				}
			}

		}
		return *this;
	}
};

struct compare
{
	bool operator() (const node* l, const node* r) const
	{
		return (l->weight + l->heuristic) > (r->weight + r->heuristic);
	}
};

unsigned short solved[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };
vector<string> repeated;
int maxQsize = 0;	//reset these when I reset the vector
int numExpand = 0; //reset these when I reset the vector


///////////////////////////////////////////////////////////////////////////////
///////////////////////Helper Function Delcarations////////////////////////////
bool goalTest(node* n);
void buildPuzzle(node*& n);
void buildDefault(node*& n);
bool UniformCostSearch(node*& n, node*& goal, int choice);
void queingFunction(priority_queue<node*, vector<node*>, compare >& q, node*& currNode, int choice);
void findBlank(node* currNode, unsigned short& row, unsigned short& col);
void UP(unsigned short& row, unsigned short& col, node*& n);
void DOWN(unsigned short& row, unsigned short& col, node*& n);
void LEFT(unsigned short& row, unsigned short& col, node*& n);
void RIGHT(unsigned short& row, unsigned short& col, node*& n);
unsigned short misplacedTile(node*& n);
unsigned short manhattanDist(node*& n);
void targetCoord(unsigned short& val, unsigned short& x, unsigned short& y);
void addInstance(node*& n);
string makeString(node*& n);
unsigned short Heuristic(node*& n, int choice);
//////////////////////End Helper Declarations//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





bool goalTest(node* n)
{
	for (short i = 0; i<3; i++) {
		for (short j = 0; j<3; j++) {
			if (solved[i][j] != n->arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void buildPuzzle(node*& n)
{
	unsigned short a, b, c, d, e, f, g, h, i;
	cout << "Enter each element of the puzzle separately," << endl;
	cout << "and the number 0 as the blank space." << endl;
	cout << "\"Error\" prints if value entered is not a number" << endl;
	cin >> a;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> a;
	}
	cin >> b;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> b;
	}
	cin >> c;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> c;
	}
	cin >> d;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> d;
	}
	cin >> e;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> e;
	}
	cin >> f;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> f;
	}
	cin >> g;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> g;
	}
	cin >> h;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> h;
	}
	cin >> i;
	while (cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> i;
	}
	n->buildArray(a, b, c, d, e, f, g, h, i);
}
void buildDefault(node*& n)
{
	//n->buildArray(1, 2, 0, 4, 5, 3, 7, 8, 6); //easy
	//n->buildArray(8, 7, 1, 6, 0, 2, 5, 4, 3); //oh boy
	n->buildArray(1, 2, 3, 4, 5, 6, 7, 0, 8); //very easy
}
bool UniformCostSearch(node*& n, node*& goal, int choice) //bool UniformCostSearch(node*& n, node*& goal, int choice)
{
	priority_queue<node*, vector<node*>, compare >  q;
	node* currNode;
	q.push(n); //add initial state to the queue
	while (!q.empty()) {
		currNode = q.top();
		cout << "The Best state to expand when g(n) = " << currNode->weight;
		cout << " and h(n) = " << currNode->heuristic  << " is..." << endl;
		currNode->print();
		addInstance(currNode);
		maxQsize = maxQsize > q.size() ? maxQsize : q.size();
		q.pop(); //pop the top element
		if (goalTest(currNode)) {
			goal = currNode;
			return true;
		}
		else {
			numExpand++;
			queingFunction(q, currNode, choice);
		}
	}
	return false;
}


void queingFunction(priority_queue<node*, vector<node*>, compare >& q, node*& currNode, int choice)
{
	bool flagUp = true, flagDown = true, flagLeft = true, flagRight = true;
	unsigned short row, col;
	findBlank(currNode, row, col);
	cout << "Row, Col: " << row << ',' << col << endl;
	if (row == 0) {
		flagUp = false;
		if (col == 0) {
			flagLeft = false;
		}
		else if (col == 2) {
			flagRight = false;
		}
	}
	else if (row == 1) {
		if (col == 0) {
			flagLeft = false;
		}
		else if (col == 2) {
			flagRight = false;
		}
	}
	else if (row == 2) {
		flagDown = false;
		if (col == 0) {
			flagLeft = false;
		}
		else if (col == 2) {
			flagRight = false;
		}
	}

	if (flagUp) {
		node* n = new node(*currNode);
		UP(row, col, n);
		n->weight = (currNode->weight + 1);
		unsigned short heuristic = Heuristic(n, choice);
		n->heuristic = heuristic;
		string s = makeString(n);
		if (!(find(repeated.begin(), repeated.end(), s) != repeated.end())) {
			q.push(n);
		}
	}

	if (flagDown) {
		node* n = new node(*currNode);
		DOWN(row, col, n);
		n->weight = (currNode->weight + 1);
		unsigned short heuristic = Heuristic(n, choice);
		n->heuristic = heuristic;
		string s = makeString(n);
		if (!(find(repeated.begin(), repeated.end(), s) != repeated.end())) {
			q.push(n);
		}
	}

	if (flagLeft) {
		node* n = new node(*currNode);
		LEFT(row, col, n);
		n->weight = (currNode->weight + 1);
		unsigned short heuristic = Heuristic(n, choice);
		n->heuristic = heuristic;
		string s = makeString(n);
		if (!(find(repeated.begin(), repeated.end(), s) != repeated.end())) {
			q.push(n);
		}
	}
	
	if (flagRight) {
		node* n = new node(*currNode);
		RIGHT(row, col, n);
		n->weight = (currNode->weight + 1);
		unsigned short heuristic = Heuristic(n, choice);
		n->heuristic = heuristic;
		string s = makeString(n);
		if (!(find(repeated.begin(), repeated.end(), s) != repeated.end())) {
			q.push(n);
		}
	}
	
	
}

void findBlank(node* currNode, unsigned short& row, unsigned short& col)
{
	for (short i = 0; i<3; i++) {
		for (short j = 0; j<3; j++) {
			if (currNode->arr[i][j] == 0) {
				row = i;
				col = j;
				return;
			}
		}
	}
}

void UP(unsigned short& row, unsigned short& col, node*& n)
{
	unsigned short temp = n->arr[row - 1][col];//store above element
	n->arr[row - 1][col] = 0; //move blank up
	n->arr[row][col] = temp;//move element down
}

void DOWN(unsigned short& row, unsigned short& col, node*& n)
{
	unsigned short temp = n->arr[row + 1][col];//store above element
	n->arr[row + 1][col] = 0; //move blank up
	n->arr[row][col] = temp;//move element down
}

void LEFT(unsigned short& row, unsigned short& col, node*& n)
{
	unsigned short temp = n->arr[row][col - 1];//store above element
	n->arr[row][col - 1] = 0; //move blank up
	n->arr[row][col] = temp;//move element down
}

void RIGHT(unsigned short& row, unsigned short& col, node*& n)
{
	unsigned short temp = n->arr[row][col + 1];//store above element
	n->arr[row][col + 1] = 0; //move blank up
	n->arr[row][col] = temp;//move element down
}



unsigned short misplacedTile(node*& n)
{
	unsigned short count = 0;
	for (unsigned short i = 0; i<3; i++) {
		for (unsigned short j = 0; j<3; j++) {
			if (i==2 && j==2){
				return count;
			}
			else if (n->arr[i][j] != solved[i][j]) {
				count++;
			}
		}
	}
	return count;
}

unsigned short manhattanDist(node*& n)
{
	unsigned short x, y, total=0;

	for (unsigned short i = 0; i<3; i++) {
		for (unsigned short j = 0; j<3; j++) {
			if (n->arr[i][j] != 0) {
				targetCoord(n->arr[i][j], x, y);
				total += abs(i-x);
				total += abs(j-y);
			}
		}
	}
	return total;
}
unsigned short Heuristic(node*& n, int choice)
{
	if (choice == 1){
		//choice uniform cost search
		return 0;
	}
	else if (choice == 2){
		//choice for misplaced tile heuristic
		return misplacedTile(n);
		
	}
	else{
		//choice for mahattan distance heuristic
		return manhattanDist(n);
	}
}




void targetCoord(unsigned short& val, unsigned short& x, unsigned short& y)
{
	switch (val) {
	case 1:
		x = 0;
		y = 0;
		break;
	case 2:
		x = 0;
		y = 1;
		break;
	case 3:
		x = 0;
		y = 2;
		break;
	case 4:
		x = 1;
		y = 0;
		break;
	case 5:
		x = 1;
		y = 1;
		break;
	case 6:
		x = 1;
		y = 2;
		break;
	case 7:
		x = 2;
		y = 0;
		break;
	case 8:
		x = 2;
		y = 1;
		break;
	}
}


void addInstance(node*& n)
{
	string s = "";
	for (unsigned short i = 0; i<3; i++) {
		for (unsigned short j = 0; j<3; j++) {
			s += to_string(n->arr[i][j]);
		}
	}
	repeated.push_back(s);
}

string makeString(node*& n)
{
	string s = "";
	for (unsigned short i = 0; i<3; i++) {
		for (unsigned short j = 0; j<3; j++) {
			s += to_string(n->arr[i][j]);
		}
	}
	return s;
}

int main() 
{

	int isDefault = -1;
	int pickSearch = -1;
	//node* n = new node(); putting this line under while(), and adding delete call at end of while()
	node* n = new node();
	node * goal = new node();
	cout << "Welcome to Rogelio Macedo's 8-puzzle solver. \n";
	cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";
	cout << "(Enter -1 to quit)\n\n";
	cin >> isDefault;
	while (isDefault != -1) {
		if (isDefault == 1) {
			cout << "You selected 1.\n";
			buildDefault(n);
		}
		else if (isDefault == 2) {
			cout << "You selected 2.\n";
			buildPuzzle(n);
		}
		
		cout << "Enter your choice of algorithm \n";
		cout << "		1. Uniform Cost Search \n";
		cout << "		2. A* with Misplaced Tile heuristic \n";
		cout << "		3. A* with Manhattan heuristic \n";
		cin >> pickSearch;
		
		
		
		if (isDefault == -1) {
			cout << "Bye!\n";
			return 0;
		}
		cout << endl;
		if (UniformCostSearch(n, goal, pickSearch)) {
			//goal->print();
			cout << "Goal!" << endl;
			cout << "To solve this problem the search algorithm expanded a total of ";
			cout << numExpand << " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time was ";
			cout << maxQsize << "." << endl;
			cout << "The depth of the goal node was " << goal->weight << "." << endl;
			
		}
		else {
			cout << "Failure, there is no solution found." << endl;
		}
		repeated.clear(); //clear all elements from vector to reinitiate search algorithm
		maxQsize = 0;
		numExpand = 0;
		cout << "Enter \"1\" to use a default puzzle, or \"2\" to enter your own puzzle \n";

		cout << "(Enter -1 to quit)\n\n";
		cin >> isDefault;
	}

	return 0;
}