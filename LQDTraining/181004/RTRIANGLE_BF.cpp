using namespace std;
#include <bits/stdc++.h>
#define mp make_pair
typedef pair<int, int> ii;
const int N = 1510;
int x[N], y[N], n;
long long res;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b);}

int main() {
    //double Time = clock();
    freopen("RTRIANGLE.INP", "r", stdin);
    freopen("RTRIANGLE.ANS", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        multiset<ii> data;
        for (int j = 1; j <= n; j++) if (j!=i) {
            int u = x[i] - x[j];
            int v = y[i] - y[j];
            if (u == 0) {
                res += data.count(mp(1, 0));
                data.insert(mp(0, 1));
            } else if (v == 0) {
                res += data.count(mp(0, 1));
                data.insert(mp(1, 0));
            }
            else {
                int t = gcd(abs(u), abs(v));
                u /= t; v /= t;
                if (v < 0) v = -v, u = -u;
                data.insert(mp(u, v));

                swap(u, v);
                if (v < 0) v = -v, u = -u;
                u = -u;
                res += data.count(mp(u, v));
            }
        }
        // cerr << i << ' ' << res << '\n';
    }
    printf("%lld\n", res);
    //Time = (clock() - Time)/double(CLOCKS_PER_SEC);
    //printf("%f\n", Time);
}
/*using namespace std;
#include <stdio.h>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#define mp make_pair
typedef pair<int, int> ii;
const int N = 1510;
int x[N], y[N], n;
long long res;
int gcd(int a, int b)
    { return (b == 0) ? a : gcd(b, a%b);}
int cnt(map<ii, int> &data, int u, int v) {
    if (data.find(mp(u, v)) == data.end()) return 0;
    else return data[mp(u, v)];
}
void push(map<ii, int> &data, int u, int v) {
    if (data.find(mp(u, v)) == data.end()) data[mp(u, v)] = 1;
    else data[mp(u, v)] ++;
}
int main() {
    double Time = clock();
    freopen("RTRIANGLE.INP", "r", stdin);
    freopen("RTRIANGLE.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        map<ii, int> data;
        //printf("%d\n", i);
        for (int j = 1; j <= n; j++) if (j!=i) {
            int u = x[i] - x[j];
            int v = y[i] - y[j];
            if (u == 0) {
                res += cnt(data, 1, 0);
                push(data, 0, 1);
            } else if (v == 0) {
                res += cnt(data, 0, 1);
                push(data, 1, 0);
            }
            else {
                int t = gcd(abs(u), abs(v));
                u /= t; v /= t;
                if (v < 0) v = -v, u = -u;
                push(data, u, v);

                swap(u, v);
                if (v < 0) v = -v, u = -u;
                u = -u;
                res += cnt(data, u, v);
            }
        }
    }
    printf("%lld\n", res);
    Time = (clock() - Time)/double(CLOCKS_PER_SEC);
    printf("%f\n", Time);
}*/
/*using namespace std;
#include <stdio.h>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#define mp make_pair
typedef pair<int, int> ii;
const int N = 1510;
int x[N], y[N], n;
long long res;
int gcd(int a, int b)
    { return (b == 0) ? a : gcd(b, a%b);}
map<ii, int> data;
int cnt(int u, int v) {
    if (data.find(mp(u, v)) == data.end()) return 0;
    else return data[mp(u, v)];
}
void push(int u, int v) {
    if (data.find(mp(u, v)) == data.end()) data[mp(u, v)] = 1;
    else data[mp(u, v)] ++;
}
int main() {
    double Time = clock();
    freopen("RTRIANGLE.INP", "r", stdin);
    freopen("RTRIANGLE.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        data.clear();
        //printf("%d\n", i);
        for (int j = 1; j <= n; j++) if (j!=i) {
            int u = x[i] - x[j];
            int v = y[i] - y[j];
            if (u == 0) {
                res += cnt(1, 0);
                push(0, 1);
            } else if (v == 0) {
                res += cnt(0, 1);
                push(1, 0);
            }
            else {
                int t = gcd(abs(u), abs(v));
                u /= t; v /= t;
                if (v < 0) v = -v, u = -u;
                push(u, v);

                swap(u, v);
                if (v < 0) v = -v, u = -u;
                u = -u;
                res += cnt(u, v);
            }
        }
    }
    printf("%lld\n", res);
    Time = (clock() - Time)/double(CLOCKS_PER_SEC);
    printf("%f\n", Time);
}
*/
