//https://injae-kim.github.io/problem_solving/2020/03/11/baekjoon-2618.html
//https://kibbomi.tistory.com/m/95
//dp[i][j] : 1번 경찰차가 마지막으로 i, 2번 경찰차가 마지막으로 j사건을 처리했을 때, 앞으로 가야 할 이동거리'
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 1e9
typedef long long ll;
int N; //동서방향 도로의 개수, N(5≤N≤1,000)
int W; // 처리해야 하는 사건의 개수, W(1≤W≤1,000)
int dp[1001][1001] = { 0 };
pair<int, int> events[1001];
int dist(const pair<int, int>& a, const pair<int, int>& b);
int func(int a, int b);
void backTracking(int cur1, int cur2);
int main() {

	cin >> N;
	cin >> W;
	for (int i = 1; i <= W; ++i) {
		cin >> events[i].first >> events[i].second;
	}
	memset(dp, -1, sizeof(dp));
	
	cout << func(0, 0) << '\n';
	backTracking(0, 0);
	return 0;
}
int func(int cur1, int cur2) {
	if (cur1 == W || cur2 == W)
		return 0;
	int& ret = dp[cur1][cur2];
	if (ret != -1)
		return ret;
	ret = INF;
	int next = max(cur1, cur2) + 1; //다음 사건 번호
	int distA, distB;
	if (cur1 == 0) 
		distA = dist({ 1,1 }, events[next]);
	else 
		distA = dist(events[cur1], events[next]);
	if (cur2 == 0) 
		distB = dist({ N,N }, events[next]);
	else
		distB = dist(events[cur2], events[next]);

	/*int ret1 = func(next, cur2) + distA;
	int ret2 = func(cur1, next) + distB;*/
	ret = min(func(next, cur2) + distA, func(cur1, next) + distB);
	return ret;
}
void backTracking(int cur1, int cur2) {
	if (cur1 == W || cur2 == W)
		return;

	int next = max(cur1, cur2) + 1; //다음 사건 번호
	int distA, distB;
	if (cur1 == 0)
		distA = dist({ 1,1 }, events[next]);
	else
		distA = dist(events[cur1], events[next]);
	if (cur2 == 0)
		distB = dist({ N,N }, events[next]);
	else
		distB = dist(events[cur2], events[next]);
	/*int ret1 = func(next, cur2) + distA;
	int ret2 = func(cur1, next) + distB;*/

	if (dp[next][cur2] + distA < dp[cur1][next] + distB) {
		cout << "1" << '\n';
		backTracking(next, cur2);
	}
	else {
		cout << "2" << '\n';
		backTracking(cur1, next);
	}
}
int dist(const pair<int, int>& a, const pair<int, int>& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}