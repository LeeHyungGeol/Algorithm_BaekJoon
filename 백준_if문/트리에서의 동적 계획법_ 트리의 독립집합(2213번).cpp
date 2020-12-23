//Ʈ���� ""�ִ� ���� ����""�� ���ϴ� ����. �Ϲ����� �׷������� �ִ� ���� ������ ���ϴ� ������ NP-�ϵ��, ȿ������ �˰����� �˷����� �ʾҽ��ϴ�.
//dfs ��ȸ ���� �󿡼� �ٷ� ������ �湮�� ��尡 ���� ������ �ƴϾ�� �Ѵ�.
//dp[cur][true]>dp[cur][false]: ���� �湮�� ��带 ������ ���� ���� ���� �� ���� �� ū ���������� ���� �� �ִ�.
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>//memset
#include <algorithm>
using namespace std;
int n;//Ʈ���� ������ �� n, n�� 10,000������ ���� ����
int dp[10001][2] = { 0 };//dp[n][]�� ���� ���������� �ִ� ���� ������ ũ��//dp[n][0]�� false, dp[n][1]�� true
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
	int ret1 = dfs(1, false, -1);//���� ���� 1���� �ϵ� ������� �����ϵ� �������.
	int ret2 = dfs(1, true, -1);//���� ��带 �����ϰ� �����ϴ� ���� �������� �ʰ� �����ϴ� ����� 2���� ��츦 ��� �����Ѵ�.
	cout << max(ret1, ret2) << '\n';
	if (ret1 > ret2)//�� �� ���� �� ū ���� ������ ����
		tracert(1, false, -1);
	else
		tracert(1, true, -1);
	sort(answer.begin(), answer.end());//������������ ����
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
		if (select) {//���� ���� �ִ� ��带 ������ ��(������ ��)
			if (next != prev) {//���� ��尡 ���� ���� �޶�� �ϰ�
				//dp[cur][select] = w[cur];
				dp[cur][select] += dfs(next, false, cur);//���� ��带 �����ϸ� �ȵȴ�.(false)
			}
		}
		else {//���� ���� �ִ� ��带 �������� ���� ��(�������� ���� ��)
			if (next != prev) {//���� ��尡 ���� ���� �޶�� �ϰ�
				//dp[cur][select] = 0; 
				int ret2 = dfs(next, true, cur);//���� ��带 �������� ����
				int ret1 = dfs(next, false, cur);//�������� �ʾ��� ���� �� ��쿡��
				dp[cur][select] += max(ret1, ret2);//�� ū ���� �־��ش�.
			}
		}
	}
	return dp[cur][select];
}