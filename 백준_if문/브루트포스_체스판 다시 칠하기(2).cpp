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

	for (int i = 0; i < N-7; ++i) {//8x8 정사각형이므로 입력받은 범위 전부를 탐색하는 것이 아닌 
		for (int j = 0; j < M-7; ++j) {//저 범위(N-7, M-7) 안에 있는 맨 왼쪽 위의 칸부터 가로, 세로 8칸씩만 확인하면 된다.
			countrepaint.push_back(checkRepaint(i, j));
		}
	}
	sort(countrepaint.begin(), countrepaint.end());//countrepaint 벡터 오름차순 정렬

	cout << countrepaint[0] << '\n';//countrepaint 벡터에 있는 수 중 최솟값을 출력

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