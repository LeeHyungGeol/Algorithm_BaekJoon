//������ ���� ����: ������ �� �߱� ����(2170��)�� �޸�
//������ ��ǥ���� ���� ��ǥ�� ���� ���, ���� ��ǥ�� ������ ��ǥ�� ��ġ�� �ٲ㼭 ������������ ���� ��, �����ʿ��� �������� �̵��� ���� 2���Ͽ�, ��ü�� ���̿��� ������� �Ѵ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
vector<pll> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	arr.resize(N);

	ll L, R;
	for (int i = 0; i < N; ++i) {
		cin >> L >> R;
		//������ ���� ������ �� ū ��츸 �����ʰ� ������ ��ġ�� �ٲ㼭 push_back
		if (L > R) arr[i] = { R,L };
	}

	//�������� ����
	sort(arr.begin(), arr.end());

	ll result = 0;
	L = -1, R = -1;
	for (int i = 0; i < arr.size(); ++i) {	
		//���ο� ������ ���� ó��
		if (R < arr[i].first) {
			//�����ʿ��� �������� back�ϴ� ���, back�� ��ŭ �ٽ� ������ �����ϱ� ������ 2�踦 ���ش�.
			result +=2* (R - L);
			L = arr[i].first;
			R = arr[i].second;
		}
		//��ġ�� ������ ���� ó��
		else R = max(R, arr[i].second);
	}
	//������ ������ ���� ó��
	result += 2 * (R - L);
	cout << M+result << '\n';
	return 0;
}