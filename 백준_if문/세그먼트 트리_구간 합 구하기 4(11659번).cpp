//세그먼트 트리(구간 트리): 구간에 대한 질문 대답하기 
//구간 합 문제: 연속적으로 나열된 N개의 수가 있을 때, ""특정 구간의 모든 수를 합한 값을 계산""하는 문제

//N개의 정수로 구성된 수열이 있다.
//M개의 쿼리(Query) 정보가 주어진다.
//	-각 쿼리는 Left와 Right으로 구성된다.
//	-각 쿼리에 대하여 [Left, Right]구간에 포함된 데이터들의 합을 출력해야 한다.
//수행 시간 제한은 O(N + M)이다.

//접두사 합(Prefix Sum): 배열의 맨 앞부터 특정 위치까지의 합을 미리 구해 놓은 것

//접두사 합(Prefix Sum)을 활용한 알고리즘
//	- N개의 수 위치 각각에 대하여 접두사 합을 계산하여 P(배열)에 저장한다.
//	- 매 M개의 쿼리 정보를 확인할 때 구간 합은 P[Rigjt] - P[Left - 1]이다.

#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
int N, M;
int PrefixSum[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int tmp,sum=0;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		sum += tmp;
		PrefixSum[i + 1] = sum;
	}

	int right, left;
	for (int i = 0; i < M; ++i) {
		cin >> left >> right;
		cout << PrefixSum[right] - PrefixSum[left - 1] << '\n';
	}
	return 0;
}