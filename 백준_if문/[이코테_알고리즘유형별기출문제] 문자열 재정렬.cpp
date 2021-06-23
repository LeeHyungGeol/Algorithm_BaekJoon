// �⺻ ���� ����
// ���ڿ��� �Է� �޾Ƽ�, ������ �� ���ڸ��� ���� ó���ϴ� ����
// ���ڿ� ���ڰ� ���� ���� �� �����ϸ�, ���ڰ� ���ʿ� ��ġ�ϰ� �ȴ�.

// isalnum(����): ������ �Ǵ� ������ ��츸 ���� ���� 
// isalpha(����) : ���ڰ� �������� ��츸 ���� ����
// isdigit(����) : ���ڰ� ������ ��츸 ���� ����
// islower(����) : ���ڰ� ���� �ҹ����� ��츸 ���� ����
// isupper(����) : ���ڰ� ���� �빮���� ��츸 ���� ����

// ������ �Լ��� ���� �Ű������� Ÿ���� 'char (����)' �̴�.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int number;

int main() {
	cin >> str;

	sort(str.begin(), str.end());

	auto it = str.begin();

	while (isdigit(*it)) {
		number += *it - '0';
		str.erase(it);
	}

	str += to_string(number);

	cout << str << '\n';

	return 0;
}