#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, x = 0, y = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
char directions[] = { 'U', 'D', 'L', 'R' };
string moves;

void move(char direction);

int main() {
	cin >> N;

	// 버퍼 비우기
	cin.ignore();
	getline(cin, moves);

	for (int i = 0; i < moves.size(); ++i) {
		move(moves[i]);
	}

	cout << x + 1 << ' ' << y + 1 << '\n';

	return 0;
}

void move(char direction) {
	// 함수로 뺐을 때 공백도 입력이 된다는 것을 주의하자!!
	if (direction == ' ') {
		return;
	}

	int nx = 0, ny = 0;

	for (int i = 0; i < 4; ++i) {
		if (direction == directions[i]) {
			nx = x + dx[i];
			ny = y + dy[i];
		}
	}

	if (0 <= nx && nx < N && 0 <= ny && ny < N) {
		x = nx;
		y = ny;
	}

	return;
}