#include <iostream>
#include <vector>
using namespace std;
//�� ���� ��� ĭ���� 
//�ִ��� �����ϸ鼭 ���� ��ȹ������ Ǫ�� ����
int MAX[501] = { 0 };
int N;
int integerTriangle(int sum, int** arr);

int main() {

	int sum = 0;
	cin >> N;
	int** arr = new int* [N + 1];
	for (int i = 1; i <= N; ++i) {
		arr[i] = new int[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> arr[i][j];
		}
	}

	if (N == 1) {
		cout << arr[1][1] << '\n';
		return 0;
	}
	for (int i = 1; i <= N; ++i) {
		MAX[N]=
	}
	/*for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}*/
	return 0;
}
int integerTriangle(int sum, int **arr) {
	if (N == 1) {
		return sum = arr[1][1];
	}
}