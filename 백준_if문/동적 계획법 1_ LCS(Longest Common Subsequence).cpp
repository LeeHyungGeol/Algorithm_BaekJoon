//LCS(Longest Common Subsequence)�� ���ϴ� ����
//1.���� ���ڰ� ������ 
//���������� LCS�� ���̿� + 1�� �Ѵ�.
//���⿡�� ���������� LCS�� ���̶� ���ʰ��� �ƴ϶� �밢��(���� ��)���� ���Ѵ�.
//�̴� �� ���ڿ����� �ش� �� ���ڸ� ���ϱ� ���� LCS�� ���̿� + 1�� �ϱ� ���ؼ� �̴�.
//2. ���� ���ڰ� �ٸ��ٸ�, 
//���� ���ڰ� ���ԵǾ� �ִ� ���� LCS, 
//��, ǥ������ ���� ���� ���� ū ���� ���Եȴ�.
//���� ���, [P, Y]�� ���� 'CAP'�� 'ACAY'�� ���� ���� ���� �ǰ�, 
//'P'�� 'Y'�� �ٸ��� ������ 'CA'�� 'ACAY'�� LCS�� ���̿� 'CAP'�� 'ACA'�� LCS�� ������ ū ���� ���Եȴ�.
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