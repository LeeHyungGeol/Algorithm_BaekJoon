// 문자열 알고리즘(KMP) 문제

// 커누스-모리스-프랫(KMP)문자열 검색 알고리즘 구현
// '짚더미' H의 부분 문자열로 '바늘' N이 출현하는 시작위치들을 모두 반환
// 시간복잡도: O(H) + O(N)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S, P;

vector<int> getPartialMatch(const string& N);
vector<int> kmpSearch(const string& H, const string& N);

int main() {
	cin >> S >> P;

	vector<int> answer = kmpSearch(S, P);

	if (answer.size() > 0) {
		cout << "1" << '\n';
	}
	else {
		cout << "0" << '\n';
	}

	return 0;
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