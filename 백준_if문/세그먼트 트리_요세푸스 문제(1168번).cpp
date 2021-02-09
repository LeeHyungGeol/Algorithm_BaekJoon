//ȯ�� �������� ����Ͽ� modulo���� �ʼ�
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
//index��° ���� ����
//rangeSum[node] : node��° ���ڰ� �ִ��� �������� �Ǵ�, 1�̸� node��° ���ڰ� �ִ°�, 0�̸� ���ٴ� �ǹ�
int query(int index, int node,int nodeL, int nodeR) {
	if (nodeL == nodeR) return nodeL;
	int mid = (nodeL + nodeR) / 2;
	if (index <= rangeSum[node * 2]) return query(index, node * 2, nodeL, mid);
	else return query(index - rangeSum[node * 2], node * 2 + 1, mid + 1, nodeR);
}
//newValue�� 1 �Ǵ� 0
//index��° ���ڸ� �ִ�(1) �Ǵ� ����(0)���� ������Ʈ �Ѵ�.
int update(int index, int newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeSum[node];
	if (nodeL == nodeR) return rangeSum[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}
//L���� R���� �� ���� ���ڰ� �����ִ��� ���� ������ ����
int querySum(int L, int R, int node, int nodeL, int nodeR) {
	// [nodeL, nodeR]�� [L, R]�� ���� �� ��ġ�� ���. �ٷ� 0�� ����, 0�� ������ �տ� �����ϱ� ������
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]�� [L, R]�� ������ ���ԵǴ� ���. �ٷ� �ڽ��� ���� ����
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return querySum(L, R, node * 2, nodeL, mid) + querySum(L, R, node * 2 + 1, mid + 1, nodeR);
}
int main() {

	cin >> N >> K;

	rangeSum.resize(4 * MAX);

	for (int i = 1; i <= N; ++i) 
		update(i, 1, 1, 1, N);

	//�� ó�� K��° ���ڿ� ���� ó��
	vector<int> answer;
	answer.push_back(K);
	update(K, 0, 1, 1, N);

	int size = N - 1;
	for (int i = 2; i <= N; ++i) {
		//1���� answer.back()������ �� ���� ���ڰ� �����ִ� ���� ���� �˾Ƴ���
		//�� ���ڿ� K��ŭ ���� ��, �����ִ� ��ü ���� ����(size)�� modulo���� ����
		int pos = (querySum(1, answer.back(), 1, 1, N) + K) % size;
		//pos�� 0�� ���� ����ó��
		if (!pos) pos = size;
		//pos��° ���ڸ� answer�� push_back
		answer.push_back(query(pos, 1, 1, N));
		//pos��° ���ڸ� ���ݴٰ� update
		update(answer.back(), 0, 1, 1, N);
		//��ü ���� ������ 1 ����
		size--;
	}
	cout << "<";
	for (int i = 0; i < answer.size(); ++i)
		(i == answer.size() - 1) ? cout << answer[i] << ">\n" : cout << answer[i] << ", ";
	return 0;
}