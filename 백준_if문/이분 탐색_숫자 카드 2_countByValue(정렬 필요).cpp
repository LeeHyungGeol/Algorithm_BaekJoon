#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countByValue(vector<int>& v, int target);
int first(vector<int>& v, int target, int start, int end);
int last(vector<int>& v, int target, int start, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	cin >> M;

	sort(v.begin(), v.end());
	for (int i = 0; i < M; ++i) {
		cin >> x;
		cout << countByValue(v, x) << ' ';
	}
	cout << '\n';
	return 0;
}
int countByValue(vector<int>& v, int target) {
	int n = v.size();
	//target이 처음 등장한 인덱스 값 리턴
	int firstIndex = first(v, target, 0, n - 1);
	if (firstIndex == -1) //배열에 원소가 존재하지 않는 경우 0을 리턴
		return 0;
	//target이 마지막으로 등장한 인덱스 값 리턴
	int lastIndex = last(v, target, 0, n - 1);

	return lastIndex - firstIndex + 1;
}
int first(vector<int>& v, int target, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if ((mid == 0 || target > v[mid - 1]) && v[mid] == target)//target값을 가지는 원소 중에서 가장 왼쪽에 있는 경우에만 인덱스 값을 리턴
		return mid;
	else if (v[mid] >= target) // >= // 중간 점의 값보다 target값이 작거나 같은 경우에 왼쪽을 확인 
		return first(v, target, start, mid - 1);
	else
		return first(v, target, mid + 1, end); //중간 점의 값보다 target값이 큰 경우에 오른쪽을 확인 
}
int last(vector<int>& v, int target, int start, int end) {
	if (start > end)
		return -1;
	int n = v.size();
	int mid = (start + end) / 2;
	if ((mid == n - 1 || target < v[mid + 1]) && v[mid] == target) //target값을 가지는 원소 중에서 가장 오른 쪽에 있는 경우에만 인덱스 값을 리턴
		return mid;
	else if (v[mid] > target) // 중간 점의 값보다 target값이 작거나 같은 경우에 왼쪽을 확인
		return last(v, target, start, mid - 1); 
	else
		return last(v, target, mid + 1, end); //중간 점의 값보다 target값이 큰 경우에 오른쪽을 확인
}