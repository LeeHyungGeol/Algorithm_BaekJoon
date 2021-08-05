// ���Ʈ����, ���ڿ� ����
// ���ڿ��� 3����ؼ� �������� ������(reverse), �ּ� ���ڿ��� ã�� ����

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Length;
string str, answer = "";

void split(int first, int second);

int main() {
	cin >> str;

	Length = str.length();

	for (int i = 0; i < Length - 1; ++i) {
		for (int j = i + 1; j < Length - 1; ++j) {
			split(i, j);
		}
	}

	cout << answer << '\n';

	return 0;
}

void split(int first, int second) {
	string a, b, c;

	for (int i = 0; i <= first; ++i) a += str[i];
	for (int i = first+1; i <= second; ++i) b += str[i];
	for (int i = second+1; i < Length; ++i) c += str[i];

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());

	string temp = a + b + c;

	if (answer == "") {
		answer = temp;
	}
	else {
		answer = min(answer, temp);
	}
}