#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


/*
 * Complete the 'minimumGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY predators as parameter.
 */

vector<int> Roots;
vector<vector<int>> Tree;
vector<bool> Visited;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    Visited[start] = true;

    int level = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            int cur = q.front();
            q.pop();

            for (int next : Tree[cur]) {
                if (!Visited[next]) {
                    Visited[next] = true;
                    q.push(next);
                }
            }
        }

        ++level;
    }

    return level;
}

int minimumGroups(vector<int> predators) {
    Tree.resize((int)predators.size());
    Visited.resize((int)predators.size(), false);

    for (int i = 0; i < predators.size(); ++i) {
        if (predators[i] == -1) {
            Roots.push_back(i);
            continue;
        }
        Tree[i].push_back(predators[i]);
        Tree[predators[i]].push_back(i);
    }

    int answer = 0;

    for (int i = 0; i < Roots.size(); ++i) {
        int level = bfs(Roots[i]);
        answer = max(answer, level);
    }

    return answer;
}
int main()