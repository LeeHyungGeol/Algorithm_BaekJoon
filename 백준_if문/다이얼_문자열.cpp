#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main() {
//	int index = 0, sum = 0;
//	string str;
//	string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	cin >> str;
//
//	for (int i = 0; i < str.length(); i++) {
//		index = alphabet.find(str[i]);
//		if (index <= 3) {
//			sum += 3;
//		}
//		else if (3 < index && index <= 6) {
//			sum += 4;
//		}
//		else if (6 < index && index <= 9) {
//			sum += 5;
//		}
//		else if (9 < index && index <= 12) {
//			sum += 6;
//		}
//		else if (12 < index && index <= 15) {
//			sum += 7;
//		}
//		else if (15 < index && index <= 19) {
//			sum += 8;
//		}
//		else if (19 < index && index <= 22) {
//			sum += 9;
//		}
//		else if (22 < index && index <= 26) {
//			sum += 10;
//		}
//	}
//	cout << sum << '\n';
//
//	return 0;
//}

//다른 사람의 풀이 1:
//배열을 만들어 각 알파벳에 대한 시간을 미리 설정해주었습니다.
//int arr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
//입력 받은 영어를 한 글자씩 잘라서 - 65 해주어서 index에 접근했습니다.
//
//int arr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
//int sum = 0;
//string s;
//
//cin >> s;
//
//for (int i = 0; i < s.length(); ++i) {
//	int index = s[i] - 65; //'A'
//	sum += arr[index];
//}
//
//cout << sum << endl;


//다른 사람의 풀이 2:
//벡터 vec은 계산하기 쉽도록 각 벡터의 인덱스가 다이얼을 입력하는 시간이 되도록 만들었습니다.
//
//string.find() 함수는 vec[j]에서 S[i]가 몇 번째 있는지를 리턴하는 함수입니다.
//문자를 찾지 못하면 string::npos가 리턴됩니다.
//그러므로 string::npos가 아니면 문자열을 찾았다는 뜻이니 
//해당 인덱스인 j를 값에 더해주면 몇 초 걸렸는지 구할 수 있습니다.

int main() {
	int sum = 0;
	string s;
	vector<string> vec = { {"-1"},{"-1"},{"-1"},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"} };
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		for (int j = 0; j < vec.size(); j++)
			if (vec[j].find(s[i]) != string::npos)
				sum += j;
	cout << sum;
	return 0;
}


//다른 사람의 문제풀이 3:
//각 다이얼마다 알파벳이 보통 3개씩 들어있으며 마지막 다이얼과 마지막에서 3번째에 위치한 다이얼 2개만 알파벳을 4개 가지고 있는 것을 활용한 코드이다.
//
//A, B, C를 각각 0, 1, 2로 보고 3을 나누어주면 0이라는 결과가 나오고 여기서 3을 더하면 A, B, C를 걸기 위해 걸리는 시간인 3초가 딱 나온다.
//M, N, O까지만 해도 이 규칙이 잘 맞아떨어지다가 그 다음 다이얼에서 알파벳이 4개가 들어가면서 예외 사항이 생긴다.
//S는 본래 같은 다이얼에 있는 알파벳들보다 1초 더 걸린다.
//다음 알파벳에 있는 V 또한 같은 다이얼에 있는 알파벳들보다 1초 더 걸린다.
//이걸 이용해서 S와 V만 따로 예외처리해서 다른 알파벳들은 3을 더해주는걸 이 알파벳들만 2를 더해준다.
//
//그럼 마지막 알파벳 4개는 어떡해할까? 
//앞에 A, B, C를 0, 1, 2로 본 것처럼 V, W, X를 각각 21, 22, 23으로 볼 수 있으며 여기서 3을 나누고 이 몫에 3을 더하면 10이라는 숫자가 나온다.
//원래는 V, W, X가 모두 10초가 걸려야하나, V가 예외처리 되었으므로 얘만 앞서 2를 더해서 9초가 걸리게끔 처리한다.
//그리고 W부터는 모두 10초가 걸리게끔 if문을 사용해 3을 나누고 몫에 3을 더한 값이 9가 넘으면 무조건 10초가 걸린다고 분류해버리는 것이다.
//그래서 Y, Z도 다이얼 거는데 10초가 걸린다고 분류된다.
//
//알파벳을 다이얼 거는데 몇 초가 걸릴 지 분류하는 코드 앞에 알파벳이 각각 몇 개 있는지 분류해서 카운트하는 코드를 집어넣는다.
//그리고 이 알파벳의 개수와 알파벳을 다이얼 거는데 걸리는 시간을 곱해서 result 결과 값에 차곡차곡 더해주고 
//마지막에 result를 출력하면 전체 다이얼을 거는데 걸리는 시간이 출력된다.
//
//int main(void)
//{
//	char alpha[26] = { 0, };
//	string ch;
//	int result = 0, dial;
//	cin >> ch;
//	for (char e : ch)
//	{
//		alpha[e - 'A']++;
//	}
//	for (int i = 0; i <= 'Z' - 'A'; i++)
//	{
//		if (i == 'S' - 'A' || i == 'V' - 'A')
//		{
//			result += (i / 3 + 2) * alpha[i];
//			continue;
//		}
//
//		if (alpha[i])
//		{
//			dial = i / 3 + 3;
//			if (dial > 9)
//			{
//				result += 10 * alpha[i];
//			}
//			else
//			{
//				result += dial * alpha[i];
//			}
//		}
//	}
//	cout << result << endl;
//	return 0;
//}


