//환형 구조임을 고려하여 modulo연산 필수
//N : 7, K : 3
// 1 2 3 4 5 6 7
// 1 2 X 4 5 6 7 -> 3
// 1 2 X 4 5 X 7 -> 6
// 1 X X 4 5 X 7 -> 2
// 1 X X 4 5 X X -> 7
// 1 X X 4 X X X -> 5
// X X X 4 X X X -> 1
// X X X X X X X -> 4
#include <vector>
#include <iostream>
using namespace std;
#define MAX 100001

vector<int> rangeSum;
int N, K;
//index번째 수를 리턴
//rangeSum[node] : node번째 숫자가 있는지 없는지를 판단, 1이면 node번째 숫자가 있는것, 0이면 없다는 의미
int query(int index, int node,int nodeL, int nodeR) {
	if (nodeL == nodeR) return nodeL;
	int mid = (nodeL + nodeR) / 2;
	if (index <= rangeSum[node * 2]) return query(index, node * 2, nodeL, mid);
	else return query(index - rangeSum[node * 2], node * 2 + 1, mid + 1, nodeR);
}
//newValue는 1 또는 0
//index번째 숫자를 있다(1) 또는 없다(0)으로 업데이트 한다.
int update(int index, int newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeSum[node];
	if (nodeL == nodeR) return rangeSum[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}
//L부터 R까지 몇 개의 숫자가 남아있는지 숫자 갯수를 리턴
int querySum(int L, int R, int node, int nodeL, int nodeR) {
	// [nodeL, nodeR]과 [L, R]이 전혀 안 겹치는 경우. 바로 0을 리턴, 0은 구간의 합에 무관하기 때문에
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]이 [L, R]에 완전히 포함되는 경우. 바로 자신의 값을 리턴
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return querySum(L, R, node * 2, nodeL, mid) + querySum(L, R, node * 2 + 1, mid + 1, nodeR);
}
int main() {

	cin >> N >> K;

	rangeSum.resize(4 * MAX);

	for (int i = 1; i <= N; ++i) 
		update(i, 1, 1, 1, N);

	//맨 처음 K번째 숫자에 대한 처리
	vector<int> answer;
	answer.push_back(K);
	update(K, 0, 1, 1, N);

	int size = N - 1;
	for (int i = 2; i <= N; ++i) {
		//1부터 answer.back()까지의 몇 개의 숫자가 남아있는 지에 대해 알아내서
		//그 숫자에 K만큼 더한 후, 남아있는 전체 숫자 갯수(size)로 modulo연산 수행
		int pos = (querySum(1, answer.back(), 1, 1, N) + K) % size;
		//pos가 0일 때의 예외처리
		if (!pos) pos = size;
		//pos번째 숫자를 answer에 push_back
		answer.push_back(query(pos, 1, 1, N));
		//pos번째 숫자를 없앴다고 update
		update(answer.back(), 0, 1, 1, N);
		//전체 숫자 갯수를 1 감소
		size--;
	}
	cout << "<";
	for (int i = 0; i < answer.size(); ++i)
		(i == answer.size() - 1) ? cout << answer[i] << ">\n" : cout << answer[i] << ", ";
	return 0;
}