// ��Ʈ��ŷ, dfs, ����, ���Ʈ����

// [���� ��� 5] ����(15682��) ���� ���� ����(angles[i])�� ������ �����ϴ� ����� �Ȱ���.
// ������ �����ϴ� ����� �� ����ص���!!

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