#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int Answer;
string str;
vector<vector<int>> Ducks;
map<char, int> Duck = { {'q',0}, {'u',1}, {'a',2}, {'c',3}, {'k',4} };

int main() {
	cin >> str;

	bool flag = true;

	for (int i = 0; i < str.length(); ++i) {
		int index = Duck[str[i]];
		bool check = false;

		for (int j = 0; j < Ducks.size(); ++j) {
			if (((Ducks[j].back() + 1) % 5) == index) {
				Ducks[j].push_back(index);
				check = true;
				break;
			}
		}

		if (!check) {
			if (index == 0) {
				Ducks.push_back({ 0 });
			}
			else {
				flag = false;
			}
		}
	}

	for (int i = 0; i < Ducks.size(); ++i) {
		if (Ducks[i].back() != 4) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << Ducks.size() << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}