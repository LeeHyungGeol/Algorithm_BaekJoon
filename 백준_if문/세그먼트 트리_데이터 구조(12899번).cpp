//https://blog.naver.com/PostView.nhn?blogId=adamdoha&logNo=222136922767&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
//https://jh280722.tistory.com/6
//나의 풀이 : 구간 최소를 구하였다.하지만 틀렸다..
//정석적인 풀이 : kth 세그먼트 트리로 풀면 O(NlogX)이다.
//
//Query 1. 데이터 범위 200만까지의 Segment Tree 만들기
//쿼리1로 들어오는 입력 값으로 세그먼트 트리를 관리,

//Query 2. num 번째 숫자 찾기
//K번째 노드가 수 K를 나타내는 것으로 나타낼 수 있다.
//각 노드의 값을 그 수의 개수로 입력하고 세그먼트 트리로 개수들의 합을 저장
//K 번째 수는 결국 왼쪽에 K개가 있으면 그 노드가 K번째 수이므로 위치의 수를 구할 수 있다.
//K가 왼쪽 노드의 수보다 클 경우, K - 왼쪽 노드의 개수를 다시 K로 하여 오른쪽 노드에서 찾는다.
//
//삭제 쿼리
//Query 1에서는 해당 숫자에 대해 + 1을 해줬으니 삭제하는 로직은 반대로 하면 됩니다.
//num번째 숫자에 해당하는 값을 포함하는 구간을 - 1씩 세그먼트 트리 업데이트를 해주면 됩니다.
#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000001
int N;
vector<int> rangeSum;

int update(int index, int newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeSum[node];
	if (nodeL == nodeR) return rangeSum[node] += newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}
int query(int index, int node, int nodeL, int nodeR) {
	if (nodeL == nodeR) return nodeL;
	int mid = (nodeL + nodeR) / 2;
	if (index <= rangeSum[node * 2]) return query(index, node * 2, nodeL, mid);
	else return query(index - rangeSum[node * 2], node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	rangeSum.resize(4 * MAX);

	int T, X;
	for (int i = 0; i < N; ++i) {
		cin >> T >> X;
		if (T == 1) {
			update(X, 1, 1, 1, MAX);
		}
		else {
			int pos = query(X, 1, 1, MAX);
			update(pos, -1, 1, 1, MAX);
			cout << pos << '\n';
		}
	}
}