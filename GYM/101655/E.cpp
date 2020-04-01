/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = a ;i <= b ; ++i)
#define ROF(i,a,b) for (int i = a ;i >= b ; --i)
#define REP(i,a) for (int i = 0 ; i < a ; i++)
#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ll, ii>
#define fi first
#define se second
#define pb push_back
#define pu push

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const long long oo = 1e18;
const int nmax = 1e3 + 9 ;

int a[nmax][nmax];
long long d[nmax][nmax];
int T, diff, n, m, x, y;
int value[26];
priority_queue < iii, vector <iii>, greater<iii> > q;

void Inp(){
    cin >> diff >> m >> n;
    FOR(i, 1, diff){
        char ch;
        int val;
        cin >> ch >> val;
        value[ch-'A'] = val;
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            char ch;
            cin >> ch;
            if (ch == 'E'){
                x = i;
                y = j;
            }
            a[i][j] = value[ch-'A'];
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    return ;
}

void Process(){
    long long ans = oo;
    q.push(iii(0,ii(x,y)));
    FOR(i, 1, n){
        FOR(j, 1, m)
            d[i][j] = oo;
    }
    d[x][y] = 0;
    if (x == 1 || x == n || y == 1 || y == m){
        cout << 0 << "\n";
        return ;
    }
    int tmp = 1, _max = 1;
    int cnt = 0;
    while (!q.empty()){
        long long duv = q.top().fi;
        int u = q.top().se.fi;
        int v = q.top().se.se;
        if (cnt % 1000 == 0) {
        	cerr << ++ cnt << "\n";	
        }
        q.pop();
        tmp --;
        if (duv != d[u][v])
            continue;
        REP(i, 4){
            int uu = u + dx[i];
            int vv = v + dy[i];
            if (uu > n || uu < 1 || vv > m || vv < 1 || d[uu][vv] < d[u][v] + a[uu][vv])
                continue;
            d[uu][vv] = d[u][v] + a[uu][vv];
            if (uu == 1 || uu == n || vv == 1 || vv == m)
                ans = min (ans, d[uu][vv]);
            q.push(iii(d[uu][vv], ii (uu,vv)));
            tmp ++;
            _max = max(_max, tmp);
        }
    }
    cout << ans << "\n";
    cerr << "heap max size = " << _max << "\n";
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("E.inp", "r", stdin);
    freopen("E.out","w",stdout);
    cin >> T;
    while (T--){
        Inp();
        Process();
    }
    return 0;
}