#include <string>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
    int solution(string s) {
        int answer = 2 * s.length() - 1;

        for (int i = 0; i < s.length(); ++i) {
            string temp = s.substr(i, s.length() - i);
            if (isPalindrome(temp)) {
                answer = s.length() + i;
                break;
            }
        }

        return answer;
    }
    bool isPalindrom(string str)
    {
        int cnt = str.size() / 2;
        for (int i = 0; i < cnt; i++) {
            if (str[i] != str[str.size() - 1 - i]) {
                return false;
            }
        }

        return true;
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
};