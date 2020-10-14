#include <iostream>
using namespace std;

int main() {

	/*
	int x, arr[10] = { 0 },cnt=0, tmp=0;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		arr[i] = x % 42;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i] == arr[j] && i != j) {
				cnt++;
				tmp--;
				arr[j] = tmp;			}
		}
	}
	cout << 10 - cnt << '\n';
	*/

	/*
	int x, cnt = 0, arr[42] = { 0 };
	for (int i = 0; i < 10; i++) {
		cin >> x;
		arr[x % 42]++;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0)
			cnt++;
	}
	cout << cnt << '\n';
	*/

	int x, cnt = 0, arr[42] = { 0 };
	for (int i = 0; i < 10; i++) {
		cin >> x;
		if (!arr[x % 42]++)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}