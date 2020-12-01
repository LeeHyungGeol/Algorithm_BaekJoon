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
    int x, bit = 0; // BIT�� �ݵ�� 0���� �ʱ�ȭ ���ش�.
    for (int i = 0; i < M; ++i) {
        cin >> Case;
        if (Case == "add") {
            cin >> x;
            // or �����ڸ� ���� x��° �ڸ����� 1�� ä���.
            bit |= (1 << x);
        }
        else if (Case == "remove") {
            cin >> x;
            // ex) 1000 & ~(1000) = 0000
            bit &= ~(1 << x);
        }
        else if (Case == "check") {
            cin >> x;
            if (bit & (1 << x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (Case == "toggle") {
            cin >> x;
            // BIT�� x��° �ڸ��� 1�̶�� 1^1=0�� �Ǿ� 1->0�� �ǰ�
            // x��° �ڸ��� 0�̶�� 0^1=1 �� �Ǿ� 0 -> 1�� �ȴ�.
            bit ^= (1 << x);
        }
        else if (Case == "all") {
            // ex) 10000 - 1 = 1111
            bit = (1 << 21) - 1;
        }
        else if (Case == "empty") {
            bit = 0;
        }
    }

    return 0;
}

//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int arr[21];
//
//void add(int x) {
//    arr[x] = 1;
//}
//
//void remove(int x) {
//    arr[x] = 0;
//}
//
//void check(int x) {
//    printf("%d\n", arr[x]);
//}
//
//void toggle(int x) {
//    if (arr[x]) arr[x] = 0;
//    else arr[x] = 1;
//}
//
//void all() {
//    for (int i = 1; i <= 20; ++i)
//        arr[i] = 1;
//}
//
//void empty() {
//    for (int i = 1; i <= 20; ++i)
//        arr[i] = 0;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int N; scanf("%d", &N);
//
//    for (int i = 0; i < N; ++i) {
//        string str; cin >> str;
//        int num;
//
//        if (str == "add") {
//            cin >> num;
//            add(num);
//        }
//
//        else if (str == "remove") {
//            cin >> num;
//            remove(num);
//        }
//
//        else if (str == "check") {
//            cin >> num;
//            check(num);
//        }
//
//        else if (str == "toggle") {
//            cin >> num;
//            toggle(num);
//        }
//
//        else if (str == "all") all();
//
//        else if (str == "empty") empty();
//    }
//
//    return 0;
//}