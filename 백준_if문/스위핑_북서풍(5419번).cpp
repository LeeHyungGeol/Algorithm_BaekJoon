//북서풍을 타고 항해할 수 있는 섬의 쌍의 개수를 구하는 문제이다.
//여기서 북서풍을 타고 항해할 수 있는 섬이란, 어떤 섬 기준으로 x좌표가 해당하는 섬보다 크거나 같고, y좌표가 해당하는 섬보다 작거나 같은 섬들을 말한다.
//결국 각 섬마다 x좌표가 작으면서 y좌표는 큰 섬들의 개수를 구한 뒤 그 합을 출력하면 된다. 
//x좌표에 대해 오름차순으로 정렬, y좌표에 대해 내림차순으로 정렬한다.
//새로운 배열 newY를 이용하여, y좌표에 대한 좌표 압축을 수행한다.
//좌표 압축을 한 index에 대해서 세그먼트 트리에 업데이트 시켜주고, 현재 보고 있는 섬(좌표)보다 더 큰 y좌표의 개수를 세어주면 된다.

//좌표를 압축한다 : 해당 좌표의 값을 그 값보다 작은 좌표값들의 개수로 대체한다.
//좌표 압축은 주어지는 수의 범위가 매우 크지만 그 범위의 수 중에서 나오는 수는 그렇게 많지 않을때 사용한다.
//만약 범위가 - 1e9 ~1e9 인데 숫자는 10만개 밖에 없다면 좌표 압축을 통해 범위를 줄여서 무언가를 수행한다면, 더욱 효율적으로 할 수 있다.
//이는 세그먼트 트리나 구간 쿼리 처리에 쓰이는 경우가 많다.

//좌표 압축을 하는 방법
//1. vector를 이용하여 좌표 값을 모두 입력 받는다.이때 원래 상태를 저장하기 위해 두 개의 벡터에 입력받습니다.
//2. 중복된 수를 제거하기 위해 오름차순으로 정렬한다.
//3. unique를 이용하여 중복된 수를 뒤로 밀고 resize나 erase를 이용해서 뒤로 밀려난 중복된 수를 제거합니다.
//4. lower_bound를 이용하여 원래의 수를 찾습니다.즉 index의 위치가 좌표 압축을 한 값이 됩니다.
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
	// [nodeL, nodeR]과 [L, R]이 전혀 안 겹치는 경우. 바로 0을 리턴, 0은 구간의 합에 무관하기 때문에
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]이 [L, R]에 완전히 포함되는 경우. 바로 자신의 값을 리턴
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
int update(int index, int newValue, int node, int nodeL, int nodeR) {
	//index가 노드가 표현하는 구간과 상관없는 경우에는 무시한다.
	if (nodeL > index || index > nodeR) return rangeSum[node];
	//트리의 리프 노드까지 내려온 경우
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