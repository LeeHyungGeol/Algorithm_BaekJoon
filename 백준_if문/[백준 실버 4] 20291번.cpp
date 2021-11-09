#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> Map;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		int index = str.find('.');
		string extension = str.substr(index + 1);
		++Map[extension];
	}

	for (auto it = Map.begin(); it != Map.end(); ++it) {
		cout << it->first << ' ' << it->second << '\n';
	}

	return 0;
}