//트리의 ""최대 독립 집합""을 구하는 문제. 일반적인 그래프에서 최대 독립 집합을 구하는 문제는 NP-하드로, 효율적인 알고리즘이 알려지지 않았습니다.
//dfs 순회 순서 상에서 바로 이전에 방문한 노드가 독립 집합이 아니어야 한다.
//dp[cur][true]>dp[cur][false]: 현재 방문한 노드를 포함할 때가 포함 안할 때 보다 더 큰 독립집합을 얻을 수 있다.
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>//memset
#include <algorithm>
using namespace std;
int n;//트리의 정점의 수 n, n은 10,000이하인 양의 정수
int dp[10001][2] = { 0 };//dp[n][]은 현재 정점까지의 최대 독립 집합의 크기//dp[n][0]은 false, dp[n][1]은 true
int w[10001] = { 0 };
vector<int> answer;
vector<int> tree[10001];
int dfs(int cur, int selected, int prev);
void tracert(int cur, int select, int prev);
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> w[i];
	int from, to;
	for (int i = 1; i <= n - 1; ++i) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	memset(dp, -1, sizeof(dp));
	int ret1 = dfs(1, false, -1);//시작 노드는 1번을 하든 몇번부터 시작하든 상관없다.
	int ret2 = dfs(1, true, -1);//시작 노드를 포함하고 시작하는 경우와 포함하지 않고 시작하는 경우의 2가지 경우를 모두 실행한다.
	cout << max(ret1, ret2) << '\n';
	if (ret1 > ret2)//둘 중 값이 더 큰 경우로 역추적 실행
		tracert(1, false, -1);
	else
		tracert(1, true, -1);
	sort(answer.begin(), answer.end());//오름차순으로 정렬
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	return 0;
}
void tracert(int cur, int select, int prev) {
	if (select) {
		answer.push_back(cur);
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (next != prev)
				tracert(next, false, cur);
		}
	}
	else {
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (next != prev) {
				if (dp[next][true] > dp[next][false])
					tracert(next, true, cur);
				else
					tracert(next, false, cur);
			}
		}
	}
}
int dfs(int cur, int select, int prev) {
	if (dp[cur][select] != -1)
		return dp[cur][select];
	if (select)
		dp[cur][select] = w[cur];
	else
		dp[cur][select] = 0;
	for (int i = 0; i < tree[cur].size(); ++i) {
		int next = tree[cur][i];
		if (select) {//지금 보고 있는 노드를 포함할 때(선택할 때)
			if (next != prev) {//다음 노드가 이전 노드랑 달라야 하고
				//dp[cur][select] = w[cur];
				dp[cur][select] += dfs(next, false, cur);//다음 노드를 선택하면 안된다.(false)
			}
		}
		else {//지금 보고 있는 노드를 포함하지 않을 때(선택하지 않을 때)
			if (next != prev) {//다음 노드가 이전 노드랑 달라야 하고
				//dp[cur][select] = 0; 
				int ret2 = dfs(next, true, cur);//다음 노드를 선택했을 때와
				int ret1 = dfs(next, false, cur);//선택하지 않았을 때의 두 경우에서
				dp[cur][select] += max(ret1, ret2);//더 큰 값을 넣어준다.
			}
		}
	}
	return dp[cur][select];
}