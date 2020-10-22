#include <iostream>
using namespace std;

int N; //(1 ≤ N < 15)
int arr[15] = { 0 };
int cnt = 0;
void backtracking(int x);
bool isPossible(int row);
// row: 행, column: 열

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int col = 1; col <= N; ++col) {//1열부터 N열까지 차례대로 해본다.
		arr[1] = col; //1행, col열
		backtracking(2); //2행부터 dfs시작
	}
	cout << cnt << '\n';
	
	return 0;
}
void backtracking(int row) {
	if (row > N) {//row(행)이 N을 넘어섰을 때(N + 1 일 때), 모든 행에 하나씩 Queen이 놓아져 있는 상태이기 때문에
		cnt++;
		return;
	}
	else {
		for (int col = 1; col <= N; ++col) {//1열부터 N열까지 차례대로 조건에 맞는지 넣어 본다.
			arr[row] = col;
			if (isPossible(row))
				backtracking(row + 1);
		}
	}
}
bool isPossible(int row) {
	for (int r = 1; r < row; ++r) {//행은 항상 +1을 해줬기 때문에 조건에서 제외
		if (arr[r] == arr[row])//이전의 Queen이 같은 열에 있으면 false
			return false;
		if (abs(arr[r] - arr[row]) == abs(r - row))//이전의 Queen이 같은 대각선에 있으면 false
			return false;
	}
	return true; //조건을 모두 충족할 경우 true
}

