// DFS ����, �̰� ���� ��� �Լ��� �̿��ϹǷ� , DFS ������� �� �� �ִ�.
// ��� ����� ���� ����ϱ� ���Ͽ�(���� Ž��) DFS�� �̿��Ͽ� ������ �ذ��� �� �ִ�.
// �� ��Ģ ������ �ߺ����� ����� �� �ֱ� ������, ������ Ǯ�� ���ؼ��� �ߺ� ������ ����ؾ� �Ѵ�.

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