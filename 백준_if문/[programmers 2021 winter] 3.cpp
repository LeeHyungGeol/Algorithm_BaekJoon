#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef struct Node {
    int x1, x2, y1, y2;
}Node;

int N;
vector<int> Arr;
deque<int> Rows;
deque<int> Cols;
vector<Node> Nodes;

// 0 <= x < r0
int solution(vector<string> cakes, vector<int> cut_rows, vector<int> cut_columns) {
    int answer = 0;
    N = cakes.size();

    Rows.assign(cut_rows.begin(), cut_rows.end());
    Cols.assign(cut_columns.begin(), cut_columns.end());

    Rows.push_front(0);
    Rows.push_back(N);
    Cols.push_front(0);
    Cols.push_back(N);

    for (int i = 0; i < Rows.size() - 1; ++i) {
        int x1 = Rows[i], x2 = Rows[i + 1];
        for (int j = 0; j < Cols.size() - 1; ++j) {
            int y1 = Cols[j], y2 = Cols[j + 1];
            Nodes.push_back({ x1,x2,y1,y2 });
        }
    }

    for (Node n : Nodes) {
        set<char> Set;
        for (int i = n.x1; i < n.x2; ++i) {
            for (int j = n.y1; j < n.y2; ++j) {
                Set.insert(cakes[i][j]);
            }
        }
        answer = max(answer, (int)Set.size());
    }

    return answer;
}