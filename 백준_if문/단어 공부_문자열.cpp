#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int arr[26] = { 0 }, max = 0, index = 0;
	string str, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		str[i] = toupper(str[i]); //소문자를 대문자로 교환.
	}
	for (int i = 0; i < str.size(); i++) {
			arr[alphabet.find(str[i])]++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	sort(arr, arr + 26, greater<int>()); //역순으로 정렬
	/*for (int i = 0; i < 26; ++i) {
		printf("%d ", arr[i]);
	}*/
	if (arr[0] == arr[1])
		cout << "?" << '\n';
	else
		cout << alphabet[index] << '\n';

	return 0;
}