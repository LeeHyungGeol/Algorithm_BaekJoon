//분할 정복으로 행렬의 거듭제곱을 빠르게 계산하는 문제
//<빠른 거듭제곱 알고리즘> O(logN)
//N이 홀수이면 A ^ N을 A * A ^ (N - 1)로 바꾸고 A를 결과값에 곱한다
//N이 짝수이면 A ^ N을(A ^ 2) ^ (N / 2) 즉 A를 제곱하고 N을 2로 나눈다
//N = 0 이면 종료
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