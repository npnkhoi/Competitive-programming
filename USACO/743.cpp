#include <fstream>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const int N = 1e5 + 5;
int n;
vector<int> v;
int st[N], en[N];
bool mark[N];
stack<int> s;

int main() {
    ifstream fin("art2.in");
    ofstream fout("art2.out");

    fin >> n;
    REP(i, n) {
        int val;
        fin >> val;
        if (val != 0 && (v.empty() || val != v.back())) {
            v.push_back(val);
            if (mark[val] == 0) {
                mark[val] = 1;
                st[val] = en[val] = v.size() - 1;
            } else en[val] = v.size() - 1;
        }
    }
    //REP(i, v.size()) cerr << v[i] << " " << st[v[i]] << " " << en[v[i]] << "\n";

    int maxDepth = 0;
    REP(i, v.size()) {
        if (i == st[v[i]]) s.push(v[i]);
        maxDepth = max(maxDepth, (int)s.size());
        if (i == en[v[i]]) {
            if (s.top() != v[i]) {
                fout << -1;
                return 0;
            } else s.pop();
        }
    }
    fout << maxDepth;

}
