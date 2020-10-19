#include <iostream>
#include <list>
#include <map>
using namespace std;

map<int, int> m;

int main() {

	
	map<int, int>::iterator iter;
	list<int> list;
	int N, i = 1, x = 1, n;
	cin >> N;
	m.insert(make_pair(i, 666));
	while (i <= 10000) {
		++i;
		if ((x % 10) != 6) {
			n = (x * 1000) + 666;
			m.insert(make_pair(i, n));
			++x;
		}
		else {
			for (int j = 0; j <= 9; ++j) {
				n = (x * 1000) + (66 * 10) + j;
				m.insert(make_pair(i, n));
				++i;
			}
			++x;
		}
	}

	cout << m.at(N) << '\n';
	/*
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "Key : " << iter->first << "Value : " << iter->second << endl;
	}
	*/
	return 0;
}
