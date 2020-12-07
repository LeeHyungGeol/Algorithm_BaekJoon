#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
typedef long long ll;
using namespace std;
vector<ll> v; //-1,000,000,000 ≤ Ai ≤ 1,000,000,000
ll arr[1000001] = { 0 };
ll index[1000001] = { 0 };
int N; //1 ≤ N ≤ 1,000,000
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll cnt = 0;
	cin >> N;
	v.push_back(-1000000001);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			cnt++;
			index[i] = cnt;
		}
		else {
			/*vector<ll>::iterator it = lower_bound(v.begin(), v.end(), x);
			*it = x;*/

			//lower_bound(first, last, x)는 (first, last) 범위에서 x 이상인 첫 번째 원소의 위치를 반환합니다.
			//lower_bound는 찾으려 하는 key값이 "없으면" key값보다 큰 가장 작은 정수 값을 찾습니다.

			//upper_bound(first, last, x)는 (first, last) 범위에서 x를 초과하는 첫 번째 원소의 위치를 반환합니다.

			int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin(); //lower_bound()의 반환 값이 iterator형태이므로 v.begin()을 빼주어야 int 값을 가질 수 있다.
			v[pos] = arr[i];
			index[i] = pos;
		}
	}
	cout << cnt << '\n';
	stack<ll> s;
	for (int i = N; i >= 0; --i) {
		if (cnt == index[i]) {
			s.push(arr[i]);
			cnt--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	return 0;
}