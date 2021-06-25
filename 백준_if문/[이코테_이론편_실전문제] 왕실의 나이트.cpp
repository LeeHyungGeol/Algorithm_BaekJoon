#include <iostream>
#include <string>
using namespace std;

int answer;
int dx[] = { -2,-2, -1,1,2,2,1,-1 };
int dy[] = { -1, 1,2,2,1,-1,-2,-2 };
string str;

void countPossibleMoves(char y, char x);

int main() {
	cin >> str;

	countPossibleMoves(str[0], str[1]);

	cout << answer << '\n';

	return 0;
}

void countPossibleMoves(char y, char x) {
	int nx = 0, ny = 0, curX = y - 'a', curY = x - '1';

	for (int i = 0; i < 8; ++i) {
		nx = curX + dx[i];
		ny = curY + dy[i];
		if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
			++answer;
		}
	}

	return;
}