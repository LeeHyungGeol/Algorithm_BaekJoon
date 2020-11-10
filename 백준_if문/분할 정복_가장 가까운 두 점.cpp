//https://casterian.net/archives/92
//http://chanhaeng.blogspot.com/2018/07/divide-and-conquer-closest-pair-of.html
//https://letsgoturing.tistory.com/69
//---가장 가까운 점들의 쌍 찾기 (Divide and Conquer, Closest Pair of Points)---
//우선 x에 대해 오름차순으로 정렬을 합니다.
//그 다음 가운데 점을 기준으로 오른쪽과 왼쪽을 분할하고,
//오른쪽과 왼쪽에 대해서 가장 가까운 두 점 상의 거리를 찾습니다.
//그리고 가운데 중심점을 기준으로 오른쪽과 왼쪽에 대해서 각각 찾은 가장 가까운 두 점 사이 거리 중 작은 것에 대해 
//그 거리 만큼 x, y축안에 존재하는 점들에 대해 이보다 더 가까운 점들이 존재하는지 검사합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second
vector<pii> varr;
int n;
int divideAndConquer(int first, int last);
int dist(const pii& a, const pii& b);
bool compare(const pii& a, const pii& b);

int main() {

	int x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		varr.push_back(make_pair(x, y));
	}
	sort(varr.begin(), varr.end()); //x좌표를 기준으로 오름차순 정렬
	int answer = divideAndConquer(0, n - 1);
	cout << answer << '\n';

	return 0;
}
int divideAndConquer(int first, int last) {
	if ((last - first) == 1)//점이 2개일 때
		return dist(varr[first], varr[last]);
	if ((last - first) == 2)//점이 3개일 때
		return min(
				dist(varr[first], varr[first + 1]),

			min(dist(varr[first + 1], varr[first + 2]), 

				dist(varr[first], varr[first + 2])));

	int mid = (int)(last + first) / 2; //중간 점(기준선) 잡기
	int dl = divideAndConquer(first, mid); //중간 점 기준 왼쪽의 최소거리
	int dr = divideAndConquer(mid + 1, last); //중간 점 기준 오른쪽의 최소거리
	int distanceMin = min(dl, dr);  //왼쪽 값과 오른쪽 값 중 더 작은 값

	//중간 점(기준선) 기준으로 좌, 우에 하나씩 점이 있는 경우 처리
	vector<pii> tmp;
	int d = 0;
	for (int i = first; i < mid; ++i) { // 기준선을 중심으로 좌우 거리 distanceMin 이내에 들어오는 점끼리만 비교하기 위해 
		d = varr[i].X - varr[mid].X; //x좌표를 기준으로 distanceMin 내에 있는지 확인
		if (d * d < distanceMin)
			tmp.push_back(varr[i]);
		
	}
	for (int i = mid + 1; i <= last; ++i) { // 기준선을 중심으로 좌우 거리 distanceMin 이내에 들어오는 점끼리만 비교하기 위해 
		d = varr[i].X - varr[mid].X; //x좌표를 기준으로 distanceMin 내에 있는지 확인
		if (d * d < distanceMin)
			tmp.push_back(varr[i]);

	}

	int length = tmp.size();
	sort(tmp.begin(), tmp.end(), compare); //y좌표를 기준으로 오름차순 정렬
	//for (int i = 0; i < length - 1; ++i) {
	//	for (int j = i + 1; j < length; ++j) {
	//		d = tmp[j].Y - tmp[i].Y;
	//	
	//		/*cout << "(" << tmp[i].X << " ," << tmp[i].Y << ") vs"
	//			<< "(" << tmp[j].X << " ," << tmp[j].Y << ")" << endl;
	//		
	//		cout << d << " Vs " << distanceMin << endl;*/
	//		
	//		if (d * d < distanceMin)
	//			distanceMin = min(distanceMin, dist(tmp[i], tmp[j]));
	//		else
	//			break;
	//	}
	//}
	for (int i = 0; i < length - 1; ++i) {
		for (int j = i + 1; j < length && (tmp[j].Y - tmp[i].Y) * (tmp[j].Y - tmp[i].Y) < distanceMin; ++j) {
				distanceMin = min(distanceMin, dist(tmp[i], tmp[j]));
		}
	}
	return distanceMin;
}
int dist(const pii& a, const pii& b) { // 두 점 사이의 거리 구하는 함수
	int x = a.X - b.X;
	int y = a.Y - b.Y;
	return x * x + y * y;
}
bool compare(const pii& a, const pii& b) { //y좌표를 기준으로 오름차순 정렬
	if (a.second == b.second) 
		return a.first < b.first;
	return a.second < b.second;
}