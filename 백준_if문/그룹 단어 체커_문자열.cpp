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