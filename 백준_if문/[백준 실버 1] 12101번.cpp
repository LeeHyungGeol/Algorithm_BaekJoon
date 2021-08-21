// 백트랙킹, dfs, 조합, 브루트포스

// [백준 골드 5] 감시(15682번) 문제 에서 각도(angles[i])의 조합을 구현하는 방법과 똑같다.
// 조합을 구현하는 방법을 잘 기억해두자!!

#include <iostream>
#include <vector>

using namespace std;

int N, K, Count;
vector<int> Arr;

void dfs(int sum);

int main() {
	cin >> N >> K;

	dfs(0);

	if (Count == 0 || Count < K) {
		cout << "-1" << '\n';
	}

	return 0;
}

void dfs(int sum) {
	if (sum > N) {
		return;
	}
	if (sum == N) {
		++Count;
		if (Count == K) {
			for (int i = 0; i < Arr.size() - 1; ++i) {
				cout << Arr[i] << "+";
			}
			cout << Arr[(int)Arr.size() - 1] << '\n';
		}
		return;
	}

	for (int i = 1; i <= 3; ++i) {
		Arr.push_back(i);
		dfs(sum + i);
		Arr.pop_back();
	}
}