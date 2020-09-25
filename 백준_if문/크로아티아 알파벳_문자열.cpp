#include <iostream>
#include <vector>
#include <string>
using namespace std;
//
//int main() {
//	int cnt = 0;
//	string str;
//	vector<string> v = { {"c="}, {"c-"},{"dz="},{"d-"},{"lj"},{"nj"},{"s="},{"z="} };
//	cin >> str;
//
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == 'c') {
//			if (str[i + 1] == '-' || str[i + 1] == '=') {
//				cnt++;
//				i += 1;
//			}
//			else
//				cnt++;
//		}
//		else if (str[i] == 'd') {
//			if (str[i + 1] == '-') {
//				cnt++;
//				i += 1;
//			}
//			else if (str[i + 1] == 'z' && str[i + 2] == '=') {
//				cnt++;
//				i += 2;
//			}
//			else {
//				cnt++;
//			}
//		}
//		else if (str[i] == 'l' && str[i + 1] == 'j') {
//			cnt++;
//			i += 1;
//		}
//		else if (str[i] == 'n' && str[i + 1] == 'j') {
//			cnt++;
//			i += 1;
//		}
//		else if (str[i] == 's' && str[i + 1] == '=') {
//			cnt++;
//			i += 1;
//		}
//		else if (str[i] == 'z' && str[i + 1] == '=') {
//			cnt++;
//			i += 1;
//		}
//		else {
//			cnt++;
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}

int main() {
    vector<string> v = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    int index;
    string str;
    cin >> str;

    for (int i = 0; i < v.size(); i++) {
        while (true) {
            index = str.find(v[i]);
            if (index == string::npos)
                break;
            str.replace(index, v[i].length(), "?");
        }
    }
    cout << str.length() << '\n';
    return 0;
}

// string.replace(문자열의 시작 위치, 문자열의 길이, 대체 문자)입니다.
//다른 사람의 문제 풀이 1:
//while문을 안쓰고 for문으로 무한루프를 구현
//int main() {
//    vector<string> vec = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
//    int index = 0;
//    string S;
//    cin >> S;
//    for (int i = 0; i < vec.size(); i++) {
//        index = S.find(vec[i]);
//        for (; index != string::npos; index = S.find(vec[i]))
//            S.replace(index, vec[i].length(), "@");
//    }
//    cout << S.length();
//    return 0;
//}