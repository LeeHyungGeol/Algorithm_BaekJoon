// ����(sort)����
// �⺻���� ���� ����
// algorithm���̺귯���� �ִ� sort()�޼��带 ����ص� �ǰ�, ���� �����ص� �ȴ�.
// ��, ���� �ܾ���� �ѹ��� ����϶�� ������ �����Ƿ� ����� �� ���� ó������� �Ѵ�.

// Ȥ�� v.erase(unique(v.begin(), v.end()), v.end()); �� ����ص� �ȴ�.

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