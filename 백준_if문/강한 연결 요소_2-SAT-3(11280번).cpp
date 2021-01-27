//https://m.blog.naver.com/kks227/220803009418
//https://justicehui.github.io/hard-algorithm/2019/05/17/2SAT/ - 정점 번호를 새로 매기는 방법이 기발했음
//https://devbelly.tistory.com/54 - 문제가 어려워질수록 헷갈려지기 때문에 디버깅의 편의를 위해 ""OR함수""를 작성하시는 것을 추천드립니다. 
//2-SAT 문제는 다항 시간에 풀 수 있다.

//2-SAT
//충족 가능성 문제(satisfiability problem) 중 하나인데,
//충족 가능성 문제는 여러 개의 boolean 변수들로 이루어진 boolean expression이 있을 때,
//각 변수의 값을 true, false 중 하나로 설정하여 전체 식의 결과를 true로 만들 수 있느냐는 문제


//2-SAT 문제에서 어떤 절 하나를 보면,
//각각의 절(clause)이 true이어야 하니까, 절에 들어있는 두 항 중에 적어도 하나는 참이어야 한다.

//(x1∨x2)라는 절이 있다면, 
//만약 x1이 거짓이라면 x2는 참이어야만 하고, 
//x2가 거짓이면 반대로 x1이 참이어야 전체 식이 true가 될 가능성이 생깁니다. 
//아니면 둘 다 거짓이 되어 절대 전체 식이 true가 될 수가 없다.

//(x1∨~x2)라는 절이 있다면, 
//x1이 거짓이면 ~x2가 참이어야 하는데, 이 말은 x2가 거짓이어야 한다는 의미이며, 
//~x2가 거짓이면, 즉 x2가 참이면 x1이 참이어야 한다.

//이런 식으로 만약 두 항 중 하나가 거짓이라면,
//나머지 하나는 참이어야 한다는 명제들을 모두 모으자.

//절 (x1∨x2)는 다음과 같은 2개의 명제로 나타낼 수 있다.
//->   ~x1 → x2, ~x2 → x1

//절(x1∨¬x2)는 다음과 같은 2개의 명제로 나타낼 수 있다.
//->   ~x1 → ~x2, ~(~x2) = x2 → x1


//1. 이런 식으로 모든 절에서 각각 두 개의 명제를 추출한다.

//2.이제 각 변수(p)와 NOT 변수(~p)를 하나의 정점(vertex)이라 생각하고, 이런 → 관계들을 간선(edge)이라 생각한다면,
//  x1 → ~x1과 ~x1 → x1 꼴의, 자신의 NOT 형 변수로 가는 경로가 양쪽으로 존재하는 경우가 하나라도 존재한다면,
//전체 식을 참으로 만들 방법이 없는 게 확실하다.

//3. 이 그래프를 SCC별로 분리한 후, 어떤 변수(p)와 NOT 형 변수(~p)가 같은 SCC에 있는 경우가 있는지를 체크하는 식으로 확인한다.

//주목해야 할 점은, p → q라는 명제가 있을 때,
//p가 거짓이면 q는 참이어도 거짓이어도 명제를 해치지 않지만, p가 참이면 q도 반드시 참이어야 합니다.

//하나의 SCC 안에 있는 정점들은 그 중 하나라도 참이면 나머지도 모두 참이어야 하고,
//따라서 SCC 안에 p와 ~p가 동시에 존재한다면 둘 다 참일 수는 없으므로 모순이 된다.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 10001

int N, M;//변수의 개수 N (1 ≤ N ≤ 10,000)과 절의 개수 M (1 ≤ M ≤ 100,000)
int scc, id, pa[MAX * 2];
bool finished[MAX * 2];
int group[MAX * 2];
vector<int> graph[MAX*2];
stack<int> s;
int SCC[MAX * 2];
// 자신의 not literal의 정점 번호 리턴
inline int oppo(int n) { return n % 2 ? n - 1 : n + 1; }

int TarjanSCC(int cur) {
	pa[cur] = id++;
	s.push(cur);
	int parent = pa[cur];
	
	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (pa[next] == 0) parent = min(parent, TarjanSCC(next));
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 그래프 구축
	cin >> N >> M;

	//CNF를 입력받아 그걸 토대로 그래프를 구축한다.
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		// 양수냐 음수냐에 따라 각 정점 번호를 새로 매김
		// x_k : (k-1)*2 
		//not x_k : (k-1)*2-1
		a = (a < 0) ? -(a + 1) * 2 : a*2 - 1;
		b = (b < 0) ? -(b + 1) * 2 : b * 2 - 1;

		// (A or B)에 대한 간선 추가
		graph[oppo(a)].push_back(b); // ~A -> B
		graph[oppo(b)].push_back(a); // ~B -> A
	}

	for (int i = 0; i < N * 2; ++i) {
		if (pa[i] == 0) TarjanSCC(i);
	}

	// x_k와 not x_k가 한 SCC 안에 있으면 불가능
	for (int i = 0; i < N; ++i) {
		if (group[i * 2] == group[i * 2 + 1]) {
			cout << "0" << '\n';
			return 0;
		}
	}
	cout << "1" << '\n';
	return 0;
}