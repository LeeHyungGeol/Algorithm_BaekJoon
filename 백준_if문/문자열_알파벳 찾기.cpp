#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    string abc = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    for (int i = 0; i < abc.length(); i++) {
        if (s.find(abc[i]) == string::npos)//찾는 문자가 없으면 string::npos를 반환한다.
            cout << -1 << " ";
        else {
            cout << s.find(abc[i]) << " ";
            continue;
        }
    }
	return 0;//26
}