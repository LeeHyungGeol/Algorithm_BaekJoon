#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char realchess1[8][8] = { 
				{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' }, { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
				{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' }, { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
				{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' }, { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
				{ 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' }, { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' } };

char realchess2[8][8] = { 
		{ 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' }, { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
		{ 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' }, { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
		{ 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' }, { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
		{ 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' }, { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' } };

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

	for (int i = 0; i < N-7; ++i) {//8x8 ���簢���̹Ƿ� �Է¹��� ���� ���θ� Ž���ϴ� ���� �ƴ� 
		for (int j = 0; j < M-7; ++j) {//�� ����(N-7, M-7) �ȿ� �ִ� �� ���� ���� ĭ���� ����, ���� 8ĭ���� Ȯ���ϸ� �ȴ�.
			countrepaint.push_back(checkRepaint(i, j));
		}
	}
	sort(countrepaint.begin(), countrepaint.end());//countrepaint ���� �������� ����

	cout << countrepaint[0] << '\n';//countrepaint ���Ϳ� �ִ� �� �� �ּڰ��� ���

	return 0;
}
int checkRepaint(int x, int y) {
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (chessboard[x + i][y + j] == realchess1[i][j])
				continue;
			else
				cnt1++;
		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (chessboard[x + i][y + j] == realchess2[i][j])
				continue;
			else
				cnt2++;
		}
	}

	if (cnt1 > cnt2)
		return cnt2;
	else
		return cnt1;
}