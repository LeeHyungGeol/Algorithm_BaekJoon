#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int countByValue(vector<int>& v, int target);
int first(vector<int>& v, int target, int start, int end);
//int last(vector<int>& v, int target, int start, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x;
	vector<int> v1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v1.push_back(x);
	}
	cin >> M;
	
	sort(v1.begin(), v1.end());
	int n = v1.size();
	for (int i = 0; i < M; ++i) {
		cin >> x;
		if (first(v1, x, 0, n - 1) == -1)
			cout << "0" << '\n';
		else
			cout << "1" << '\n';
	}

	return 0;
}
//int countByValue(vector<int>& v, int target) {
//	int n = v.size();
//	int firstIndex = first(v, target, 0, n - 1);
//	if (firstIndex == -1) //배열에 원소가 존재하지 않는 경우 0을 리턴
//		return 0;
//	//int lastIndex = last(v, target, 0, n - 1);
//	else
//		return 1;
//	//return lastIndex - firstIndex + 1;
//}
int first(vector<int>& v, int target, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	//if ((mid == 0 || target > v[mid - 1]) && v[mid] == target)
	if ( v[mid] == target)
		return mid;
	else if (v[mid] > target)
		return first(v, target, start, mid - 1);
	else
		return first(v, target, mid + 1, end);
}
//int last(vector<int>& v, int target, int start, int end) {
//	if (start > end)
//		return -1;
//	int n = v.size();
//	int mid = (start + end) / 2;
//	if ((mid == n - 1 || target < v[mid + 1]) && v[mid] == target)
//		return mid;
//	else if (v[mid] > target)
//		return last(v, target, start, mid - 1);
//	else
//		return last(v, target, mid + 1, end);
//}