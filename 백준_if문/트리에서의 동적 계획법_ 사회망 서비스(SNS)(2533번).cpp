//��ȸ�� ���񽺿� ���� ������� �� �ƴ����̰ų� �� �ƴ��Ͱ� �ƴϴ�. 
//�� �ƴ��Ͱ� �ƴ� ������� �ڽ��� ��� ģ������ �� �ƴ����� ���� �� ���̵� �޾Ƶ��δ�. 
//ģ�� ���� Ʈ���� �־����� ��, ��� ������ ���ο� ���̵� �����ϱ� ���Ͽ� �ʿ��� �ּ� �� ������� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//ó���� Ʈ���� ����(height)�� ���Ͽ�, ¦�� level�� �ش��ϴ� ������ �� �ƴ��ͷ� ����� ������ count�Ϸ��� �ߴ�.
//ã�ƺ���, �� ����� �ݷʰ� �����ߴ�.
//�ι�°�� �׺��� �����ϰ� �׳� bfs�� ����Ͽ� Ȧ�� level�� �ش��ϴ� ����� ¦�� level�� �ش��ϴ� ������ ���� �� ���� ���� ����Ϸ��� �ߴ�.
//������, ���� 2��� ��� root���� ��Ȯ�ϰ� ���� ���ϸ�, �������� ���ϹǷ� �Ϲ����� dp����ó�� ��͹���� ����Ͽ� memoization�� �ߴ�.
//Ʈ���� ��������(2213��)�� ����ϰ� Ǯ����� �Ѵ�.
#include <iostream>
#include <vector>
#include <cstring>//memset
#include <algorithm>
using namespace std;
int N;//ģ�� ���� Ʈ���� ���� ���� N�� �־�����. ��, 2 <= N <= 1,000,000
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
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	int ret1 = func(1, 0, -1);
	int ret2 = func(1, 1, -1);
	cout << min(ret1, ret2) << '\n';
	return 0;
}
int func(int cur, int selected, int prev) {
	
}
