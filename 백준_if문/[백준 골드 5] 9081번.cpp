#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int T;
string Str, Answer;

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> Str;

		int cnt = 0;

		do {
			Answer = Str;
			if (++cnt == 2) {
				break;
			}
		} while (next_permutation(Str.begin(), Str.end()));


		cout << Answer << '\n';
	}

	return 0;
}


//-----------2번째 풀이(순열 구현)--시간초과----------------//

#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int T;
string Str;
vector<bool> Select;
set<string> Ranks;

void dfs(string str, int cnt);

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> Str;
		
		Ranks.clear();
		Select.assign(Str.length(), false);

		dfs("", 0);

		for (auto it = Ranks.begin(); it != Ranks.end(); ++it) {
			if (*it == Str) {
				++it;
				if (it == Ranks.end()) {
					cout << Str << '\n';
				}
				else {
					cout << *it << '\n';
				}
				break;
			}
		}
	}
	
	return 0;
}

void dfs(string str, int cnt) {
	if (cnt == Str.length()) {
		Ranks.insert(str);
		return;
	}

	for (int i = 0; i < Select.size(); ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		str.push_back(Str[i]);
		dfs(str, cnt + 1);
		str.pop_back();
		Select[i] = false;
	}
}