#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int Max = -INT_MAX, Min = INT_MAX;
string N;

int countOdd(string str);
void operation(string n, int total);
void dfs(string n, vector<bool>& select, int total, int startIndex, int cnt);

int main() {
	cin >> N;

	operation(N, 0);

	cout << Min << ' ' << Max << '\n';

	return 0;
}

void operation(string n, int total) {
	if (n.length() == 1) {
		total += countOdd(n);
		Max = max(Max, total);
		Min = min(Min, total);
		return;
	}
	else if (n.length() == 2) {
		int result = countOdd(n);
		operation(to_string((n[0] - '0') + (n[1] - '0')), total + result);
	}
	else {
		vector<bool> select(n.length() - 1, false);
		dfs(n, select,total, 0, 0);
	}
}

void dfs(string n, vector<bool>& select,int total, int startIndex, int cnt) {
	if (cnt == 2) {
		vector<int> index;

		for (int i = 0; i < select.size(); ++i) {
			if (select[i]) index.push_back(i);
		}
		
		int result = countOdd(n);
		string n1 = n.substr(0, index[0] + 1);
		string n2 = n.substr(index[0] + 1, index[1] - index[0]);
		string n3 = n.substr(index[1] + 1);
		operation(to_string(stoi(n1) + stoi(n2) + stoi(n3)), total + result);
		return;
	}

	for (int i = startIndex; i < select.size(); ++i) {
		if (select[i]) continue;
		select[i] = true;
		dfs(n, select, total, i, cnt + 1);
		select[i] = false;
	}
}

int countOdd(string str) {
	int cnt = 0;
	for (char c : str) {
		int n = c - '0';
		if (n % 2) ++cnt;
	}
	return cnt;
}