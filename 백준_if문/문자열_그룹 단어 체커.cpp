#include <iostream>
#include <string>
using namespace std;
 
int main() {

	int N, cnt = 0, index = 0, check = 1;
	string str, collector;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (collector.find(str[j]) == string::npos) {
				collector.push_back(str[j]);
				continue;
			}
			else {
				if (str[j] == str[j - 1]) {
					continue;
				}
				else {
					check--;
					break;
				}
			}
		}
		if (check == 1)
			cnt++;
		collector.clear();
		str.clear();
		check = 1;
	}
	cout << cnt << '\n';
	

	return 0;
}


//다른 사람의 문제 풀이 1:
//나와는 다르게 string을 사용하지 않고 bool타입의 alphabet배열[26]을 사용하였다.
//int main(void) {
//	int n;
//	cin >> n;
//
//	int count = n;
//	while (n > 0) {
//		string input;
//		cin >> input;
//
//		bool alphabet[26] = { false };
//		bool flag = true;
//		for (int i = 0; i < input.length(); i++) {
//			int idx = input[i] - 'a';
//			if (!alphabet[idx]) {
//				alphabet[idx] = true;
//			}
//
//			else if (alphabet[idx] && (input[i] != input[i - 1])) {
//				count -= 1; break;
//			}
//		}
//		n--;
//	}
//	cout << count;
//
//	return 0;
//}