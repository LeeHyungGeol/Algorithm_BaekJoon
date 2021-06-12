// DFS 문제, 이것 역시 재귀 함수를 이용하므로 , DFS 문제라고 할 수 있다.
// 모든 경우의 수를 계산하기 위하여(완전 탐색) DFS를 이용하여 문제를 해결할 수 있다.
// 각 사칙 연산을 중복으로 사용할 수 있기 때문에, 문제를 풀기 위해서는 중복 순열을 계산해야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1e9;

int N, add, sub, mul, divide;
int minValue = MAX;
int maxValue = -MAX;
vector<int> arr;

void dfs(int index, int total);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> add >> sub >> mul >> divide;

	dfs(1, arr[0]);

	cout << maxValue << '\n' << minValue << '\n';

	return 0;
}

void dfs(int index, int total) {
	if (index == N) {
		maxValue = max(maxValue, total);
		minValue= min(minValue, total);
		return;
	}

	if (add > 0) {
		--add;
		total += arr[index];
		dfs(index + 1, total);
		++add;
		total -= arr[index];
	}

	if (sub > 0) {
		--sub;
		total -= arr[index];
		dfs(index + 1, total);
		++sub;
		total += arr[index];
	}

	if (mul > 0) {
		--mul;
		total *= arr[index];
		dfs(index + 1, total);
		++mul;
		total /= arr[index];
	}

	if (divide > 0) {
		--divide;
		total /= arr[index];
		dfs(index + 1, total);
		++divide;
		total *= arr[index];
	}

}