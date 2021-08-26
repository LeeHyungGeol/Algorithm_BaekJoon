#include <iostream>
#include <string>
#include <vector>

#define INF 1e9

using namespace std;

int T, K, Min = INF, Max = -1;
string W;
vector<int> Alphabet;

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> W >> K;

		Min = INF;
		Max = -1;
		Alphabet.assign(26, 0);

		for (int i = 0; i < W.length(); ++i) {
			++Alphabet[W[i] - 'a'];
		}

		for (int i = 0; i < W.length(); ++i) {
			if (Alphabet[W[i] - 'a'] >= K) {
				int cnt = 0;
				
				for (int j = i; j < W.length(); ++j) {
					if (W[i] == W[j]) {
						++cnt;
					}
					if (cnt == K) {
						Min = min(Min, j - i + 1);
						Max = max(Max, j - i + 1);
						break;
					}
				}
			}
		}

		if (Min == INF || Max == -1) {
			cout << "-1" << '\n';
		}
		else {
			cout << Min << " " << Max << '\n';
		}
	}

	return 0;
}

//---------------2번째 풀이-----------------//

#include <iostream>
#include <string>
#include <vector>

#define INF 1e9

using namespace std;

int K, T, Min, Max;
string W;

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> W >> K;

		Min = INF;
		Max = -1;
		vector<int> alphabet[26];

		for (int i = 0; i < W.length(); ++i) {
			alphabet[W[i] - 'a'].push_back(i);
		}

		for (int i = 0; i < 26; ++i) {
			if (alphabet[i].size() >= K) {
				for (int j = 0; j <= alphabet[i].size() - K; ++j) {
					Min = min(Min, alphabet[i][j + K - 1] - alphabet[i][j] + 1);
					Max = max(Max, alphabet[i][j + K - 1] - alphabet[i][j] + 1);
				}
			}
		}

		if (Min == INF || Max == -1) {
			cout << "-1" << '\n';
		}
		else {
			cout << Min << " " << Max << '\n';
		}
	}
	
	return 0;
}
