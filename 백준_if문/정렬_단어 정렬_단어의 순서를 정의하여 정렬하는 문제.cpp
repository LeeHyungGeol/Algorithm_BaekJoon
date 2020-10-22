#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b);
int main() {
	vector<string> v;
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(),v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end()); //����_�ߺ� ����
	//unique �Լ��� �հ� ���� ���ҵ��� ���ϱ� ������ �ݵ�� ������ �� �� �����ؾ� �մϴ�.
	//[�������� �ʾ��� ��] 1 2 1 �� 1 ���̿� 2�� �־ �������� �ʾ����� 
	//5 5�� �߰��� ��� ���� ���� ���������� ��Ÿ���� �ߺ��� ���ҷ� �ǴܵǾ��ٴ� ���� Ȯ���� �� �ֽ��ϴ�.

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << '\n';
	}
	return 0;
}
bool compare(const string& a, const string& b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

