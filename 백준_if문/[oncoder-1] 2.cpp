#include <string>
using namespace std;

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
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