// �׸���(Ž���) ,��� ����

// � ��쿡 ũ�Ⱑ 10�� cake�� ���� ���� ���� �� �ִ��� �����Ѵ�.
// 1. ũ�Ⱑ 10���� ������ �������� cake���� ���� �߶� ������ ���Ѵ�.
// 2. ũ�Ⱑ 10���� �ϴ��� �������� ����ũ�� �߿��� ũ�Ⱑ ���� ������ ���� ������ ���Ѵ�.
// EX) 10, 20, 30, 40... ������ ���� ���ؾ� �Ѵ�.
// �ֳ��ϸ�, 10�� ���� M�� �Ҹ����� �ʰ� ���� ���� �� �ְ�, 
// 20�� 4���� ���, 4���� �ڸ����� 8���� ���� �� ������, 50�� ��� �Ȱ��� 4���� �ڸ����� 5�� �ۿ� ���� ���ϱ� �����̴�. 

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