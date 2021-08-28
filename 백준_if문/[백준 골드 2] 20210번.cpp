// 문자열, 구현, 정렬

// isalpha() : 
// 알파벳 대문자 : 1
// 알파벳 소문자 : 2
// 알파벳이 아닌것 : 0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> Files[10000];

bool compare(vector<string>& a, vector<string>& b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		string number = "", alphabets = "";

		for (int j = 0; j < str.length(); ++j) {
			if (isalpha(str[j])) {
				if (!number.empty()) {
					Files[i].push_back(number);
					number = "";

					alphabets += str[j];
				}
				else {
					alphabets += str[j];
				}
			}
			else if (isdigit(str[j])) {
				if (!alphabets.empty()) {
					Files[i].push_back(alphabets);
					alphabets = "";

					number += str[j];
				}
				else {
					number += str[j];
				}
			}

			if (j == str.length() - 1 && !number.empty()) {
				Files[i].push_back(number);
			}
			if (j == str.length() - 1 && !alphabets.empty()) {
				Files[i].push_back(alphabets);
			}
		}
	}

	sort(Files, Files + N, compare);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < Files[i].size(); ++j) {
			cout << Files[i][j];
		}
		cout << '\n';
	}

	return 0;
}

bool compare(vector<string>& a, vector<string>& b) {
	int size = min(a.size(), b.size());

	for (int i = 0; i < size; ++i) {
		if (isdigit(a[i][0]) && isalpha(b[i][0])) {
			return true;
		}
		else if (isalpha(a[i][0]) && isdigit(b[i][0])) {
			return false;
		}
		else if (isdigit(a[i][0]) && isdigit(b[i][0])) {
			int countZeroA = 0;
			int countZeroB = 0;
			string numberA = "";
			string numberB = "";

			for (int j = 0; j < a[i].size(); ++j) {
				if (a[i][j] == '0') {
					++countZeroA;
				}
				else {
					numberA = a[i].substr(countZeroA, a[i].size() - countZeroA);
					break;
				}
			}
			for (int j = 0; j < b[i].size(); ++j) {
				if (b[i][j] == '0') {
					++countZeroB;
				}
				else {
					numberB = b[i].substr(countZeroB, b[i].size() - countZeroB);
					break;
				}
			}

			if (numberA == numberB) {
				if (countZeroA < countZeroB) {
					return true;
				}
				else if (countZeroA > countZeroB) {
					return false;
				}
			}
			else {
				if (numberA.size() < numberB.size()) {
					return true;
				}
				else if (numberA.size() > numberB.size()) {
					return false;
				}
				else {
					for (int j = 0; j < numberA.size(); ++j) {
						if (numberA[j] < numberB[j]) {
							return true;
						}
						else if (numberA[j] > numberB[j]) {
							return false;
						}
					}
				}
			}
		}
		else if (isalpha(a[i][0]) && isalpha(b[i][0])) {
			int alphabetLength = min(a[i].size(), b[i].size());

			for (int j = 0; j < alphabetLength; ++j) {
				if (tolower(a[i][j]) < tolower(b[i][j])) {
					return true;
				}
				else if (tolower(a[i][j]) > tolower(b[i][j])) {
					return false;
				}
				else {
					if (('A' <= a[i][j] && a[i][j] <= 'Z') && ('a' <= b[i][j] && b[i][j] <= 'z')) {
						return true;
					}
					else if (('a' <= a[i][j] && a[i][j] <= 'z') && ('A' <= b[i][j] && b[i][j] <= 'Z')) {
						return false;
					}
				}
			}
		
			if (a[i].size() < b[i].size()) {
				return true;
			}
			else if (a[i].size() > b[i].size()) {
				return false;
			}
		}
	}

	if (a.size() < b.size()) {
		return true;
	}
	else {
		return false;
	}

	return true;
}