//�ϼ�ǳ�� Ÿ�� ������ �� �ִ� ���� ���� ������ ���ϴ� �����̴�.
//���⼭ �ϼ�ǳ�� Ÿ�� ������ �� �ִ� ���̶�, � �� �������� x��ǥ�� �ش��ϴ� ������ ũ�ų� ����, y��ǥ�� �ش��ϴ� ������ �۰ų� ���� ������ ���Ѵ�.
//�ᱹ �� ������ x��ǥ�� �����鼭 y��ǥ�� ū ������ ������ ���� �� �� ���� ����ϸ� �ȴ�. 
//x��ǥ�� ���� ������������ ����, y��ǥ�� ���� ������������ �����Ѵ�.
//���ο� �迭 newY�� �̿��Ͽ�, y��ǥ�� ���� ��ǥ ������ �����Ѵ�.
//��ǥ ������ �� index�� ���ؼ� ���׸�Ʈ Ʈ���� ������Ʈ �����ְ�, ���� ���� �ִ� ��(��ǥ)���� �� ū y��ǥ�� ������ �����ָ� �ȴ�.

//��ǥ�� �����Ѵ� : �ش� ��ǥ�� ���� �� ������ ���� ��ǥ������ ������ ��ü�Ѵ�.
//��ǥ ������ �־����� ���� ������ �ſ� ũ���� �� ������ �� �߿��� ������ ���� �׷��� ���� ������ ����Ѵ�.
//���� ������ - 1e9 ~1e9 �ε� ���ڴ� 10���� �ۿ� ���ٸ� ��ǥ ������ ���� ������ �ٿ��� ���𰡸� �����Ѵٸ�, ���� ȿ�������� �� �� �ִ�.
//�̴� ���׸�Ʈ Ʈ���� ���� ���� ó���� ���̴� ��찡 ����.

//��ǥ ������ �ϴ� ���
//1. vector�� �̿��Ͽ� ��ǥ ���� ��� �Է� �޴´�.�̶� ���� ���¸� �����ϱ� ���� �� ���� ���Ϳ� �Է¹޽��ϴ�.
//2. �ߺ��� ���� �����ϱ� ���� ������������ �����Ѵ�.
//3. unique�� �̿��Ͽ� �ߺ��� ���� �ڷ� �а� resize�� erase�� �̿��ؼ� �ڷ� �з��� �ߺ��� ���� �����մϴ�.
//4. lower_bound�� �̿��Ͽ� ������ ���� ã���ϴ�.�� index�� ��ġ�� ��ǥ ������ �� ���� �˴ϴ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 75001

int T, N;
vector<pii> islands;
vector<int> newY;
vector<int> cnt;
vector<int> rangeSum;

int query(int L, int R, int node, int nodeL, int nodeR) {
	// [nodeL, nodeR]�� [L, R]�� ���� �� ��ġ�� ���. �ٷ� 0�� ����, 0�� ������ �տ� �����ϱ� ������
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]�� [L, R]�� ������ ���ԵǴ� ���. �ٷ� �ڽ��� ���� ����
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
int update(int index, int newValue, int node, int nodeL, int nodeR) {
	//index�� ��尡 ǥ���ϴ� ������ ������� ��쿡�� �����Ѵ�.
	if (nodeL > index || index > nodeR) return rangeSum[node];
	//Ʈ���� ���� ������ ������ ���
	if (nodeL == nodeR) return rangeSum[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}
bool cmp(const pii& a, const pii& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		islands.clear();
		newY.clear();
		cnt.clear();
		rangeSum.clear();

		cin >> N;

		rangeSum.resize(4 * MAX);
		cnt.resize(MAX);

		int x, y;
		for (int i = 0; i < N; ++i) {
			cin >> x >> y;
			islands.push_back({ x,y });
			newY.push_back(y);
		}

		sort(islands.begin(), islands.end(), cmp);
		sort(newY.begin(), newY.end());
		newY.erase(unique(newY.begin(), newY.end()), newY.end());

		ll result = 0;
		for (int i = 0; i < N; ++i) {
			int index = lower_bound(newY.begin(), newY.end(), islands[i].second) - newY.begin();
			result += (ll)query(index, N - 1, 1, 0, N - 1);
			cnt[index]++;
			update(index, cnt[index], 1, 0, N - 1);
		}
		cout << result << '\n';
	}
	return 0;
}