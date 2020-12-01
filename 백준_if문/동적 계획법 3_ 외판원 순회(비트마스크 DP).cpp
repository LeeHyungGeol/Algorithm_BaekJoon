//��Ʈ����ũ DP�� �̿��Ͽ� �ּ� ������� ��� ���ø� ��ȸ�ϴ� ����
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
int TSP(int cur, int visited) {//���ǿ� ��ȸ ���� : Traveling Salesman problem (TSP) 
	//////////////////////////////////////////  �ǹ���
	if (((1 << N) - 1) == visited) {//��� �湮�� ���
		if (W[cur][0] == 0)
			return INF;
		return W[cur][0];
	}

	//Case : 1 -> 24ms
	if (dp[cur][visited] != -1)// �̹� �湮�� ���� �ִ� ��� //�̹� �տ��� �ּڰ��� ���� ���� �ִ� ���
		return dp[cur][visited];

	dp[cur][visited] = INF;

	for (int next = 0; next < N; ++next) {//���� ������ ���� ���
		if (W[cur][next] == 0 || visited & (1 << next))//���� ������ ���� ��ΰ� ���ų�, �̹� �湮�� ���
			continue;
		// cur->next�� �� ������ next���� ������ ���õ� ��ȸ�Ѱ� �� �ּ� or ���� ��// 2���� �ּҸ� ����
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
		// cur->next�� �� ������ next���� ������ ���õ� ��ȸ�Ѱ� �� �ּ� or ���� ��// 2���� �ּҸ� ����
	//	ret = min(ret, TSP(next, visited | (1 << next)) + W[cur][next]);
	//}
	//return ret;
	
}
