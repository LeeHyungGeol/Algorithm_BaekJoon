//사회망 서비스에 속한 사람들은 얼리 아답터이거나 얼리 아답터가 아니다. 
//얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 얼리 아답터일 때만 이 아이디어를 받아들인다. 
//친구 관계 트리가 주어졌을 때, 모든 개인이 새로운 아이디어를 수용하기 위하여 필요한 최소 얼리 어답터의 수를 구하는 프로그램을 작성하시오.
//처음엔 트리의 높이(height)를 구하여, 짝수 level에 해당하는 노드들을 얼리 아답터로 만들고 개수를 count하려고 했다.
//찾아보니, 이 방법도 반례가 존재했다.
//두번째엔 그보다 간단하게 그냥 bfs를 사용하여 홀수 level에 해당하는 노드들과 짝수 level에 해당하는 노드들의 개수 중 작은 값을 출력하려고 했다.
//하지만, 위의 2방법 모두 root값을 정확하게 알지 못하면, 적용하지 못하므로 일반적인 dp문제처럼 재귀방법을 사용하여 memoization을 했다.
//트리의 독립집합(2213번)과 비슷하게 풀어나가려 한다.
#include <iostream>
#include <vector>
#include <cstring>//memset
#include <algorithm>
using namespace std;
int N;//친구 관계 트리의 정점 개수 N이 주어진다. 단, 2 <= N <= 1,000,000
int dp[1000001][2] = { 0 };
vector<int> tree[1000001];
int func(int cur, int select, int prev);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	memset(dp, -1, sizeof(dp));
	int ret1 = func(1, 0, -1);
	int ret2 = func(1, 1, -1);
	cout << min(ret1, ret2) << '\n';
	return 0;
}
int func(int cur, int selected, int prev) {
	if (dp[cur][selected] != -1) return dp[cur][selected];

	if (selected) {//부모가 얼리어답터일 때
		dp[cur][selected] = 1;
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (next != prev) {
				int ret1 = func(next, true, cur);
				int ret2 = func(next, false, cur);
				dp[cur][selected] += min(ret1, ret2);//자식은 아무 상태가 되어도 상관없다.
			}
		}
	}
	else {//부모가 얼리어답터가 아닐 때
		dp[cur][selected] = 0;
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (next != prev) {//next는 true
				dp[cur][selected] += func(next, true, cur);//자식은 무조건 얼리어답터이어야 한다.	
			}
		}
	}
	return dp[cur][selected];
}
