// 문자열(alphabet[26] 빈도수 체크), getline(cin, string) + cin.ignore()

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string Str;
vector<int> Arr;
vector<int> Frequency(26, 0);
string Alphabet = "abcdefghijklmnopqrstuvwxyz";

int main() {
	cin >> N;

	//추가 안할 경우 getline에서 subscript range 에러 발생
	cin.ignore();

	for (int i = 0; i < N; ++i) {
		getline(cin, Str);
		Arr.clear();
		Frequency.assign(26, 0);

		for (int j = 0; j < Str.length(); ++j) {
			if (Str[j] == ' ') {
				continue;
			}
			int index = Str[j] - 'a';

			++Frequency[index];
		}

		bool flag = true;
		int maxFreq = -1, maxIndex = 0;

		for (int j = 0; j < 26; ++j) {
			if (maxFreq < Frequency[j]) {
				maxFreq = Frequency[j];
				maxIndex = j;
				flag = true;
			}
			else if (maxFreq == Frequency[j]) {
				flag = false;
			}
		}

		if (flag) {
			cout << Alphabet[maxIndex] << '\n';
		}
		else {
			cout << "?" << '\n';
		}
	}

	return 0;
}
