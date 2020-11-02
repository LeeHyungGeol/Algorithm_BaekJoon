//LCS(Longest Common Subsequence)를 구하는 문제
//1.같은 문자가 나오면 
//이전까지의 LCS의 길이에 + 1을 한다.
//여기에서 이전까지의 LCS의 길이란 왼쪽값이 아니라 대각선(왼쪽 위)값을 말한다.
//이는 두 문자열에서 해당 두 문자를 비교하기 전의 LCS의 길이에 + 1을 하기 위해서 이다.
//2. 비교한 문자가 다르다면, 
//비교한 문자가 포함되어 있는 직전 LCS, 
//즉, 표에서는 위와 왼쪽 값중 큰 값이 오게된다.
//예를 들면, [P, Y]의 값은 'CAP'와 'ACAY'를 비교한 값이 오게 되고, 
//'P'와 'Y'는 다르기 때문에 'CA'와 'ACAY'의 LCS의 길이와 'CAP'와 'ACA'의 LCS의 길이중 큰 값이 오게된다.
//https://mygumi.tistory.com/126
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001] = { 0 };

int main() {
	int maxlength = 0; 
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[str1.size()][str2.size()] << '\n';
	return 0;
}