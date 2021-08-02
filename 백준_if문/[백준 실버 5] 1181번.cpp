// 정렬(sort)문제
// 기본적인 정렬 문제
// algorithm라이브러리에 있는 sort()메서드를 사용해도 되고, 직접 구현해도 된다.
// 단, 같은 단어들은 한번만 출력하라는 조건이 있으므로 출력할 때 따로 처리해줘야 한다.

// 혹은 v.erase(unique(v.begin(), v.end()), v.end()); 를 사용해도 된다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> words;

bool compare(const string& a, const string& b);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		words.push_back(str);
	}

	sort(words.begin(), words.end(), compare);

	// 	v.erase(unique(v.begin(), v.end()), v.end());

	int cnt = 0;

	for (int i = 0; i < words.size(); ++i) {
		if (i == words.size() - 1) {
			cout << words[i] << '\n';
			break;
		}
		if (words[i] == words[i + 1]) {
			++cnt;
			continue;
		}
		if (cnt > 0) {
			cout << words[i] << '\n';
			cnt = 0;
			continue;
		}
		cout << words[i] << '\n';

	}

	return 0;
}

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}