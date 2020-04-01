#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
typedef pair<vi, int> pack;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName "LM"

const int N = 1e6 + 5;

int n, m;
vector<int> v;
queue<pack> q;
double Time;
bool mark[N];

int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    //double Time = clock();
    scanf("%d ", &n);

    string s;
    getline(cin, s);
    REP(i, s.size()) v.push_back(s[i] - '0');
    sort(v.begin(), v.end());
    m = v.size();

    q.push("");

    while (1) {
        //cerr << ++ cnt << "\n";
        //cerr << "ok\n";
        checkTime();
        memset(mark, 0, sizeof mark);
        int size = q.size();
        checkTime();
        while (size --) {
            vi num = q.front().fi;
            int r = q.front().se;
            q.pop();
            checkTime();
            REP(i, m) {
                if (num.empty() && v[i] == 0) continue;
                int tmp = (r * 10 + v[i]) % n;
                if (tmp == 0) {
                    REP(j, num.size()) printf("%d", num[j]);
                    printf("%d", v[i]);
                    exit(0);
                }
                if (mark[tmp] == 0) {
                    mark[tmp] = 1;
                    num.pb(v[i]);
                    q.push(mp(num, tmp));
                    //REP(j, num.size()) printf("%d", num[j]); printf(", %d\n", tmp);
                    num.pop_back();
                }
            }
        }
    }
    return 0;
}
/** Happy Coding :D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName "LM"
const int N = 1e6 + 2;
const int maxI = 50;
int n, m;
vector<int> v;
bool dp[maxI + 2][N];
ll Exp[maxI+2];

int mod(ll x) {
    x = x % n;
    if (x < 0) x += n;
    return x;
}
void trace(int i, int j) {
    if (i == 0) return;
    REP(k, m) {
        if (dp[i-1][mod(j - v[k] * Exp[i])]) {
            printf("%d", v[k]);
            trace(i-1, mod(j - v[k] * Exp[i]));
            break;
        }
    }
}
int main() {
    freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d ", &n);

    Exp[1] = 1;
    FOR(i, 2, maxI) Exp[i] = Exp[i-1] * 10 % n;

    string line;
    getline(cin, line);
    m = line.size();
    REP(i, m) v.push_back(line[i] - '0');
    sort(v.begin(), v.end());

    REP(i, m) {
        if (v[i] && v[i] % n == 0) {
            printf("%d", v[i]);
            exit(0);
        }
        dp[1][v[i]%n] = 1;
    }
    REP(j, n)
        printf("dp(%d, %d) = ", 1, j),
        cerr << dp[1][j] << "\n";

    FOR(i, 2, maxI) {
        REP(j, n) {
            REP(k, m) dp[i][j] |= dp[i-1][mod(j - v[k] * Exp[i])];
            printf("dp(%d, %d) = ", i, j);
            cerr << dp[i][j] << "\n";
        }
        if (dp[i][0]) {
            trace(i, 0);
            exit(0);
        }
    }
    printf("0");

    return 0;
}*/
