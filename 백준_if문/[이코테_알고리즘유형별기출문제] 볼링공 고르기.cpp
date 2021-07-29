// 그리디(탐욕법)
// 첫 번째 풀이 : 2중 반복문을 이용하여 모든 조합을 직접 count하였다.
// 두 번째 풀이(정석 풀이) : 볼링공의 무게가 1~10 까지 정해져 있기 때문에
// 반복문을 1번만 돌면서 각각의 갯수에서 사람수를 곱하면서 조합의 갯수를 계산 가능하다.

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> balls;
// 무게가 1~10인 볼링공의 갯수를 다는 배열
int weights[11] = { 0, };

void solution1();
void solution2();

int main() {

	//solution1();

	solution2();

	return 0;
}

void solution1() {
	cin >> N >> M;

	balls.resize(N, { 0,0 });

	for (int i = 0; i < N; ++i) {
		int weight;
		cin >> weight;
		balls[i] = { i + 1, weight };
	}

	int cnt = 0;

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (balls[i].second != balls[j].second) {
				++cnt;
			}
		}
	}

	cout << cnt << '\n';
}

void solution2() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int w;
		cin >> w;
		++weights[w];
	}

	int cnt = 0;

	// 무게가 1부터 M까지 무게의 볼링공에 대한 처리
	for (int i = 1; i <= M; ++i) {
		// 무게가 i인 볼링공의 개수(A가 선택할 수 있는 개수 제외)
		N -= weights[i];
		// A가 선택한 경우의 수(weights[i])와 B가 선택하는 경우의 수(N) 곱하기
		cnt += weights[i] * N;
	}

	cout << cnt << '\n';
}