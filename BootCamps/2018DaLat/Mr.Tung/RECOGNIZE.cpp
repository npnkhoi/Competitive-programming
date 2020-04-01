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

//ifstream inp("RECOGNIZE.inp");
//ofstream out("RECOGNIZE.out");
const int N = 1e5 + 5;

set<ii> data;
ii pa, pb, pc, pd;
vector<int> v[4];
bool sign1[N][4], sign2[N][4];
int sh;

void updateA() {
    while (sign1[pa.fi][pa.se]) {
        if (pa.se == 1) pa.se = 2;
        else ++ pa.fi, pa.se =1;
    }
}
void updateB() {
    while (sign1[pb.fi][pb.se]) {
        if (pb.se == 2) pb.se = 1;
        else ++ pb.fi, pb.se = 2;
    }
}
void updateC() {
    while (sign2[pc.fi-sh][pc.se]) {
        if (pc.se == 1) pc.se = 2;
        else -- pc.fi, pc.se =1;
    }
}
void updateD() {
    while (sign2[pd.fi-sh][pd.se]) {
        if (pd.se == 2) pd.se = 1;
        else -- pd.fi, pd.se = 2;
    }
}
int main() {
    freopen("RECOGNIZE.inp", "r", stdin);
    freopen("RECOGNIZE.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    //inp >> n >> k;
    if (n > 1e5) sh = n - 100000;
        else sh = 0;
    pa = mp(1, 1);
    pb = mp(1, 2);
    pc = mp(n, 1);
    pd = mp(n, 2);
    FOR(i, 1, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        //inp >> x  >> y;
        ii tmp = mp(x, y);
        if (tmp == pa) {
            v[0].push_back(i);
            if (pa.se == 1) pa.se = 2;
            else ++ pa.fi, pa.se =1;
        }
        if (tmp == pb) {
            v[1].push_back(i);
            if (pb.se == 2) pb.se = 1;
            else ++ pb.fi, pb.se = 2;
        }
        if (tmp == pc) {
            v[2].push_back(i);
            if (pc.se == 1) pc.se = 2;
            else -- pc.fi, pc.se =1;
        }
        if (tmp == pd) {
            v[3].push_back(i);
            if (pd.se == 2) pd.se = 1;
            else -- pd.fi, pd.se = 2;
        }
        if (x <= 100001) sign1[x][y] = 1;
        if (x-sh <= 100000) sign2[x-sh][y] = 1;
        updateA();
        updateB();
        updateC();
        updateD();
    }
    REP(i, 4) {
        printf("%d ", v[i].size());
        //out << v[i].size() << " ";
        if (v[i].size()) REP(j, v[i].size())
            printf("%d ", v[i][j]);
            //out << v[i][j] << " ";
        printf("\n");
        //out << "\n";
    }
    printf("%d ", k);
    //out << k << " ";
    FOR(i, 1, k)
    printf("%d ", i);
    out << i << " ";

    return 0;
}
/** Happy Coding :D */
