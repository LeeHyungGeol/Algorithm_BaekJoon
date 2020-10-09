#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char chessboard[51][51];
int checkRepaint(int x, int y);
int main() {

	vector<int> countrepaint;//�ٽ� ĥ�ؾ� �ϴ� ���簢���� ���� ����
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

	for (int i = 0; i < N - 7; ++i) {//8x8 ���簢���̹Ƿ� �Է¹��� ���� ���θ� Ž���ϴ� ���� �ƴ� 
		for (int j = 0; j < M - 7; ++j) {//�� ����(N-7, M-7) �ȿ� �ִ� �� ���� ���� ĭ���� ����, ���� 8ĭ���� Ȯ���ϸ� �ȴ�.
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