//������ �˰���(Sweeping Algorithm): ������ ���� ���������� �ȴٰ� ����ġ�� ������ ������ ���� ó���� ���ִ� ���

//-> ������ ���� �� ��ǥ ������ �����Ͽ� ��ȸ�ϸ� �ȴ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000001
typedef long long ll;
typedef pair<ll, ll> pll;

int N; //���� ���� Ƚ�� N(1 �� N �� 1,000,000)
vector<pll> arr;

int main() {
	ios_base::sync_with_stdio(false);//�ð� �ʰ�->387ms
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);

	//���� ���� �� ������ �� ���� ��ġ x, y(-1,000,000,000 �� x < y �� 1,000,000,000)
	ll L, R, result = 0;
	for (int i = 0; i < N; ++i) {
		cin >> L >> R;
		arr[i] = { L,R };
	}

	//���е��� ���� �� ��ǥ ������ ����
	sort(arr.begin(), arr.end());

	//���� ���� ������ ���� ���� �ʱⰪ�� �ּҰ��� -1e9���� �ϳ� �� ���� ������ �ʱ�ȭ
	L = -MAX, R = -MAX;
	for (int i = 0; i < N; ++i) {
		//���ο� ������ ���� ó��
		if (R < arr[i].first) {
			//���� ������ ���� ���� ������� �����ش�.
			result += R - L;
			//���ο� �������� ����
			L = arr[i].first;
			R = arr[i].second;
		}
		//��ġ�� ������ ���� ó��
		else R = max(R, arr[i].second);
	}
	//������ ������ ���� ���� ������� �����ش�.
	result += R - L;
	cout << result << '\n';

	return 0;
}