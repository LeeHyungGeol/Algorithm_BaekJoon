#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string str1, str2;
int dp[1001][1001] = { 0 };
int main() {
	int maxLength = 0;
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			if (str1[i - 1] == str2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			maxLength = max(maxLength, dp[i][j]);
		}
	}
	cout << maxLength << '\n';
	stack<char> s;
	int i = str1.size();
	int j = str2.size();
	while (dp[i][j] != 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			s.push(str2[j - 1]);
			i--;
			j--;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';
	return 0;
}