//���� �������� ����� �ŵ������� ������ ����ϴ� ����
//<���� �ŵ����� �˰���> O(logN)
//N�� Ȧ���̸� A ^ N�� A * A ^ (N - 1)�� �ٲٰ� A�� ������� ���Ѵ�
//N�� ¦���̸� A ^ N��(A ^ 2) ^ (N / 2) �� A�� �����ϰ� N�� 2�� ������
//N = 0 �̸� ����
#include <iostream>
using namespace std;
#define mod 1000
int N;
long long B, arr[6][6] = { 0 }, answer[6][6] = { 0 };
void divideAndConquer(long long arr1[6][6], long long arr2[6][6]);

int main() {

	cin >> N >> B;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
		answer[i][i] = 1;
	}
	while (B > 0) {
		if (B % 2 == 1) 
			divideAndConquer(answer, arr);
		divideAndConquer(arr, arr);
		B /= 2;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
void divideAndConquer(long long arr1[6][6], long long arr2[6][6]) {
	long long tmp[6][6] = { 0 };
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				tmp[i][k] += arr1[i][j] * arr2[j][k];
				tmp[i][k] %= mod;
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			arr1[i][j] = tmp[i][j];
		}
	}

}