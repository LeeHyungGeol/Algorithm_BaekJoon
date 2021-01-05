//https://hooongs.tistory.com/308
//���� �ϳ��ϳ��� �ε����� �Ͽ� '0' �Ǵ� '1'�� ä�� ��(bool���� �Ȱ���)
//parent�� �ش��ϴ� ���ڿ��� str = str + str ���� 2�踦 ���� �� pattern�� ã���ش�.
//ȯ������ - ȯ�����ڿ����� �κ� ���ڿ��� ��ġ�ϴ� ��찡 �ִ��� Ȯ���ϴ� ����
//https://jaimemin.tistory.com/702
//��û ����ߴ� ����
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int matched = 0, begin = 1;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
bool kmpSearch(const string& H, const string& N) {
	int m = N.size(), n = H.size();
	vector<int> pi = getPartialMatch(N);
	int matched = 0, begin = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m)
				return true;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return false;
}
int main() {
	/*string s = "140 130 110 120 125 100 105";
	int num = 0;
	string n = to_string(num);
	vector<int> ret = kmpSearch(s, n);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << ' ';
	}
	cout << '\n';*/
	string str1, str2;
	for (int i = 0; i < 360000; ++i) {
		str1 += '0';
		str2 += '0';
	}
	cin >> N;
	int num;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		str1[num] = '1';
	}
	for (int i = 0; i < N; ++i) {
		cin >> num;
		str2[num] = '1';
	}
	str1 = str1 + str1;
	(kmpSearch(str1, str2)) ? cout << "possible" << '\n' : cout << "impossible" << '\n';
	return 0;
}