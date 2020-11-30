#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    string Case;
    int x, BIT = 0; // BIT를 반드시 0으로 초기화 해준다.
    while (M--)
    {
        cin >> Case;
        if (Case == "add") {
            cin >> x;
            // or 연산자를 통해 x번째 자리수를 1로 채운다.
            BIT |= (1 << x);
        }
        else if (Case == "remove") {
            cin >> x;
            // ex) 1000 & ~(1000) = 0000
            BIT &= ~(1 << x);
        }
        else if (Case == "check") {
            cin >> x;
            if (BIT & (1 << x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (Case == "toggle") {
            cin >> x;
            // BIT의 x번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
            // x번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
            BIT ^= (1 << x);
        }
        else if (Case == "all") {
            // ex) 10000 - 1 = 1111
            BIT = (1 << 21) - 1;
        }
        else if (Case == "empty") {
            BIT = 0;
        }
    }

    return 0;
}