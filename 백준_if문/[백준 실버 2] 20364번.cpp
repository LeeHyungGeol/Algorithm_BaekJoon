// Ʈ��(����Ʈ��) ����, Set�� ��밡��

// ��� 2�� �����ٰ� �̹� �湮�� ��带 ������ ���� ���������� ���Ž����ش�.
// ������ 1���� �� ó�� �湮�� ��带 ����ϴ� ���̱� ������, ���� ���������� ���� �����ִ� ��
// �� �κ� ������ �ָ� �Ծ���.

// while���� �� ���� ������ ���� ���ŵ� ���� ���ٸ�, ó�� �湮�� ���̱� ������ Visited[cur] = true�� �����ϰ�, 0�� ����Ѵ�.
// ���� ���ŵǾ��ٸ�, ���ŵ� ���� ����Ѵ�.

// �� ������ Set�� �̿��ؼ��� Ǯ �� �ִ�.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, Q;
set<int> Set;
vector<bool> Visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	Visited.resize(N + 1, false);

	for (int i = 0; i < Q; ++i) {
		int cur;
		cin >> cur;
		int temp = 0;
		int j = cur;

		while (j) {
			if (Visited[j]) {
				temp = j;
			}
			j /= 2;
		}

		if (temp == 0) {
			Visited[cur] = true;
		}

		cout << temp << '\n';
	}
	
	return 0;
}