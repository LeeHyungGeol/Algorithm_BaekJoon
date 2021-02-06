//이 문제는 쿼리를 그대로 받아들이면 안된다. 
//세그먼트 트리의 리프가 각각 그 자리에 몇 번 DVD가 있는지를 나타내면 풀기 어렵습니다.
//바꿔서, 세그먼트 트리의 리프가 k번이라면 """k번 DVD가 어느 위치에 있는지를 저장"""해 두면 된다.
//매번 L~R번 DVD가 있는 위치들 중 최솟값과 최댓값이 각각 L, R인지 확인하면 문제를 풀 수 있습니다!한 단계 발상의 전환이 필요한 문제.
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e9
using namespace std;
int T, N, K;
vector<int> arr;
vector<int> rangeMin;
vector<int> rangeMax;

int initMin(int node,int left,int right) {
	if (left == right) return rangeMin[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeMin[node] = min(initMin(node*2, left,mid),initMin(node*2+1,mid+1,right));
}
int queryMin(int L,int R, int node, int nodeL, int nodeR) {
	if (nodeR < L || R < nodeL) return MAX;
	if (L <= nodeL && nodeR <= R) return rangeMin[node];
	int mid = (nodeL + nodeR) / 2;
	return min(queryMin(L, R, node * 2, nodeL, mid), queryMin(L, R, node * 2 + 1, mid + 1, nodeR));
}
int updateMin(int index, int newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeMin[node];
	if (nodeL == nodeR) return rangeMin[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeMin[node] = min(updateMin(index, newValue, node * 2, nodeL, mid), updateMin(index, newValue, node * 2 + 1, mid + 1, nodeR));
}

int initMax(int node, int left, int right) {
	if (left == right) return rangeMax[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeMax[node] = max(initMax(node * 2, left, mid), initMax(node * 2 + 1, mid + 1, right));
}
int queryMax(int L, int R, int node, int nodeL, int nodeR) {
	if (nodeR < L || R < nodeL) return -1;
	if (L <= nodeL && nodeR <= R) return rangeMax[node];
	int mid = (nodeL + nodeR) / 2;
	return max(queryMax(L, R, node * 2, nodeL, mid), queryMax(L, R, node * 2 + 1, mid + 1, nodeR));
}
int updateMax(int index, int newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeMax[node];
	if (nodeL == nodeR) return rangeMax[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeMax[node] = max(updateMax(index, newValue, node * 2, nodeL, mid), updateMax(index, newValue, node * 2 + 1, mid + 1, nodeR));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		arr.clear();
		rangeMin.clear();
		rangeMax.clear();

		cin >> N >> K;

		arr.resize(N);
		rangeMin.resize(4 * N);
		rangeMax.resize(4 * N);

		for (int i = 0; i < N; ++i)
			arr[i] = i;

		initMin(1,0,N-1);
		initMax(1,0,N-1);

		int Q, A, B;
		for (int k = 0; k < K; ++k) {
			cin >> Q >> A >> B;
			if (Q) {
				if (queryMin(A,B,1,0,N-1) == A && queryMax(A,B,1,0,N-1) == B) cout << "YES" << '\n';
				else cout << "NO" << '\n';
			}
			else {
				swap(arr[A], arr[B]);
				updateMin(A,arr[A],1,0,N-1);
				updateMin(B,arr[B],1,0,N-1);
				updateMax(A, arr[A], 1, 0, N - 1);
				updateMax(B, arr[B], 1, 0, N - 1);
			}
		}
	}

	return 0;
}