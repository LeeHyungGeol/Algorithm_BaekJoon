// 우선순위 POINT queue는 시작지점에 따라 우선순위를 결정, 시작점이 같다면 끝나는점이 빠른 노드가 우선순위가 높다

#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>

using namespace std;
class POINT {
public:
	int start;
	int end;
	int num;
	POINT() {
	}
	POINT(int s, int e) {
		this->start = s;
		this->end = e;
	}
	const bool operator<(POINT const& other) const {
		if (start == other.start) {
			return end < other.end;
		}
		return start < other.start;
	}
}point[300001];


struct comp {
	bool operator()(POINT& a, POINT& b) {
		return a.end > b.end;
	}
};

priority_queue<POINT, vector<POINT>, comp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> point[i].start >> point[i].end;
		point[i].num = i + 1;
	}
	if (n == 1) {
		cout << 1;
		cout << "\n" << 1;
		return 0;
	}
	sort(point, point + n);

	int maxv = 1;
	pq.push(point[0]);
	int minend = point[0].end;

	for (int i = 1; i < n; i++) {
		if (point[i].start <= minend) {
			pq.push(point[i]);
			if (point[i].end < minend) {
				minend = point[i].end;
			}
		}
		else {
			while (pq.size() != 0 && pq.top().end < point[i].start) {
				pq.pop();
			}
			pq.push(point[i]);
		}
		maxv = max(maxv, (int)pq.size());
	}

	cout << maxv << "\n";
	while (pq.size() != 0) {
		pq.pop();
	}

	pq.push(point[0]);
	for (int i = 1; i < n; i++) {

		if (point[i].start <= minend) {
			pq.push(point[i]);
			if (point[i].end < minend) {
				minend = point[i].end;
			}
		}
		else {
			while (pq.size() != 0 && pq.top().end < point[i].start) {
				pq.pop();
			}
			pq.push(point[i]);
		}
		if (maxv == (int)pq.size()) {
			while (pq.size() != 1) {
				cout << pq.top().num << " ";
				pq.pop();
			}
			cout << pq.top().num;
			return 0;
		}
	}
}