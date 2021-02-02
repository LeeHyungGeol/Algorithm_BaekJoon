//Ư�� ������ true �鼭 �ٸ� ��� ������ ������Ű���� �Ǵ��ϴ°�
// : x1�� true�Ӱ� ~x1 -> x1 �� true���� ��ġ
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring> //memset
using namespace std;
#define MAX 1001

int N, M;//�������� �� n (2 �� n < 1000) �� �ɻ������� �� m (1 �� m < 2000)
int scc, id, pa[MAX * 2], group[MAX * 2], inDegree[MAX * 2];
bool finished[MAX * 2];
vector<int> graph[MAX * 2];
stack<int> s;

//inline �Լ�
//���=��=Ȧ��, ����=����=¦�� �� ����
//¦����� �ݴ��� Ȧ����, Ȧ���̸� �ݴ��� ¦���� ��ȯ
inline int oppo(int n) { return (n % 2) ? n + 1 : n - 1;}
int dfs(int cur) {
	int parent = pa[cur] = ++id;
	s.push(cur);
	
	for (int i = 0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (pa[next] == 0) parent = min(parent, dfs(next));
		else if (!finished[next]) parent = min(parent, pa[next]);
	}

	if (parent == pa[cur]) {
		while (1) {
			int t = s.top();
			s.pop();
			group[t] = scc;
			finished[t] = true;
			if (t == cur) break;
		}
		scc++;
	}
	return parent;
}

int main() {
	while (cin >> N) {
		cin >> M;
		scc = id = 0;
		memset(pa, 0, sizeof(pa));
		memset(group, 0, sizeof(group));
		memset(inDegree, 0, sizeof(inDegree));
		memset(finished, false, sizeof(finished));
		for (int i = 1; i <= N * 2; ++i)
			graph[i].clear();

		int a, b;
		//���Ŀ��� �� (a �� a)  �� ���� �ϳ� �߰����ָ�,
		//a�� ������ true �� �Ǿ���ϹǷ�,
		//�� ��(clause)�� �Ŀ� �߰��ϰ�, not(a) -> a ���踦 �������ش�.
		graph[oppo(1)].push_back(1);//~a->a

		for (int i = 0; i < M; ++i) {
			cin >> a >> b;
			a = (a > 0) ? a * 2 - 1 : (-a) * 2;//���=��=Ȧ��, ����=����=¦�� �� ����
			b = (b > 0) ? b * 2 - 1 : (-b) * 2;

			graph[oppo(a)].push_back(b);//~a->b
			graph[oppo(b)].push_back(a);//~b->a
		}

		for (int i = 1; i <= N * 2; ++i) {
			if (pa[i] == 0) dfs(i);
		}
		bool flag = true;
		for (int i = 1; i <= N; ++i) {
			if (group[i * 2 - 1] == group[i * 2]) {
				flag = false; break;
			}
		}
		flag ? cout << "yes" << '\n' : cout << "no" << '\n';
	}
	return 0;
}
