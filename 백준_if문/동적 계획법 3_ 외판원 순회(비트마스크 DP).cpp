//비트마스크 DP를 이용하여 최소 비용으로 모든 도시를 순회하는 문제
#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 1e9
using namespace std;
int N;
int dp[16][1<<16] = { 0 };
//int bit = 0;
int W[16][16] = { 0 };
int TSP(int cur, int visited);
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> W[i][j];
		}
	}
	memset(dp, -1, sizeof(dp)); //#include <string.h>

	cout << TSP(0, 1) << '\n';
	return 0;
}
int TSP(int cur, int visited) {//외판원 순회 문제 : Traveling Salesman problem (TSP) 
	//////////////////////////////////////////  의문점
	if (((1 << N) - 1) == visited) {//모두 방문한 경우
		if (W[cur][0] == 0)
			return INF;
		return W[cur][0];
	}

	//Case : 1 -> 24ms
	if (dp[cur][visited] != -1)// 이미 방문한 적이 있는 경우 //이미 앞에서 최솟값을 구한 적이 있는 경우
		return dp[cur][visited];

	dp[cur][visited] = INF;

	for (int next = 0; next < N; ++next) {//다음 마을로 가는 경우
		if (W[cur][next] == 0 || visited & (1 << next))//다음 마을로 가는 경로가 없거나, 이미 방문한 경우
			continue;
		// cur->next로 간 다음에 next에서 나머지 도시들 순회한거 중 최소 or 지금 값// 2개중 최소를 가림
		dp[cur][visited] = min(dp[cur][visited], TSP(next, visited | (1 << next)) + W[cur][next]);
	}
	return dp[cur][visited];

	//Case : 2 -> 32ms
	//int& ret = dp[cur][visited];
	//if (ret != -1)
	//	return ret;

	//ret = INF;

	//for (int next = 0; next < N; ++next) {
	//	if (W[cur][next] == 0 || (visited & (1 << next)))
	//		continue;
		// cur->next로 간 다음에 next에서 나머지 도시들 순회한거 중 최소 or 지금 값// 2개중 최소를 가림
	//	ret = min(ret, TSP(next, visited | (1 << next)) + W[cur][next]);
	//}
	//return ret;
	
}
