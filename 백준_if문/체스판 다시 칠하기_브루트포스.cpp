#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char chessboard[51][51];
int checkRepaint(int x, int y);
int main() {

	vector<int> countrepaint;//다시 칠해야 하는 정사각형의 개수 저장
	int M, N;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			chessboard[i][j] = ' ';
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> chessboard[i][j];
		}
	}

	for (int i = 0; i < N - 7; ++i) {//8x8 정사각형이므로 입력받은 범위 전부를 탐색하는 것이 아닌 
		for (int j = 0; j < M - 7; ++j) {//저 범위(N-7, M-7) 안에 있는 맨 왼쪽 위의 칸부터 가로, 세로 8칸씩만 확인하면 된다.
			countrepaint.push_back(checkRepaint(i, j));
		}
	}
	sort(countrepaint.begin(), countrepaint.end());
	
	cout << countrepaint[0] << '\n';

	return 0;
}
int checkRepaint(int x, int y) {
	char firstcolor = chessboard[x][y], lastcolor = chessboard[x + 7][y + 7];

	vector<int> vectorcnt;
	int cnt = 0;

	for (int i = 0; i < 8; ++i) { 
		for (int j = 0; j < 8; ++j) {
			if (firstcolor == 'W') {
				if (i % 2 == 0 && j % 2 == 0) {
					if (chessboard[x + i][y + j] == 'W')
						continue;
					else
						cnt++;
				}
				else if (i % 2 == 1 && j % 2 == 1) {
					if (chessboard[x + i][y + j] == 'W')
						continue;
					else
						cnt++;
				}
				else {
					if (chessboard[x + i][y + j] == 'B')
						continue;
					else
						cnt++;
				}
			}
			else if (firstcolor == 'B') {
				if (i % 2 == 0 && j % 2 == 0) {
					if (chessboard[x + i][y + j] == 'B')
						continue;
					else
						cnt++;
				}
				else if (i % 2 == 1 && j % 2 == 1) {
					if (chessboard[x + i][y + j] == 'B')
						continue;
					else
						cnt++;
				}
				else {
					if (chessboard[x + i][y + j] == 'W')
						continue;
					else
						cnt++;
				}
			}
		}
		//cout << cnt << '\n';
	}
	//cout << cnt << '\n';
	vectorcnt.push_back(cnt);
	cnt = 0;
	for (int i = 7; i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			if (lastcolor == 'W') {
				if (i % 2 == 0 && j % 2 == 0) {
					if (chessboard[x + i][y + j] == 'W')
						continue;
					else
						cnt++;
				}
				else if (i % 2 == 1 && j % 2 == 1) {
					if (chessboard[x + i][y + j] == 'W')
						continue;
					else
						cnt++;
				}
				else {
					if (chessboard[x + i][y + j] == 'B')
						continue;
					else
						cnt++;
				}
			}
			else if (lastcolor == 'B') {
				if (i % 2 == 0 && j % 2 == 0) {
					if (chessboard[x + i][y + j] == 'B')
						continue;
					else
						cnt++;
				}
				else if (i % 2 == 1 && j % 2 == 1) {
					if (chessboard[x + i][y + j] == 'B')
						continue;
					else
						cnt++;
				}
				else {
					if (chessboard[x + i][y + j] == 'W')
						continue;
					else
						cnt++;
				}
			}
		}
		//cout << cnt << '\n';
	}
	//cout << cnt << '\n';
	vectorcnt.push_back(cnt);
	sort(vectorcnt.begin(), vectorcnt.end());

	return vectorcnt[0];
}
//8 8
//BBBBBBBB
//BBBBBBBB
//BBBBBBBB
//BBBBBBBB
//BBBBBBBB
//BBBBBBBB
//BBBBBBBB
//BBBBBBBW