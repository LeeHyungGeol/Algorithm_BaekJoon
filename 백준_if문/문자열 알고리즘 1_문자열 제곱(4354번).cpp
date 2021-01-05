//KMP�� failure function�� Ȱ���ϴ� ���� 1
//������ �����Լ�(getPartialMatch) ���� �߿�
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
vector<int> getPartialMatch1(const string& N) {
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
vector<int> kmpSearch1(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> pi = getPartialMatch1(N);
	vector<int> ret;
	int begin = 0, matched = 0;
	while (begin + m <= n) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m)
				ret.push_back(begin);
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
	return ret;
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
vector<int> kmpSearch2(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch2(N);
	int matched = 0;
	for (int begin = 0; begin < n; ++begin) {
		while (matched > 0 && H[begin] != N[matched]) {
			matched = pi[matched - 1];
		}
		if (H[begin] == N[matched]) {
			++matched;
			if (matched == m) {
				ret.push_back(begin - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
int main() {
	while (true) {
		getline(cin, s);
		if (s == ".")
			break;
	
		vector<int> pi = getPartialMatch2(s);
		int inputSize = s.size();
		int finalIndex = pi.size() - 1;
		if (inputSize % (inputSize - pi[finalIndex]) != 0)
			//ababa�� ���� ������ ���� �Լ� ���� 0�� �ƴ� ���� �����Ƿ�
			//��ü ���ڿ� ���� % �ݺ��Ǵ� ���ڿ��� ���̰� 0���� �ƴ����� ��
			cout << "1" << '\n';
		else
			cout << inputSize / (inputSize - pi[finalIndex]) << '\n';
	}
	return 0;
}