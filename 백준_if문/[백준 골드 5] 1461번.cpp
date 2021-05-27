// 정렬 문제, 그리디 문제
// 각 책들의 위치를 양수, 음수로 나누어 배열에 입력 받은 후, 
// 가장 먼 책들(M개)를 제외하고, 차례로 책을 가져다 놓는다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Plus, Minus;

int main() {
	cin >> N >> M;

	int Max = 10001;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		if (temp > 0) {
			Plus.push_back(temp);
		}
		else {
			Minus.push_back(temp);
		}
		
	}

	sort(Plus.begin(), Plus.end());
	sort(Minus.begin(), Minus.end());

	for (int i = 0; i < N; ++i) {
		
	}

	return 0;
}