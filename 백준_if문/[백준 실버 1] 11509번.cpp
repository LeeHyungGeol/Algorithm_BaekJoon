// 그리디(탐욕법) 문제
// 입력 받는 N의 크기 만큼 배열을 선언하여, 
// 차례대로 수를 배열에 입력 받으면서, 배열의 인덱스(index)를 입력값이라고 생각하고
// 배열의 값이 0이면(Heights[h] == 0), ++Heights[h-1]을 해주고(height가 1 작은 화살 추가), ++Answer
// 배열의 값이 존재한다면, --Heights[h], 를 해주고, ++Heights[h-1]를 해준다.

#include <iostream>
#include <vector>

using namespace std;

int N, Answer;
vector<int> Heights;

int main() {
	cin >> N;

	Heights.resize(1000001, 0);
	
	int h = 0;

	for (int i = 0; i < N; ++i) {
		cin >> h;
		if (Heights[h] == 0) {
			++Heights[h - 1];
			++Answer;
		}
		else {
			--Heights[h];
			++Heights[h - 1];
		}
	}
	
	cout << Answer << '\n';

	return 0;
}