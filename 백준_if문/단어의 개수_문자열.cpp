#include <iostream>
#include <string>
using namespace std;

int main() {
	int j = 0, countBlank = 1;
	string str;
	getline(cin, str);
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') { // 왜 여기에 조건을 더 추가하면 안될까????
			countBlank++;
		}
	}

	if (str[0] == ' ')
		countBlank--;
	
	if (str[str.length() - 1] == ' ')
		countBlank--;
	cout << countBlank;

	return 0;
}