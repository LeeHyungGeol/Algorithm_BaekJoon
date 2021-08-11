// dp(다이나믹 프로그래밍) 문제

// Dp배열에 항상 그 인덱스에 해당하는 Snacks[i] 값은 기본 값으로 갖고 있어야 하므로, 초기화시켜준다.
// 뒤에 나오는 과자의 만족도가 앞에 나오는 과자의 만족도 보다 커야 하므로
// j < i 일때, Snacks[j] < Snacks[i] 이라면, 지금까지의 값들 중 최댓값(Dp[j])에다가 Snacks[i]를 더해준다.

// 라이브러리 algorithm의 max_element(vector.begin(), vector.end())
// -> vector의 최댓값 반환

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Answer;
vector<int> Snacks;
vector<int> Dp;

int main() {
	cin >> N;

	Snacks.resize(N, 0);
	Dp.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> Snacks[i];
	}

	Answer = Dp[0] = Snacks[0];

	for (int i = 1; i < N; ++i) {
		Dp[i] = Snacks[i];

		for (int j = 0; j < i; ++j) {
			if (Snacks[j] < Snacks[i]) {
				Dp[i] = max(Dp[i], Dp[j] + Snacks[i]);
			}
		}
	}
	

	/*for (int i = 0; i < Dp.size(); ++i) {
		Answer = max(Answer, Dp[i]);
	}
	
	cout << Answer << '\n';*/

	cout << *max_element(Dp.begin(), Dp.end()) << '\n';

	return 0;
}