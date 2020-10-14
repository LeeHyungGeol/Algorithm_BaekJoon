#include <iostream> //cin.eof()
using namespace std;

int main() {
	//간혹, 알고리즘 문제에서 입력값의 범위가 주어지지 않는 경우가 있다. 
	//이는 파일이 종료될때까지 입력을 받으라는 의미이므로, cin.eof()를 사용하면 된다.
	//*bool타입을 가진다.
	//*만약 파일의 끝을 의미하는 EOF를 읽게 되면, true값으로 바뀌게 된다.
	//*콘솔 창에서는 EOF를 수동으로 넣어주어야 한다.이때, 윈도우 기준 ctrl + z가 EOF를 의미한다.
	//*EOF는 상수 - 1로 정의되어 있다.
	// EOF == End Of File

	int num1 = 1, num2 = 1;

	while (true) {    //EOF를 만날때까지 무한 입력
		cin >> num1 >> num2;
		if (cin.eof() == true)
			break;
		cout << num1 + num2 << '\n';
	}

	//while (scanf("%d %d", &a, &b) != EOF)
	//EOF == End Of File
	//말그대로 파일의 끝에 도달하면 EOF를 리턴한다
	//윈도우 계열에서 임의로 발생시키기 위해선 Ctrl + Z를 누르면 된다고.. 
	//	printf("%d\n", a + b);

	return 0;
}