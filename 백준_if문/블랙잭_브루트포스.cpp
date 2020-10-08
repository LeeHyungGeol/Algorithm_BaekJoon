#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;
int main() {
	int N, M, max = 0, x;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x;
		card.push_back(x);
	}
	sort(card.begin(), card.end());
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j)
				continue;
			for (int k = 0; k < N; ++k) {
				if (j == k || i == k)
					continue;
				else {
					if (card[i] + card[j] + card[k] > M)
						break;
					else if (card[i] + card[j] + card[k] > max)
						max = card[i] + card[j] + card[k];
				}
			}
		}
	}
	
	cout << max << '\n';
	return 0;
}
