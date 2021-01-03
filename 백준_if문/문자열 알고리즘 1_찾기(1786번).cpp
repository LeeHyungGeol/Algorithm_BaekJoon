//https://jhnyang.tistory.com/107 - getline() �Լ� ���� ����Ʈ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string H; //'¤����' H(Haystack)
string N; //'�ٴ�' N(Needle)

//�ܼ��� ���ڿ� �˰����� �̿��� �κ� ��ġ ���̺�(pi) ���
//N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿��� pi[]�� ����Ѵ�.
//pi[i]�� N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� �����̴�. 
//�ð� ���⵵: O(N^2)
vector<int> getPartialMatchNative(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	for (int begin = 1; begin < m; ++begin) {
		for (int i = 0; begin + i < m; ++i) {
			if (N[begin + i] != N[i]) break;
			//i+1 ���ڰ� ���� �����Ǿ���.
			//���纸�� ���ʿ� �ִ� ���� ��ġ���� ���� �̹� ���� �������� �𸣱� ������ max�Լ��� �̿�
			pi[begin + i] = max(pi[begin + i], i + 1);
		}
	}
	return pi;
}
//'¤����' H(Haystack)�� �κ� ���ڿ��� '�ٴ�' N(Needle)�� �����ϴ� ������ġ���� ��� ��ȯ
//���� ������ ������� N�� ������ ��� ���ڿ� ���� ��ġ�� �õ��� ���� ���̴�.
//�ð� ���⵵: O(N*H)
vector<int> nativeSearch(const string& H, const string& N) {
	vector<int> ret;
	//��� ���� ��ġ�� ���� �õ��غ���
	for (int begin = 0; begin + N.size() <= H.size(); ++begin) {
		bool matched = true;
		for (int i = 0; i < N.size(); ++i) {
			if (H[begin + i] != N[i]) {
				matched = false;
				break;
			}
		}
		if (matched)
			ret.push_back(begin);
	}
	return ret;
}
//N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ���ġ�� �̿��� pi[]�� ����Ѵ�.
//pi[i]�� N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� �����̴�.
//�ð����⵵: O(N)
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP�� �ڱ� �ڽ��� ã�´�.
	//N�� N���� ã�´�. begin=0 ���� �����ϸ�, �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵȴ�.
	int begin = 1, matched = 0;
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
//Ŀ����-�𸮽�-����(KMP)���ڿ� �˻� �˰��� ����
//'¤����' H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ������ġ���� ��� ��ȯ
//�ð����⵵: O(H) + O(N)
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size();
	int m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N); //�ð����⵵: O(N)

	//begin = matched = 0 �������� ���� 
	int begin = 0, matched = 0;
	while (begin <= n - m) {//begin + N.size() <= H.size()
		//���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
		//while�� ������ begin + matched�� ���� �������� �ʴ´�.
		//matched�� ������ ���� begin�� �׻� �� ���Һи�ŭ �����ϱ� ������ ���� ���� ������ �ʴ´�.
		//����, �ѹ� matched�� �����ϰ� ����, H[begin + matched]�� �ٽ� ������ ���� ����.
		//�� �б�� �ִ� O(H)�� ����
		if (matched < m && H[begin + matched] == N[matched]) {//matched<m�� ��� ����� ����
			++matched;
			//��������� m���ڰ� ��� ��ġ�ߴٸ� �信 �߰�
			if (matched == m)
				ret.push_back(begin);
		}

		else {//begin�� H.size()-N.size()�� �ʰ��ϸ� ���� �����ϱ� ������, �� �б⵵ �ִ� O(H)�� �����Ѵ�.

			//����: �� ���ڵ� ��ġ���� �ʴ� ��쿡�� ���� ĭ�������� ã�� ���� ����Ѵ�.
			if (matched == 0) 
				++begin;
			else {
				begin += matched - pi[matched - 1];
				//begin�� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
				//�ű� �Ŀ��� pi[matched - 1]��ŭ�� �׻� ��ġ�ϱ� �����̴�.
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
vector<int> getPartialMatchTable(const string& N) {
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
	vector<int> ret;
	vector<int> pi = getPartialMatchTable(N);
	int n = H.size(), m = N.size();
	//���� ������ ���� ��
	int matched = 0;
	//H�� �� ���ڸ� ��ȸ�Ѵ�. 
	for (int begin = 0; begin < n; ++begin) {
		//matched�� ���ڿ� H�� �ش� ���ڰ� ����ġ �� ���
		//���� ������ ������ �� pi[matched - 1]�� ���δ�.
		while (matched > 0 && H[begin] != N[matched]) {
			matched = pi[matched - 1];
		}
		//���ڰ� ������ ���
		if (H[begin] == N[matched]) {
			++matched;
			if (matched == m) {
				ret.push_back(begin - m + 1);
				//���ڰ� ��� ��ġ�� ��쿡�� ���� ��ġ�� �����ؾ��ϱ� ������ N�� ���̻� ���� ��ŭ matched�̵�
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
int main() {
	getline(cin, H);
	getline(cin, N);
	//cout << H << '\n';
	//cout << N << '\n';
	vector<int> answer = kmpSearch2(H, N);
	cout << answer.size() << '\n';
	for (auto it : answer) {
		cout << it + 1 << '\n';
	}
	/*for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] + 1 << '\n';
	}*/
	return 0;
}