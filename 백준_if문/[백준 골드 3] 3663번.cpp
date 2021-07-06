// �׸��� ����

// left == i
// right == ind(i ������ �ִ� A�� �ƴ� ����)
// 1) (����)0 -> i -> 0 -> ind : 2a + b
// 2) (����)0 -> ind -> 0 -> i : a + 2b
// min(2a+b, a+2b) == a+b + min(a,b);
// a = i, b = n - ind
// -> step = min(step, i + n - ind + min(i, n - ind));

// [���α׷��ӽ� ���� 2] ���̽�ƽ ������ �Ȱ���. ���� Ǯ��� ���� ��õ

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int TC;
string name;

int main() {
	cin >> TC;

	for (int tc = 0; tc < TC; ++tc) {
		cin >> name;
		int n = name.size();
		int step = n - 1;
		int answer = 0;

		for (int i = 0; i < n; ++i) {
			answer += min(name[i] - 'A', 'Z' - name[i] + 1);

			int left = i;
			int right = i + 1;

			while (right < n && name[right] == 'A') {
				++right;
			}

			step = min(step, left + n - right + min(left, n - right));
		}

		answer += step;

		cout << answer << '\n';
	}

	return 0;
}