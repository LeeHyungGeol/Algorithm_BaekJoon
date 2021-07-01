// ����(����) ����
// dfs�� �̿��� ���� ������ nCm�� �����ϴ� ��������.
// ��ǻ� ������ ������ �� �� �˸�, �Ÿ� ���ϴ� ���� �״��� ����� ���� ��������.

// �ٸ�, ������ ���� ��, ������ void �� �����ϴ� ���� �������!!

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1e9

using namespace std;

typedef pair<int, int> pii;

int N, M, answer = MAX;
int arr[50][50] = { 0, };
vector<pii> houses;
vector<pii> chickens;
vector<bool> Select;
void dfs(int startIndex, int cnt);
int getDistance(const pii& a, const pii& b);

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				houses.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				chickens.push_back({ i,j });
			}
		}
	}

	Select.resize(chickens.size());

	dfs(0, 0);

	cout << answer << '\n';

	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt == M) {
		vector<pii> selcetedChickens;

		for (int i = 0; i < chickens.size(); ++i) {
			if (Select[i]) {
				selcetedChickens.push_back(chickens[i]);
			}
		}
		
		int sum = 0;

		for (auto house : houses) {
			int d = MAX;
			for (auto selected : selcetedChickens) {
				d = min(d, getDistance(house, selected));
			}
			sum += d;
		}

		answer = min(answer, sum);

		return;
	}

	for (int i = startIndex; i < Select.size(); ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

int getDistance(const pii& a, const pii& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}