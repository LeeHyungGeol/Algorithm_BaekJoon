//�ǿܷ� �̺� Ž������ Ǯ �� �ִ� ���� ���� 2. ���� ���Ǵ� �˰����̴� �˾� �ӽô�.
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
	int start = v[0], end = v[n - 1];//���� a�� ũ�� n (1 �� n �� 1,000,000)
	int result = 0, cnt = 0, value = 0;
	
	return 0;
}
//https://kyunstudio.tistory.com/240 //�ݺ��� + �̺�Ž��
//https://regularmember.tistory.com/169 //�ݺ��� + lower_bound()
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
//	v.push_back(0);//���� A�� ũ�� N (1 �� N �� 1,000,000)
//	for (int i = 0; i < N; ++i) {
//		cin >> x;
//		if (v.back() < x) {
//			v.push_back(x);
//			cnt++;
//		}
//		else {
//			//int index = lower_bound(v.begin(), v.end(), x) - v.begin(); //lower_bound()�� ��ȯ ���� iterator�����̹Ƿ� v.begin()�� ���־�� int ���� ���� �� �ִ�.
//			//v[index] = x;
//
//			//lower_bound(first, last, x)�� (first, last) �������� x �̻��� ù ��° ������ ��ġ�� ��ȯ�մϴ�.
//			//lower_bound�� ã���� �ϴ� key���� "������" key������ ū ���� ���� ���� ���� ã���ϴ�.
//
//			//upper_bound(first, last, x)�� (first, last) �������� x�� �ʰ��ϴ� ù ��° ������ ��ġ�� ��ȯ�մϴ�.
//
//			vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
//			*it = x; //it�� �ּ� ���� ����Ű�� ���� x�� �ֱ�
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}