#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
	int cash, stocks;
};

int Money;
vector<int> Arr;

int main() {
	cin >> Money;

	for (int i = 0; i < 14; ++i) {
		int stock;
		cin >> stock;
		Arr.push_back(stock);
	}

	Node junHyeon = { Money, 0 }, seongMin = {Money, 0};

	for (int i = 0; i < 14; ++i) {
		int nowStock = junHyeon.cash / Arr[i];
		if (nowStock) {
			junHyeon.cash -= (nowStock * Arr[i]);
			junHyeon.stocks += nowStock;
		}
	}

	int before = Arr[0], up = 0, down = 0;

	for (int i = 0; i < 14; ++i) {
		int cur = Arr[i];
		int nowStock = seongMin.cash / Arr[i];
		if (up == 3) {
			seongMin.cash += seongMin.stocks * Arr[i];
			seongMin.stocks = 0;
			up = 0;
			down = 0;
			before = cur;
			continue;
		}
		else if (down == 3) {
			seongMin.cash -= (nowStock * Arr[i]);
			seongMin.stocks += nowStock;
			down = 0;
			up = 0;
			before = cur;
			continue;
		}
		
		if (cur > before) {
			++up;
			down = 0;
		}
		else if (cur < before) {
			++down;
			up = 0;
		}
		else if (cur == before) {
			up = 0;
			down = 0;
		}
		before = cur;
	}

	if ((junHyeon.cash + junHyeon.stocks * Arr[13]) > (seongMin.cash + seongMin.stocks * Arr[13])) {
		cout << "BNP" << '\n';
	}
	else if ((junHyeon.cash + junHyeon.stocks * Arr[13]) < (seongMin.cash + seongMin.stocks * Arr[13])) {
		cout << "TIMING" << '\n';
	}
	else {
		cout << "SAMESAME" << '\n';
	}
	return 0;
}
