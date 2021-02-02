//특정 정점이 true 면서 다른 모든 명제를 만족시키는지 판단하는것
// : x1가 true임과 ~x1 -> x1 이 true임이 동치
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring> //memset
using namespace std;
#define MAX 1001

int N, M;//참가자의 수 n (2 ≤ n < 1000) 과 심사위원의 수 m (1 ≤ m < 2000)
int scc, id, pa[MAX * 2], group[MAX * 2], inDegree[MAX * 2];
bool finished[MAX * 2];
vector<int> graph[MAX * 2];
stack<int> s;

//inline 함수
//양수=참=홀수, 음수=거짓=짝수 로 설정
//짝수라면 반대인 홀수로, 홀수이면 반대인 짝수로 반환
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
		//계산식에서 ∧ (a ∨ a)  는 절을 하나 추가해주면,
		//a는 무조건 true 가 되어야하므로,
		//저 절(clause)을 식에 추가하고, not(a) -> a 관계를 설정해준다.
		graph[oppo(1)].push_back(1);//~a->a

		for (int i = 0; i < M; ++i) {
			cin >> a >> b;
			a = (a > 0) ? a * 2 - 1 : (-a) * 2;//양수=참=홀수, 음수=거짓=짝수 로 설정
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
