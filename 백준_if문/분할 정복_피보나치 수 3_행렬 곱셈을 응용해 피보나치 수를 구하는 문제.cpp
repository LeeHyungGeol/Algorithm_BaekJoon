// ��� ������ ������ �Ǻ���ġ ���� ���ϴ� ����
// ���� ������ �� �޸𸮸� ����ϰ� ���� ������ ���� �޸𸮸� ����Ѵ�.
// "�ǻ�� �ֱ⸦ �̿��Ѵ�" -> �𸣸� �� Ǫ�� ����..
// �Ǻ���ġ ������ m���� ���� �������� �ֱ⸦ �̷��.
// �������� �̿��ؼ� ���� ������ �ֱⰡ ��Ÿ�� �� �ִ�. 
// k(m)�� �ݺ��ϴ� �κ� ������ ���̶�� ���� ��, k(11) = 10���� �� �� �ִ�.
// n > 2���, k(10^n) = 15��10^(n-1)
#include <iostream>
using namespace std;
#define mod 1000000 
#define period 1500000
int dp[15000001] = { 0,1, };
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;
	for (int i = 2; i <= period; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n % period] << '\n';

	return 0;
}