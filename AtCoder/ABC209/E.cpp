#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

string str;
map<string, int> vertices;
int countVtx = 0, deg[N], dp[N], suf[N];
vector<int> par[N];
set<pair<int, int>> edges;
queue<int> ready;

int id(string str) {
  if (vertices.find(str) == vertices.end()) {
    vertices[str] = countVtx ++; 
  }
  return vertices[str];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++ i) {
    cin >> str;
    string head = str.substr(0, 3);
    string tail = str.substr(str.size() - 3, str.size());
    // cerr << head << ' ' << tail << '\n';
    int headId = id(head);
    int tailId = id(tail);
    suf[i] = tailId;
    
    if (edges.find({headId, tailId}) == edges.end()) {
      par[tailId].push_back(headId);
      deg[headId] ++;
      edges.insert({headId, tailId});
    }
  }
  // DRAW 0, LOSE -1, WIN 1
  for (int i = 0; i < countVtx; ++ i) {
    if (deg[i] == 0) {
      ready.push(i);
      dp[i] = -1;
    }
  }
  while (!ready.empty()) {
    int v = ready.front(); ready.pop();
    for (int u : par[v]) {
      if (dp[u] != 0) {
        continue;
      }
      deg[u] --;
      if (dp[v] == -1) {
        dp[u] = 1;
        ready.push(u);
      } else if (deg[u] == 0) {
        dp[u] = -1;
        ready.push(u);
      }
    }
  }
  for (int i = 0; i < n; ++ i) {
    if (dp[suf[i]] == 0) {
      cout << "Draw\n";
    } else if (dp[suf[i]] == 1) {
      cout << "Aoki\n";
    } else {
      cout << "Takahashi\n";
    }
  }
}