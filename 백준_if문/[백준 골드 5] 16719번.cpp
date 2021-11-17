#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> psi;

string Str;
vector<bool> Visited;

int main() {
	cin >> Str;

	Visited.assign(Str.length(), false);

	for (int i = 0; i < Str.length(); ++i) {
		vector<psi> temp;
		for (int j = 0; j < Str.length(); ++j) {
			if (Visited[j]) continue;
			string str = "";
			for (int k = 0; k < Str.length(); ++k) {
				if (j == k || Visited[k]) str.push_back(Str[k]);
			}
			temp.push_back({ str,j });
		}
		sort(temp.begin(), temp.end());
		cout << temp.front().first << '\n';
		Visited[temp.front().second] = true;
	}

	return 0;
}