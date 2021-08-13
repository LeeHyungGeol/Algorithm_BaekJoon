// �ִܰ��(�÷��̵� ����) ����

// [���� ��� 4] Ű ����(2458��) ������ ����ϴ�.
// ��� �������� �ٸ� ��� ���������� `����` �� ���ϴ� ����
// a is b : a -> b : Graph[a][b] = 1 : a�� b�� `����` �� �ִٴ� �ǹ�
// Graph[a][b] == INF : a�� b���̿� `����`�� ���ٴ� �ǹ�

// �߰��� C++ ����,
// `������ ������ ���ڿ�`�� ���� ��, getline(cin, string); �� �ϸ� �ȴ�.
// string�� �Է� �ޱ⿡ �ռ� ���ڸ� �Է� �޾Ҵٸ�, cin.ignore()�� �߰��Ѵ�.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M;
vector<vector<int>> Graph;

void init();
void floyd_warshall();

int main() {
	cin >> N;
	//�߰� ���� ��� getline���� subscript range ���� �߻�
	cin.ignore();

	init();

	string str;

	for (int i = 0; i < N; ++i) {
		string str;
		getline(cin, str);
		Graph[str[0] - 'a'][str[5] - 'a'] = 1;
	}

	floyd_warshall();

	cin >> M;
	cin.ignore();

	for (int i = 0; i < M; ++i) {
		string str;
		getline(cin, str);
		if (Graph[str[0] - 'a'][str[5] - 'a'] != INF) {
			cout << 'T' << '\n';
		}
		else {
			cout << 'F' << '\n';
		}
	}

	return 0;
}

void init() {
	Graph.resize(26, vector<int>(26, INF));

	for (int i = 0; i <= 25; ++i) {
		for (int j = 0; j <= 25; ++j) {
			if (i == j) {
				Graph[i][j] = 0;
			}
		}
	}
}

void floyd_warshall() {
	for (int k = 0; k <= 25; ++k) {
		for (int i = 0; i <= 25; ++i) {
			for (int j = 0; j <= 25; ++j) {
				Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
			}
		}
	}
	return;
}