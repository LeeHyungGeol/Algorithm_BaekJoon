//https://injae-kim.github.io/problem_solving/2020/03/11/baekjoon-2618.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 1e9
typedef long long ll;
typedef struct police {
	int x, y;
}police;
int N; //동서방향 도로의 개수, N(5≤N≤1,000)
int W; // 처리해야 하는 사건의 개수, W(1≤W≤1,000)
int dp[1001][1001] = { 0 };
vector<police> p1, p2;
int dist(int a, int b, int c, int d);
int func(int a, int b);
void backTracking(int cur1, int cur2);
int main() {

	int a, b;
	cin >> N;
	cin >> W;
	p1.push_back({ 1,1 });
	p2.push_back({ N,N });
	for (int i = 0; i < W; ++i) {
		cin >> a >> b;
		p1.push_back({ a, b });
		p2.push_back({ a, b });
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
	int next = max(cur1, cur2) + 1;
	int distA = dist(p1[cur1].x, p1[next].x, p1[cur1].y, p1[next].y);
	int distB = dist(p2[cur2].x, p2[next].x, p2[cur2].y, p2[next].y);
	int ret1 = func(next, cur2) + distA;
	int ret2 = func(cur1, next) + distB;
	return ret = min(ret1, ret2);
}
void backTracking(int cur1, int cur2) {
	if (cur1 == W || cur2 == W)
		return;

	int next = max(cur1, cur2) + 1;
	int distA = dist(p1[cur1].x, p1[next].x, p1[cur1].y, p1[next].y);
	int distB = dist(p2[cur2].x, p2[next].x, p2[cur2].y, p2[next].y);
	int ret1 = func(next, cur2) + distA;
	int ret2 = func(cur1, next) + distB;
	if (ret1 < ret2) {
		cout << "1" << '\n';
		backTracking(next, cur2);
	}
	else {
		cout << "2" << '\n';
		backTracking(cur1, next);
	}
}
int dist(int a, int b, int c, int d) {
	int res = abs(a - b) + abs(c - d);
	return res;
}