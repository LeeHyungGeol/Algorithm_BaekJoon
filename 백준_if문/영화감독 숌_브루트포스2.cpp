#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 666; i < 1000000000; ++i) {
		string str = to_string(i);
		if (str.find("666") != string::npos) {
			cnt++;
			if (cnt == n) {
				cout << str << '\n';
				return 0;
			}
		}
	}
	return 0;
}
//
//int main() {
//	
//	int N, cnt = 0, n = 666;
//	cin >> N;
//
//	while (true) {
//		string str = to_string(n);
//		for (int i = 0; i < str.length() - 2; ++i) {
//			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') {
//				cnt++;
//				break;
//			}
//		}
//		if (cnt == N) {
//			cout << n << '\n';
//			break;
//		}
//		n++;
//	}
//
//	return 0;
//}