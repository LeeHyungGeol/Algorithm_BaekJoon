// ���� ����, �׸��� ����
// �� å���� ��ġ�� ���, ������ ������ �迭�� �Է� ���� ��, 
// ���� �� å��(M��)�� �����ϰ�, ���ʷ� å�� ������ ���´�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Plus, Minus;

int main() {
	cin >> N >> M;

	int Max = 10001;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		if (temp > 0) {
			Plus.push_back(temp);
		}
		else {
			Minus.push_back(temp);
		}
		
	}

	sort(Plus.begin(), Plus.end());
	sort(Minus.begin(), Minus.end());

	for (int i = 0; i < N; ++i) {
		
	}

	return 0;
}