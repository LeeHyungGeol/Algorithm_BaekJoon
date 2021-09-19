#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define INF 1e9

using namespace std;

int Min = INF, Max = 0;
string Str;

void makeOdd(string s, int total);
int check(string s);
void dfs(string s, int total, vector<bool>& select, int startIndex, int cnt);

int main() {
	cin >> Str;

	makeOdd(Str, 0);
	
	cout << Min << ' ' << Max << '\n';

	return 0;
}

void makeOdd(string s, int total) {
	if (s.length() == 1) {
		total += check(s);
		Min = min(Min, total);
		Max = max(Max, total);
		return;
	}
	else if (s.length() == 2) {
		string s1 = "", s2 = "";
		s1 += s[0];
		s2 += s[1];

		string newStr = to_string(s[0] - '0' + s[1] - '0');
		int newCount = check(s1) + check(s2);
		makeOdd(newStr, total + newCount);
	}
	else if (s.length() >= 3) {
		vector<bool> select(s.length() - 1, false);
		dfs(s, total, select,0, 0);
	}
}

int check(string s) {
	int cnt = 0;

	for (int i = 0; i < s.length(); ++i) {
		if ((s[i] - '0') % 2 == 1) {
			++cnt;
		}
	}

	return cnt;
}

void dfs(string s, int total, vector<bool>& select, int startIndex, int cnt) {
	if (cnt == 2) {
		vector<int> selected;
		
		for (int i = 0; i < select.size(); ++i) {
			if (select[i]) {
				selected.push_back(i);
			}
		}

		string s1 = s.substr(0, selected[0] + 1);
		string s2 = s.substr(selected[0] + 1, selected[1] - selected[0]);
		string s3 = s.substr(selected[1] + 1, s.length() - 1 - selected[1]);

		string newStr = to_string(stoi(s1) + stoi(s2) + stoi(s3));
		int newCount = check(s1) + check(s2) + check(s3);
		makeOdd(newStr, total + newCount);
		return;
	}

	for (int i = startIndex; i < select.size(); ++i) {
		if (select[i]) {
			continue;
		}
		select[i] = true;
		dfs(s, total, select, i, cnt + 1);
		select[i] = false;
	}
}