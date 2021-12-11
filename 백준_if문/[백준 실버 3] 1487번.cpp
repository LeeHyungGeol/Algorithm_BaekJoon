#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
	int pay, delivery;

	bool operator < (const Node& other) const {
		if (pay == other.pay) {
			return delivery < other.delivery;
		}
		return pay < other.pay;
	}
}Node;

int N;
vector<Node> Arr;

int main() {
	cin >> N;

	for (int i = 0, pay, delivery; i < N; ++i) {
		cin >> pay >> delivery;
		Arr.push_back({ pay, delivery });
	}

	sort(Arr.begin(), Arr.end());

	int price = 0, totalPrice = 0;

	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = i; j < N; ++j) {
			int benefit = Arr[i].pay - Arr[j].delivery;
			sum += benefit > 0 ? benefit : 0;
		}
		if (totalPrice < sum) {
			totalPrice = sum;
			price = Arr[i].pay;
		}
	}

	cout << price << '\n';

	return 0;
}