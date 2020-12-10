//https://suuntree.tistory.com/124
//https://seongjuk.tistory.com/entry/BOJ-1086%EB%B2%88-%EB%B0%95%EC%84%B1%EC%9B%90
//https://untouchable.tistory.com/76
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
typedef long long ll;
ll dp[1 << 15][101] = { 0 };
vector<string> arr(15);
vector<int> len(15);
vector<int> num(15);
vector<int> digit(51);
int N;// ������ ���� ���� N, N�� 15���� �۰ų� ���� �ڿ���
int K;// K�� 100���� �۰ų� ���� �ڿ���
ll factorial(int n);
ll func(int visited, int rest);
ll gcd(ll x, ll y);
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		len[i] = arr[i].size();
	}
	cin >> K;
	/////��ó��/////
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < len[i]; ++j) {
			num[i] = (num[i] * 10 + (arr[i][j] - '0')) % K;//��ȣ �ʼ�!!
		}
	}
	digit[0] = 1;
	for (int i = 1; i <= 50; ++i) {
		digit[i] = digit[i - 1] * 10 % K;
	}

	memset(dp, -1, sizeof(dp));
	ll p = func(0, 0);//����
	ll q = factorial(N);//�и�
	ll g = gcd(p, q);//�ִ�����
	if (p == 0) {
		cout << "0/1" << '\n';
		return 0;
	}
	cout << p / g << "/" << q / g << '\n';
	return 0;
}
ll func(int visited, int mod) {
	if ((1 << N) - 1 == visited) {
		if (mod == 0) return 1;
		else return 0;
	}

	//ll& ret = dp[visited][mod];
	if (dp[visited][mod] != -1)
		return dp[visited][mod];

	dp[visited][mod] = 0;
	for (int i = 0; i < N; ++i) {
		if (!(visited & (1 << i))) { // 0 <= mod < K //mod : ������
			int x = (mod * digit[len[i]] + num[i]) % K;
			dp[visited][mod] += func(visited | (1 << i), x);
		}
	}
	return dp[visited][mod];
}
ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}
ll factorial(int n) {
	ll result = 1;
	for (int i = 1; i <= n; ++i)
		result *= i;
	return result;
}