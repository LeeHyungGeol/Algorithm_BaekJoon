//https://jhnyang.tistory.com/107 - getline() 함수 설명 사이트
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string H; //'짚더미' H(Haystack)
string N; //'바늘' N(Needle)

//단순한 문자열 알고리즘을 이용해 부분 일치 테이블(pi) 계산
//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다.
//pi[i]는 N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이이다. 
//시간 복잡도: O(N^2)
vector<int> getPartialMatchNative(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	for (int begin = 1; begin < m; ++begin) {
		for (int i = 0; begin + i < m; ++i) {
			if (N[begin + i] != N[i]) break;
			//i+1 글자가 서로 대응되었다.
			//현재보다 왼쪽에 있는 시작 위치에서 값을 이미 갱신 했을지도 모르기 때문에 max함수를 이용
			pi[begin + i] = max(pi[begin + i], i + 1);
		}
	}
	return pi;
}
//'짚더미' H(Haystack)의 부분 문자열로 '바늘' N(Needle)이 출현하는 시작위치들을 모두 반환
//가장 간단한 방법으로 N의 가능한 모든 문자열 시작 위치를 시도해 보는 것이다.
//시간 복잡도: O(N*H)
vector<int> nativeSearch(const string& H, const string& N) {
	vector<int> ret;
	//모든 시작 위치를 전부 시도해보기
	for (int begin = 0; begin + N.size() <= H.size(); ++begin) {
		bool matched = true;
		for (int i = 0; i < N.size(); ++i) {
			if (H[begin + i] != N[i]) {
				matched = false;
				break;
			}
		}
		if (matched)
			ret.push_back(begin);
	}
	return ret;
}
//N에서 자기 자신을 찾으면서 나타나는 부분일치를 이용해 pi[]를 계산한다.
//pi[i]는 N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이이다.
//시간복잡도: O(N)
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP로 자기 자신을 찾는다.
	//N을 N에서 찾는다. begin=0 부터 시작하면, 자기 자신을 찾아버리니까 안된다.
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
//커누스-모리스-프랫(KMP)문자열 검색 알고리즘 구현
//'짚더미' H의 부분 문자열로 '바늘' N이 출현하는 시작위치들을 모두 반환
//시간복잡도: O(H) + O(N)
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size();
	int m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N); //시간복잡도: O(N)

	//begin = matched = 0 에서부터 시작 
	int begin = 0, matched = 0;
	while (begin <= n - m) {//begin + N.size() <= H.size()
		//만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		//while문 내에서 begin + matched는 절대 감소하지 않는다.
		//matched가 감소할 때도 begin은 항상 그 감소분만큼 증가하기 때문에 둘의 합은 변하지 않는다.
		//따라서, 한번 matched가 증가하고 나면, H[begin + matched]를 다시 참조할 일이 없다.
		//이 분기는 최대 O(H)번 수행
		if (matched < m && H[begin + matched] == N[matched]) {//matched<m이 없어도 통과가 가능
			++matched;
			//결과적으로 m글자가 모두 일치했다면 답에 추가
			if (matched == m)
				ret.push_back(begin);
		}

		else {//begin이 H.size()-N.size()를 초과하면 곧장 종료하기 때문에, 이 분기도 최대 O(H)번 수행한다.

			//예외: 한 글자도 일치하지 않는 경우에는 다음 칸에서부터 찾는 것을 계속한다.
			if (matched == 0) 
				++begin;
			else {
				begin += matched - pi[matched - 1];
				//begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
				//옮긴 후에도 pi[matched - 1]만큼은 항상 일치하기 때문이다.
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
vector<int> getPartialMatchTable(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int matched = 0;
	for (int begin = 1; begin < m; ++begin) {
		while (matched > 0 && N[begin] != N[matched]) {
			matched = pi[matched - 1];
		}
		if (N[begin] == N[matched]) {
			pi[begin] = ++matched;
		}
	}
	return pi;
}
vector<int> kmpSearch2(const string& H, const string& N) {
	vector<int> ret;
	vector<int> pi = getPartialMatchTable(N);
	int n = H.size(), m = N.size();
	//현재 대응된 글자 수
	int matched = 0;
	//H의 각 글자를 순회한다. 
	for (int begin = 0; begin < n; ++begin) {
		//matched번 글자와 H의 해당 글자가 불일치 할 경우
		//현재 대응된 글자의 수 pi[matched - 1]로 줄인다.
		while (matched > 0 && H[begin] != N[matched]) {
			matched = pi[matched - 1];
		}
		//글자가 대응될 경우
		if (H[begin] == N[matched]) {
			++matched;
			if (matched == m) {
				ret.push_back(begin - m + 1);
				//글자가 모두 일치한 경우에도 다음 위치로 점프해야하기 때문에 N의 접미사 길이 만큼 matched이동
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
int main() {
	getline(cin, H);
	getline(cin, N);
	//cout << H << '\n';
	//cout << N << '\n';
	vector<int> answer = kmpSearch2(H, N);
	cout << answer.size() << '\n';
	for (auto it : answer) {
		cout << it + 1 << '\n';
	}
	/*for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] + 1 << '\n';
	}*/
	return 0;
}