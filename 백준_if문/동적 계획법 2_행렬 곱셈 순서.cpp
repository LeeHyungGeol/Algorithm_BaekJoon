//다이나믹 프로그래밍(Dynamic Programming): 동적 계획법 - "중복되는 연산을 줄이자"
// 1. 큰 문제를 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

//모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<pair<int, int>> arr; //행렬의 크기 r과 c (1 ≤ r, c ≤ 500)
	int N, r, c;//행렬의 개수 N(1 ≤ N ≤ 500)
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> r >> c;
		arr.push_back(make_pair(r, c));
	}
	
	return 0;
}