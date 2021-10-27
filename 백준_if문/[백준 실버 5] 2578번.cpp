#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int x, y;
}Node;

int Answer;
int Arr[5][5];
Node Numbers[26];

bool isFinish();

int main() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> Arr[i][j];
			Numbers[Arr[i][j]] = { i,j };
		}
	}

	int i = 0;

	while (i < 25) {
		int n;
		cin >> n;
		Arr[Numbers[n].x][Numbers[n].y] = 0;
		++Answer;
		if (isFinish()) break;

		++i;
	}

	cout << Answer << '\n';

	return 0;
}

bool isFinish() {
	int total = 0;
	int diagnolLeft = 0, diagnolRight = 0;

	for (int i = 0; i < 5; ++i) {
		int cntRow = 0;
		for (int j = 0; j < 5; ++j) {
			if (Arr[i][j] == 0) ++cntRow;
			if (i == j && Arr[i][j] == 0) ++diagnolLeft;
			if (i + j == 4 && Arr[i][j] == 0) ++diagnolRight;
		}
		if (cntRow == 5) ++total;
	}

	if (diagnolLeft == 5) ++total;
	if (diagnolRight == 5) ++total;

	for (int j = 0; j < 5; ++j) {
		int cntCol = 0;
		for (int i = 0; i < 5; ++i) {
			if (Arr[i][j] == 0) ++cntCol;
		}
		if (cntCol == 5) ++total;
	}

	if (total >= 3) {
		return true;
	}
	else {
		return false;
	}
}