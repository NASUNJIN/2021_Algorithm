#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int s, e;
vector<vector<int>> adjArray;
vector<int> visited;
stack<int> R;

char IoT_Class[][30] = {
"IoT개론", "기초수학", "C프로그래밍", "정보통신개론", "논리회로",
"전기전자회로", "자료구조", "알고리즘", "임베디드시스템기초",
"컴퓨터네트워크", "IoT플랫폼", "운영체제", "마이크로프로세서", "캡스톤디자인"
};

void DFS_TS(int v) {
    visited[v] = 1;

    for (int i = 0; i < adjArray[v].size(); i++) {
        int x = adjArray[v][i];
        if (visited[x] == 0) {
            DFS_TS(x);
        }
    }
    R.push(v);
}

void topologicalSort2() {
    for (int v = 1; v <= n; v++)
        visited[v] = 0;
    for (int v = 1; v <= n; v++) {
        if (visited[v] == 0) {
            DFS_TS(v);
        }
    }
}

void AddEdge(int start, int end) {
    adjArray[start].push_back(end);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    adjArray.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        AddEdge(s, e);
    }

    topologicalSort2();

    while (R.size()) {
        cout << IoT_Class[R.top() - 1] << " ";
        R.pop();
        if (R.size() != 0) cout << " --> ";
    }
}