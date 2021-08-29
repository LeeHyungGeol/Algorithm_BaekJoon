// ���ڿ� �˰���(KMP) ����

// Ŀ����-�𸮽�-����(KMP)���ڿ� �˻� �˰��� ����
// '¤����' H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ������ġ���� ��� ��ȯ
// �ð����⵵: O(H) + O(N)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S, P;

vector<int> getPartialMatch(const string& N);
vector<int> kmpSearch(const string& H, const string& N);

int main() {
	cin >> S >> P;

	vector<int> answer = kmpSearch(S, P);

	if (answer.size() > 0) {
		cout << "1" << '\n';
	}
	else {
		cout << "0" << '\n';
	}

	return 0;
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