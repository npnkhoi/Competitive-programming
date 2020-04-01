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

string s;
int res;
bool isvowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i' || ch == 'o';
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    getline(cin, s);
    REP(i, s.size())
        res += (isvowel(s[i])) || (isdigit(s[i]) && (s[i] - '0') % 2 == 1);
    printf("%d", res);
}
/// Expelliarmus !
