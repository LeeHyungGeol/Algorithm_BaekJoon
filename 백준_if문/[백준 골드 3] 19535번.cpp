// Ʈ��, dfs, ���շ�
// ��ư� �򰥸��� ��������.
// D-Ʈ���� ���, G-Ʈ���� ��츦 �� ������� �Ѵ�.
// G-Ʈ���� ��� : �ش� ����� �ڽ� ������ 3�� �̻��� ��, nC3 ���� ������ �����Ѵ�.
// D-Ʈ���� ��� : �ش� ����� �ڽ� ������ �ڽ� �����  �ڽ� �������� ���� 1�� �� ���� ���Ѵ�.
// G-Ʈ�� ���� ���� : 1. Tree�� ���������� �������� �ϹǷ�, next�� cur�� �� ���� Ŀ�� �Ѵ�. 2. �ڽİ����� 2 �̻��̾�� �Ѵ�.

// N�� ������ 30�� ���� �̹Ƿ� overflow�� �߻��� �� �����Ƿ�, long long Ÿ������ ������ش�.

// ���� : https://bba-dda.tistory.com/entry/%EB%B0%B1%EC%A4%80C-19535-%E3%84%B7%E3%84%B7%E3%84%B7%E3%85%88
// https://howtolivelikehuman.tistory.com/239
// https://lovelyunsh.tistory.com/11

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
ll D = 0, G = 0;
vector<ll> ChildCount;
vector<pii> Nodes;
vector<vector<int>> Tree;

void treeD();
void treeG();
void findD();
void findG();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	Tree.resize(N + 1);
	ChildCount.resize(N + 1, 0);

	for (int i = 0; i < N-1; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
		Nodes.push_back({ a,b });
		
		++ChildCount[a];
		++ChildCount[b];
	}

	//treeD();
	//treeG();

	findD();
	findG();

	// cout << "D : " << D << '\n';
	// cout << "G : " << G << '\n';

	if (D > 3 * G) {
		cout << "D" << '\n';
	}
	else if (D < 3 * G) {
		cout << "G" << '\n';
	}
	else {
		cout << "DUDUDUNGA" << '\n';
	}

	return 0;
}

void treeD() {
	for (int i = 0; i < Nodes.size(); ++i) {
		int a = Nodes[i].first;
		int b = Nodes[i].second;
		D += (ChildCount[a] - 1) * (ChildCount[b] - 1);
	}

	return;
}

void treeG() {
	for (int i = 1; i <= N; ++i) {
		ll curChild = ChildCount[i];
		if (curChild >= 3) {
			G += (curChild * (curChild - 1) * (curChild - 2)) / 6;
		}
	}

	return;
}

void findG() {
	for (int i = 1; i <= N; ++i) {
		if (Tree[i].size() >= 3) {
			ll cnt = Tree[i].size();
			G += cnt * (cnt - 1) * (cnt - 2) / 6;
		}
	}
	return;
}

void findD() {
	for (int i = 1; i <= N; ++i) {
		if (Tree[i].size() >= 2) {
			for (int j = 0; j < Tree[i].size(); ++j) {
				int next = Tree[i][j];
				if (next > i) {
					if (Tree[next].size() >= 2) {
						D += ((ll)Tree[i].size() - 1) * ((ll)Tree[next].size() - 1);
					}
				}
			}
		}
	}
	return;
}