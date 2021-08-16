#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Cards;

int first(vector<int>& arr, int target, int start, int end);

int main() {
	cin >> N;

	Cards.push_back(-1);

	for (int i = 0; i < N; ++i) {
		int card;
		cin >> card;
		if (Cards.back() < card) {
			Cards.push_back(card);
		}
		else {
			// int index = lower_bound(Cards.begin(), Cards.end(), card) - Cards.begin();
			int index = first(Cards, card, 0, Cards.size() - 1);
			Cards[index] = card;
		}
	}

	cout << Cards.size() - 1 << '\n';

	return 0;
}

int first(vector<int>& arr, int target, int start, int end) {
	if (start > end) {
		return start;
	}

	int mid = (start + end) / 2;

	if (arr[mid] >= target) {
		return first(arr, target, start, mid - 1);
	}
	else {
		return first(arr, target, mid + 1, end);
	}
}