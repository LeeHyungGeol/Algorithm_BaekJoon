#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//�ð� : O(VE)

#define INF 1e9 //10��
int N, M;
vector<tuple<int, int, int>> graph;
long long int d[501]; //�ִ� ����� ��: 500
bool Bellman_Ford(int start);

int main() {
	cin >> N >> M;//N: ���, M: ����
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		graph.push_back(make_tuple(a, b, c));
	}
	fill(d, d + 501, INF);
	bool negativeCycle = Bellman_Ford(1);
	if (negativeCycle) {//���� ������ �����ؼ� ���� ��ȯ�� �����ϴ� ���
		cout << "-1" << '\n';
		return 0;
	}
	else {
		for (int i = 2; i <= N; ++i) {
			if (d[i] == INF)
				cout << "-1" << '\n';
			else
				cout << d[i] << '\n';
		}
	}
	return 0;
}
bool Bellman_Ford(int start) {
	d[start] = 0; //������, �ڱ� �ڽ� ������ �Ÿ��� 0
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {//�� �ݺ����� "��� ����"�� Ȯ���Ѵ�.	
			int cur, next, cost;
			tie(cur, next, cost) = graph[j];
			// ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (d[cur] != INF && d[cur] + cost < d[next]) {//�ѹ� �湮�Ͽ� ó���� ����� �ִ� �Ÿ��� �����Ǿ� ���̻� �ٲ��� �ʴ´�.
				d[next] = d[cur] + cost;
				if (i == N - 1)//N��°���� ���� ���ŵȴٸ� ���� ��ȯ�� ����
					return true;
			}
		}
	}
	return false;
}