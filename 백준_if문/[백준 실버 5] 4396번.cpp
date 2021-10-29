#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;

const int Dx[] = {-1,-1,-1,0,0,1,1,1};
const int Dy[] = {-1,0,1,-1,1,-1,0,1};
int N;
vector<string> Clicks;
vector<string> Mines;
vector<vector<char>> Answer;
vector<pii> MinesCoords;

void check();

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		Mines.push_back(str);
	}

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		Clicks.push_back(str);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Mines[i][j] == '*') MinesCoords.push_back({i,j});
	 	}
	}

	check();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << Answer[i][j];
		}
		cout << '\n';
	}

	return 0;
}

void check() {
	Answer.assign(N, vector<char>(N));
	bool flag = false;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Clicks[i][j] == 'x' && Mines[i][j] == '*') {
				flag = true;
				continue;
			}
			if (Clicks[i][j] == 'x') {
				int cnt = 0;
				for (int d = 0; d < 8; ++d) {
					int nx = i + Dx[d];
					int ny = j + Dy[d];
					
					if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
					if (Mines[nx][ny] == '.') continue;
					++cnt;
				}
				Answer[i][j] = (cnt + '0');
			}
			else {
				Answer[i][j] = '.';
			}
		}
	}

	if (flag) {
		for (pii cur : MinesCoords) {
			Answer[cur.first][cur.second] = '*';
		}
	}
}