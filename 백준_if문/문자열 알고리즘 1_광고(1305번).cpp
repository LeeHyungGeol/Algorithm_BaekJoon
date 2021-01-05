//aabaa
//pi  0 1 0 1 2
//Pi[N] : ó�� ��ġ���� ������� �� ������ �� ���� ����
//N - Pi[N - 1] : �ִ밡 N�̰� �� ������ �� �Ÿ� ��ŭ ���ָ� �� �������� ���� �ɼ� �ִ� ���� ª�� ���̶�� �Ǵ�
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int L;
string s;
vector<int> getPartialMatch1(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int matched = 0, begin = 1;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			pi[begin + matched - 1] = ++matched;
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
vector<int> getPartialMatch2(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int matched = 0;
	for (int begin = 1; begin < m; ++begin) {
		while (matched > 0 && N[begin] != N[matched]) {
			matched = pi[matched - 1];
		}
		if (N[begin] == N[matched]) {
			pi[begin] = ++matched;
		}
	}
	return pi;
}
int main() {
	cin >> L;
	getchar();
	getline(cin, s);
	vector<int> pi = getPartialMatch1(s);
	/*for (int i = 0; i < pi.size(); ++i) {
		cout << pi[i] << ' ';
	}
	cout << '\n';*/
	int finalIndex = pi.size() - 1;
	cout << s.size() - pi[finalIndex] << '\n';
	return 0;
}