// 문자열(부분 문자열, 단조증가), stringstream.clear()

#include <iostream> 
#include <string>
#include <sstream>

using namespace std;

string Str;
stringstream SS;

int main() {
	while (getline(cin, Str)) { 
		SS.str(Str);
		
		string s, t;
		bool flag = false;

		SS >> s >> t;

		int j = 0;

		for (int i = 0; i < t.length(); ++i) {
			if (t[i] == s[j]) {
				++j;

				if (j == s.length()) {
					flag = true;
				}
			}
		}

		if (flag) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}

		SS.clear();
	}

	return 0;
}