// ���ڿ�(¦��, Ȧ���� ���� ó��)(for (int i = 0; i + 1 < Arr.size(); i += 2))

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Count[] = { 3,	2,	1,	2,	3,	3,	3,	3,	1,	1,	3,	1,	3,	3,	1,	2,	2,	2,	1,	2,	1,	1,	2,	2,	2,	1 };
string Str;
vector<int> Arr, Temp;

int main() {
	cin >> Str;

	for (char c : Str) {
		Arr.push_back(Count[c - 'A']);
	}
	

	while (Arr.size() > 1) {
		Temp.clear();

		// �� ���̰� ¦����� ���� vector�� �־�����.
		for (int i = 0; i + 1 < Arr.size(); i += 2) {
			Temp.push_back((Arr[i] + Arr[i + 1]) % 10);
		}

		// Ȧ����� �� ������ ���� ���� ���� ó�����ش�.
		if (Arr.size() % 2 == 1) {
			Temp.push_back(Arr.back());
		}

		Arr = Temp;
	}

	if (Arr[0] % 2) {
		cout << "I'm a winner!" << '\n';
	}
	else {
		cout << "You're the winner?" << '\n';
	}

	return 0;
}