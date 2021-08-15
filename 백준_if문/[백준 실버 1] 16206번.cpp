// 그리디(탐욕법) ,재귀 문제

// 어떤 경우에 크기가 10인 cake를 가장 많이 구할 수 있는지 생각한다.
// 1. 크기가 10으로 나누어 떨어지는 cake들을 먼저 잘라서 갯수를 구한다.
// 2. 크기가 10으로 니누어 떨어지는 케이크들 중에서 크기가 작은 순으로 먼저 갯수를 구한다.
// EX) 10, 20, 30, 40... 순으로 먼저 구해야 한다.
// 왜냐하면, 10인 경우는 M을 소모하지 않고도 값을 구할 수 있고, 
// 20이 4개인 경우, 4번의 자름으로 8개를 얻을 수 있지만, 50인 경우 똑같이 4번의 자름으로 5개 밖에 얻지 못하기 때문이다. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Answer;
vector<int> divideByTen, notDivideByTen;

void cut(int x);

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x < 10) {
			continue;
		}
		else if (x % 10 == 0) {
			divideByTen.push_back(x);
		}
		else {
			notDivideByTen.push_back(x);
		}
	}

	sort(divideByTen.begin(), divideByTen.end());

	for (int i = 0; i < divideByTen.size(); ++i) {
		if (M <= 0) {
			break;
		}
		if (divideByTen[i] == 10) {
			++Answer;
		}
		else {
			cut(divideByTen[i]);
		}
	}

	for (int i = 0; i < notDivideByTen.size(); ++i) {
		if (M <= 0) {
			break;
		}
		cut(notDivideByTen[i]);
	}

	cout << Answer << '\n';

	return 0;
}

void cut(int x) {
	if (M <= 0) {
		return;
	}
	else {
		x -= 10;
		++Answer;
		--M;
		if (x > 10) {
			cut(x);
		}
		else if (x == 10) {
			++Answer;
		}
	}
	return;
}