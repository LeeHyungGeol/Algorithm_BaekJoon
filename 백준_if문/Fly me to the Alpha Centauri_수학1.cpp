//#include <iostream>
//using namespace std;
//
//int main() {
//
//	int t, x, y, tmp, cnt, k, a, b, c;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> x >> y;
//		y -= 1;
//		tmp = y - x;
//		k = 0;
//		cnt = 1;
//		while (true) {
//			if (tmp <= 0)
//				break;
//			if (k <= 0) {
//				k++;
//				cnt++;
//				tmp -= k;
//				if (tmp <= 0)
//					break;
//				continue;
//			}
//			a = k - 1;
//			b = k;
//			c = k + 1;
//			if (tmp >= c)
//				tmp -= c;
//			else if (tmp >= b)
//				tmp -= b;
//			else if (tmp >= a)
//				tmp -= a;
//			cnt++;
//		}
//		cout << cnt << '\n';
//	}
//	return 0;
//}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int j = 0; j < T; j++) {
		long double x, y, d, i = 1;
		cin >> x >> y;
		d = y - x;
		for (;; i++)
			if (i * i > d)
				break;

		if (pow(i - 1, 2) == y - x)
			cout << 2 * i - 3 << '\n';
		else if ((pow(i, 2) + pow(i - 1, 2)) / 2 >= y - x)
			cout << 2 * (i - 1) << '\n';
		else
			cout << 2 * (i - 1) + 1 << '\n';
	}
}
