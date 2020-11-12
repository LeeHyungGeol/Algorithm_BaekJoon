//의외로 이분 탐색으로 풀 수 있는 놀라운 문제 2. 자주 사용되는 알고리즘이니 알아 둡시다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		v.push_back(x);
	}
	int start = v[0], end = v[n - 1];//수열 a의 크기 n (1 ≤ n ≤ 1,000,000)
	int result = 0, cnt = 0, value = 0;
	
	return 0;
}
//https://kyunstudio.tistory.com/240 //반복문 + 이분탐색
//https://regularmember.tistory.com/169 //반복문 + lower_bound()
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//
//	vector<int> v;
//	int N, x, cnt = 0;
//	cin >> N;
//	v.push_back(0);//수열 A의 크기 N (1 ≤ N ≤ 1,000,000)
//	for (int i = 0; i < N; ++i) {
//		cin >> x;
//		if (v.back() < x) {
//			v.push_back(x);
//			cnt++;
//		}
//		else {
//			//int index = lower_bound(v.begin(), v.end(), x) - v.begin(); //lower_bound()의 반환 값이 iterator형태이므로 v.begin()을 빼주어야 int 값을 가질 수 있다.
//			//v[index] = x;
//
//			//lower_bound(first, last, x)는 (first, last) 범위에서 x 이상인 첫 번째 원소의 위치를 반환합니다.
//			//lower_bound는 찾으려 하는 key값이 "없으면" key값보다 큰 가장 작은 정수 값을 찾습니다.
//
//			//upper_bound(first, last, x)는 (first, last) 범위에서 x를 초과하는 첫 번째 원소의 위치를 반환합니다.
//
//			vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
//			*it = x; //it의 주소 값이 가리키는 곳에 x값 넣기
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}