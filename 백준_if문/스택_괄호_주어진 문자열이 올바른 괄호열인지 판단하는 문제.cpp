//�־��� ���ڿ��� �ùٸ� ��ȣ������ �Ǵ��ϴ� ����
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	string str;
	int T, cnt = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> str;
		stack<char> stack;
		cnt = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				stack.push(str[j]);
				cnt++;
			}
			else {
				if (stack.empty()) {
					cout << "NO" << '\n';
					cnt = -100;//�ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̹Ƿ� 
					break;
				}
				stack.pop();
				cnt--;
			}
		}
		if (cnt == -100) { //���� ���ǹ����� break�� for���� �������� ���, 
			continue;      //NO Ȥ�� YES�� ��� �� ���� �����ϱ� ���� -100(cnt�� ����� �� �� ���� ��)���� ����  
		}
		else if (cnt != 0)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

	return 0;
}