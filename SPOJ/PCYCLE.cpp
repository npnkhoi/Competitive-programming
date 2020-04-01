#include <cstdio>
#include <stack>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
const int N = 205;
int n, m;
int a[N][N], deg[N];
bool Link[N][N];
stack<int> Stack;
vector<int> eulerTour;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        a[u][v] = a[v][u] = c;
        Link[u][v] = Link[v][u] = 1;
        deg[u] ++; deg[v] ++;
    }
    for (int u = 1; u <= n; u++)
    if (deg[u] % 2) {
        printf("-1");
        exit(0);
    }

    Stack.push(1);
    while (!Stack.empty()) {
        int u = Stack.top();
        for (int v = 1; v <= n; v++)
            if (Link[u][v]) {
                Link[u][v] = Link[v][u] = 0;
                Stack.push(v);
                break;
            }
        if (Stack.top() == u) {
            eulerTour.push_back(u);
            Stack.pop();
        }
    }
    //for (int i = 0; i < eulerTour.size(); i ++) cerr << eulerTour[i] << " ";
    //cerr << "\n";

    int s = 0, minS = 0, start = 1;
    for (int i = 1; i < eulerTour.size(); i++) {
        s += a[eulerTour[i-1]][eulerTour[i]];
        if (s < minS) {
            start = i;
            minS = s;
        }
    }

    if (s < 0) {
        printf("-1");
        exit(0);
    }
    eulerTour.pop_back();
    for (int i = start; i < eulerTour.size(); i++) printf("%d ", eulerTour[i]);
    for (int i = 0; i <= start; i ++) printf("%d ", eulerTour[i]);
}
