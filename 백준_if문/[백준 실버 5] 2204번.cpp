#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<string> Changed;
map<string, string> Map;

int main() {
	while (cin >> N) {
		if (N == 0) {
			break;
		}

		Map.clear();
		Changed.clear();

		for (int i = 0; i < N; ++i) {
			string str, changed;
			cin >> str;
			changed = str;
			for (int j = 0; j < changed.length(); ++j) {
				changed[j] = tolower(changed[j]);
			}
			Map[changed] = str;
			Changed.push_back(changed);
		}

		sort(Changed.begin(), Changed.end());

		cout << Map[Changed[0]] << '\n';
	}
	
	return 0;
}