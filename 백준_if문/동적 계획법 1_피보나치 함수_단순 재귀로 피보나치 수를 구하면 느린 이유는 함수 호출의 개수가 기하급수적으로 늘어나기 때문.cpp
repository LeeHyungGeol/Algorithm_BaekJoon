#include <iostream>
using namespace std;

int cnt0[41] = { 1,0, };
int cnt1[41] = { 0,1, };
int fibonacci0(int n);
int fibonacci1(int n);

int main() {

    int T, input;
    for (int i = 2; i <= 40; ++i) {
        cnt0[i] = -1;
        cnt1[i] = -1;
    }
    //fibonacci0(40);
    //fibonacci1(40);
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> input;
        fibonacci0(input);
        fibonacci1(input);
        cout << cnt0[input] << " " << cnt1[input] << '\n';
    }

	return 0;
}
int fibonacci0(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 0;
    }
    else {
        if (cnt0[n] != -1)
            return cnt0[n];
        cnt0[n] = fibonacci0(n - 1) + fibonacci0(n - 2);
        return cnt0[n];
    }
}
int fibonacci1(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        if (cnt1[n] != -1)
            return cnt1[n];

        cnt1[n] = fibonacci1(n - 1) + fibonacci1(n - 2);
        return cnt1[n];
    }
}