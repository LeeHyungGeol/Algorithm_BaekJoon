// 그리디 문제

// left == i
// right == ind(i 다음에 있는 A가 아닌 문자)
// 1) (원점)0 -> i -> 0 -> ind : 2a + b
// 2) (원점)0 -> ind -> 0 -> i : a + 2b
// min(2a+b, a+2b) == a+b + min(a,b);
// a = i, b = n - ind
// -> step = min(step, i + n - ind + min(i, n - ind));

// [프로그래머스 레벨 2] 조이스틱 문제와 똑같다. 같이 풀어보는 것을 추천

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int TC;
string name;

int main() {
	cin >> TC;

	for (int tc = 0; tc < TC; ++tc) {
		cin >> name;
		int n = name.size();
		int step = n - 1;
		int answer = 0;

		for (int i = 0; i < n; ++i) {
			answer += min(name[i] - 'A', 'Z' - name[i] + 1);

			int left = i;
			int right = i + 1;

			while (right < n && name[right] == 'A') {
				++right;
			}

			step = min(step, left + n - right + min(left, n - right));
		}

		answer += step;

		cout << answer << '\n';
	}

	return 0;
}