// dp(���̳��� ���α׷���) ����

// Dp�迭�� �׻� �� �ε����� �ش��ϴ� Snacks[i] ���� �⺻ ������ ���� �־�� �ϹǷ�, �ʱ�ȭ�����ش�.
// �ڿ� ������ ������ �������� �տ� ������ ������ ������ ���� Ŀ�� �ϹǷ�
// j < i �϶�, Snacks[j] < Snacks[i] �̶��, ���ݱ����� ���� �� �ִ�(Dp[j])���ٰ� Snacks[i]�� �����ش�.

// ���̺귯�� algorithm�� max_element(vector.begin(), vector.end())
// -> vector�� �ִ� ��ȯ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Answer;
vector<int> Snacks;
vector<int> Dp;

int main() {
	cin >> N;

	Snacks.resize(N, 0);
	Dp.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> Snacks[i];
	}

	Answer = Dp[0] = Snacks[0];

	for (int i = 1; i < N; ++i) {
		Dp[i] = Snacks[i];

		for (int j = 0; j < i; ++j) {
			if (Snacks[j] < Snacks[i]) {
				Dp[i] = max(Dp[i], Dp[j] + Snacks[i]);
			}
		}
	}
	

	/*for (int i = 0; i < Dp.size(); ++i) {
		Answer = max(Answer, Dp[i]);
	}
	
	cout << Answer << '\n';*/

	cout << *max_element(Dp.begin(), Dp.end()) << '\n';

	return 0;
}