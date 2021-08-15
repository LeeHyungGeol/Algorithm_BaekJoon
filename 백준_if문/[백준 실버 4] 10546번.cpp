// Hash를 사용한 Map 문제

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N;
map<string, int> Names;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		++Names[str];
	}

	for (int i = 0; i < N - 1; ++i) {
		string str;
		cin >> str;
		--Names[str];
	}
	
	for (auto name : Names) {
		if (name.second != 0) {
			cout << name.first << '\n';
		}
	}

	return 0;
}