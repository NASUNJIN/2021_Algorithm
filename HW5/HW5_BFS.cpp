#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int s, e;

vector<vector<int>> adjArray;
vector<int> visited;

void BFS() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        printf("%d ", current);

        for (int i = 0; i < adjArray[current].size(); i++) {
            int next = adjArray[current][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void AddEdge(int start, int end) {
    adjArray[start].push_back(end);
    adjArray[end].push_back(start);
}

void printGraph() {
    for (int i = 1; i <= n; i++) {
        cout << i << " :  ";
        for (int j = 0; j < adjArray[i].size(); j++)
            cout << adjArray[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    adjArray.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        AddEdge(s, e);
    }
    printGraph();
    BFS();
}