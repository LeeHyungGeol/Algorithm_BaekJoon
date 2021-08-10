// 그리디(탐욕법), 수학 문제

// 그리디라고 생각하는 것이 어려웠다. 

// 한번에 총 나무의 길이를 3만큼 성장시킬 수 있다고 했으므로,
// 총 나무의 길이는 3의 배수이어야만 한다.(if(sum3 % 3 == 0))

// 그리고, 총 n번 물을 뿌렸다면, 2만큼 n번, 1만큼 n번 뿌렸다는 의미이고,
// 각 나무의 길이에서 2로 나눈 것들의 합(sum2 += x / 2)이 총 n번(sum3 / 3) 보다 크거나 같으면 된다.

// 참고 : https://velog.io/@axiom0510/b19539

#include <iostream>

using namespace std;

int N, sum2, sum3;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		sum3 += x;
		sum2 += x / 2;
	}

	if (sum3 % 3 == 0) {
		if (sum2 >= (sum3 / 3)) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}