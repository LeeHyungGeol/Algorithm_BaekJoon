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
    int x, BIT = 0; // BIT�� �ݵ�� 0���� �ʱ�ȭ ���ش�.
    while (M--)
    {
        cin >> Case;
        if (Case == "add") {
            cin >> x;
            // or �����ڸ� ���� x��° �ڸ����� 1�� ä���.
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
            // BIT�� x��° �ڸ��� 1�̶�� 1^1=0�� �Ǿ� 1->0�� �ǰ�
            // x��° �ڸ��� 0�̶�� 0^1=1 �� �Ǿ� 0 -> 1�� �ȴ�.
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