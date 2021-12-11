#include <iostream>
#include <string>

using namespace std;

int Answer;
string Str;

bool isPalindrome(string s);

int main() {
    cin >> Str;

    Answer = 2 * Str.length() - 1;

    for (int i = 0; i < Str.length(); ++i) {
        string temp = Str.substr(i, Str.length() - i);
        if (isPalindrome(temp)) {
            Answer = Str.length() + i;
            break;
        }
    }

    cout << Answer << '\n';

    return 0;
}

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
       
    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    
    return true;
}
