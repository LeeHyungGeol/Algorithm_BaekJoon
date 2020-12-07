#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
typedef long long ll;
using namespace std;
vector<ll> v; //-1,000,000,000 �� Ai �� 1,000,000,000
ll arr[1000001] = { 0 };
ll index[1000001] = { 0 };
int N; //1 �� N �� 1,000,000
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

			//lower_bound(first, last, x)�� (first, last) �������� x �̻��� ù ��° ������ ��ġ�� ��ȯ�մϴ�.
			//lower_bound�� ã���� �ϴ� key���� "������" key������ ū ���� ���� ���� ���� ã���ϴ�.

			//upper_bound(first, last, x)�� (first, last) �������� x�� �ʰ��ϴ� ù ��° ������ ��ġ�� ��ȯ�մϴ�.

			int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin(); //lower_bound()�� ��ȯ ���� iterator�����̹Ƿ� v.begin()�� ���־�� int ���� ���� �� �ִ�.
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