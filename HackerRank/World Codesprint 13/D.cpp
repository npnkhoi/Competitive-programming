#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;
int n;
char s[N];
vector<char> v;

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    int tmp = 0;
    bool ok = 1;
    FOR(i, 1, n) {
        scanf(" %c", &s[i]);
        if (s[i] == ')' && !v.empty() && v.back() == '(') v.pop_back();
        else v.push_back(s[i]);
    }
    if (v.empty()) printf("0");
    else if (v[0] == v.back()) printf("1");
    else printf("2");
}
