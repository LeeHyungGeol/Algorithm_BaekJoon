#include <iostream> //cin.eof()
using namespace std;

int main() {
	//��Ȥ, �˰��� �������� �Է°��� ������ �־����� �ʴ� ��찡 �ִ�. 
	//�̴� ������ ����ɶ����� �Է��� ������� �ǹ��̹Ƿ�, cin.eof()�� ����ϸ� �ȴ�.
	//*boolŸ���� ������.
	//*���� ������ ���� �ǹ��ϴ� EOF�� �а� �Ǹ�, true������ �ٲ�� �ȴ�.
	//*�ܼ� â������ EOF�� �������� �־��־�� �Ѵ�.�̶�, ������ ���� ctrl + z�� EOF�� �ǹ��Ѵ�.
	//*EOF�� ��� - 1�� ���ǵǾ� �ִ�.
	// EOF == End Of File

	int num1 = 1, num2 = 1;

	while (true) {    //EOF�� ���������� ���� �Է�
		cin >> num1 >> num2;
		if (cin.eof() == true)
			break;
		cout << num1 + num2 << '\n';
	}

	//while (scanf("%d %d", &a, &b) != EOF)
	//EOF == End Of File
	//���״�� ������ ���� �����ϸ� EOF�� �����Ѵ�
	//������ �迭���� ���Ƿ� �߻���Ű�� ���ؼ� Ctrl + Z�� ������ �ȴٰ�.. 
	//	printf("%d\n", a + b);

	return 0;
}