#include <iostream>
using namespace std;

int main() {

	int N, i, j;

	//º°Âï±â ±âº»
	/*
	*
	**
	***
	****
	*****
	*/
	/*
	cin >> N;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++)
			cout << "*";
		cout << '\n';
	}
	*/
	/*
	  *
     **
    ***
   ****
  *****
	*/
	cin >> N;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (j > N - i)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}