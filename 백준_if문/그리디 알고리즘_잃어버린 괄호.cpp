//���� ���� ������ �� �۰� ����� ����
#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0, sum = 0;
	string str, tmp = "";
	cin >> str;

	for (int i = 0; i <= str.size(); ++i) { 
		if (str[i] == '-' || str[i] == '+' || str[i] == NULL) {
			//���ڿ����� �ι����� ������ �ַ� ���ڿ��� ���� ��Ÿ���� ���̴�.
			//���帶�� ���̰� �ٸ����� ���ڿ��� ǥ���� ���� �޸� �Ҵ緮�� �������� �ʰ�,
			//�޸𸮿� ����� �� �ش� ���ڿ��� ���� ������� �𸣱� ������ �ι��ڰ� �ʿ��� ��
			if (cnt == 1) //'-'
				sum -= stoi(tmp);
			else
				sum += stoi(tmp);
			if (str[i] == '-')
				cnt = 1;
			tmp = "";
			continue;
		}
		else 
			tmp += str[i];
	}
	cout << sum << '\n';

	return 0;
}
