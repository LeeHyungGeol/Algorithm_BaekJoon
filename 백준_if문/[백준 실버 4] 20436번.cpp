#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef struct Node {
	int x, y;
}Node;

int Answer;
Node Left, Right;
string Str;
map<char, Node> Map;

void initMap();
int getDist(Node a, Node b);

int main() {
	initMap();

	char left, right;
	cin >> left >> right;
	cin >> Str;

	Left = Map[left], Right = Map[right];

	for (char c : Str) {
		Node cur = Map[c];
		if (cur.x == 2 && cur.y == 4) {
			Answer += getDist(cur, Right);
			Right = cur;
		}
		else if (cur.y < 5) {
			Answer += getDist(cur, Left);
			Left = cur;
		}
		else {
			Answer += getDist(cur, Right);
			Right = cur;
		}
		++Answer;
	}

	cout << Answer << '\n';

	return 0;
}

int getDist(Node a, Node b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void initMap() {
	Map['q'] = { 0,0 };
	Map['w'] = { 0,1 };
	Map['e'] = { 0,2 };
	Map['r'] = { 0,3 };
	Map['t'] = { 0,4 };
	Map['a'] = { 1,0 };
	Map['s'] = { 1,1 };
	Map['d'] = { 1,2 };
	Map['f'] = { 1,3 };
	Map['g'] = { 1,4 };
	Map['z'] = { 2,0 };
	Map['x'] = { 2,1 };
	Map['c'] = { 2,2 };
	Map['v'] = { 2,3 };

	Map['y'] = { 0,5 };
	Map['u'] = { 0,6 };
	Map['i'] = { 0,7 };
	Map['o'] = { 0,8 };
	Map['p'] = { 0,9 };
	Map['h'] = { 1,5 };
	Map['j'] = { 1,6 };
	Map['k'] = { 1,7 };
	Map['l'] = { 1,8 };
	Map['b'] = { 2,4 };
	Map['n'] = { 2,5 };
	Map['m'] = { 2,6 };
}