#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct coordinate {
	int x;
	int y;
}coordinate;
int main() {
		
	coordinate c[100000], temp;
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> c[i].x >> c[i].y;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - (i + 1); ++j) {
			if (c[i].x > c[i + 1].x) {
				temp = c[i];
				c[i] = c[i + 1];
				c[i + 1] = temp;				
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - (i + 1); ++j) {
			if (c[i].x == c[i + 1].x) {
				if (c[i].y > c[i + 1].y) {
					temp = c[i];
					c[i] = c[i + 1];
					c[i + 1] = temp;
				}
			}
		}
	}
	
	for (int i = 0; i < N; ++i) {
		cout << c[i].x << " " << c[i].y << '\n';
	}
	return 0;
}