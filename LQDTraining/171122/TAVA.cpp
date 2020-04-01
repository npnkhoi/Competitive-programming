using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int M = 505;
const ll oo = 1e9 + 7;
int n, m, k, x;
ll Exp[M];
string str, ans, s[M];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TAVA.inp", "r", stdin);
    freopen("TAVA.out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d%d%d%d ", &n, &m, &k, &x);
    getline(cin, str);
    REP(i, m) {
        getline(cin, s[i]);
        sort(s[i].begin(), s[i].end());
    }
    //----------------------------
    Exp[0] = 1;
    FOR(i, 1, m) {
        if (Exp[i-1] == oo) Exp[i] = oo;
        else {
            Exp[i] = Exp[i-1] * k;
            if (Exp[i] > 1e9) Exp[i] = oo;
        }
        //cerr << Exp[i] << "\n";
    }
    //----------------------------
    int cnt = 0;
    REP(i, n) if (str[i] != '#') ans.push_back(str[i]);
    else {
        m--;
        //cerr << "hihi\n";
        //cerr << x << " " << Exp[m] << "\n";
        FORD(j, k-1, 0) {
            //cerr << x << " " << Exp[m] * j << "\n";
            if (x > Exp[m]*j) {
                x -= Exp[m]*j;
                ans.push_back(s[cnt][j]);
                break;
            }
        }
        cnt ++;
        //m --;

    }
    printf("%s", ans.c_str());
    return 0;
}
/** Happy Coding :D */
