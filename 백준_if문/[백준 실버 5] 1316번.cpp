// ���ڿ� ����
// �������� �� �� �ϴٰ� ���� �ɸ� ����
// string.find(str[i]) �� ������� Ǯ� �ǰ�,
// Alphabet[26] �迭�� ������, ������ ���ĺ� ������ ���� ������� ������ Ǯ� �ȴ�.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, Count;
vector<int> Alphabet(101, 0);
string str;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> str;
		//Alphabet.assign(101, 0);
		Alphabet.assign(26, 0);

		if (str.length() == 1) {
			++Count;
			continue;
		}

		//int index = str.find(str[0]);
		int index = str[0] - 'a';
		++Alphabet[index];

		for (int j = 1; j < str.length(); ++j) {
			//int index = str.find(str[j]);
			int index = str[j] - 'a';
			if (Alphabet[index] != 0 && str[j - 1] != str[j]) {
				break;
			}
			else {
				++Alphabet[index];
			}

			if (j == str.length() - 1) {
				++Count;
			}
		}
	}

	cout << Count << '\n';

	return 0;
}