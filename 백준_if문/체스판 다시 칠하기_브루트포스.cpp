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
	int cntW = 0, cntB = 0;

	for (int i = 0; i < 8; ++i) { 
		for (int j = 0; j < 8; ++j) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (chessboard[x + i][y + j] == 'W')
					continue;
				else
					cntW++;
			}
			else if (i % 2 == 1 && j % 2 == 1) {
				if (chessboard[x + i][y + j] == 'W')
					continue;
				else
					cntW++;
			}
			else {
				if (chessboard[x + i][y + j] == 'B')
					continue;
				else
					cntW++;
			}
		}
		//cout << cnt << '\n';
	}
	//cout << cnt << '\n';
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (chessboard[x + i][y + j] == 'B')
					continue;
				else
					cntB++;
			}
			else if (i % 2 == 1 && j % 2 == 1) {
				if (chessboard[x + i][y + j] == 'B')
					continue;
				else		
					cntB++;
			}
			else {
				if (chessboard[x + i][y + j] == 'W')
					continue;
				else	
					cntB++;		
			}
		}
	}
	
	if (cntW > cntB)
		return cntB;
	else
		return cntW;
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