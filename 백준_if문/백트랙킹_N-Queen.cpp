#include <iostream>
using namespace std;

int N; //(1 �� N < 15)
int arr[15] = { 0 };
int cnt = 0;
void backtracking(int x);
bool isPossible(int row);
// row: ��, column: ��

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int col = 1; col <= N; ++col) {//1������ N������ ���ʴ�� �غ���.
		arr[1] = col; //1��, col��
		backtracking(2); //2����� dfs����
	}
	cout << cnt << '\n';
	
	return 0;
}
void backtracking(int row) {
	if (row > N) {//row(��)�� N�� �Ѿ�� ��(N + 1 �� ��), ��� �࿡ �ϳ��� Queen�� ������ �ִ� �����̱� ������
		cnt++;
		return;
	}
	else {
		for (int col = 1; col <= N; ++col) {//1������ N������ ���ʴ�� ���ǿ� �´��� �־� ����.
			arr[row] = col;
			if (isPossible(row))
				backtracking(row + 1);
		}
	}
}
bool isPossible(int row) {
	for (int r = 1; r < row; ++r) {//���� �׻� +1�� ����� ������ ���ǿ��� ����
		if (arr[r] == arr[row])//������ Queen�� ���� ���� ������ false
			return false;
		if (abs(arr[r] - arr[row]) == abs(r - row))//������ Queen�� ���� �밢���� ������ false
			return false;
	}
	return true; //������ ��� ������ ��� true
}

