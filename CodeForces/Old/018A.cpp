using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
struct point {
    int x, y;
    bool operator == (const point &b) {return x == b.x && y == b.y;}
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool right(point a, point b, point c) {
    if (a == b || b == c || c == a) return 0;
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = c.x - b.x;
    int y2 = c.y - b.y;
    return (x1*x2 + y1*y2 == 0);
}
/*int dist(point a, point c) {
    return sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y- c.y));
}
int ccw(point a, point b, point c) {
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
}
bool almost(point a, point b, point c) {
    int r = dist(a, c)/2;
    point o;
    o.x = (a.x+c.x)/2;
    o.y = (a.y+c.y)/2;
    int
    k = dist(o, b);
    cout << r << " " << k << " " <<
    (fabs(r-k) < 1.0 || (fabs(r-k) == 1.0 && ccw(o, a, b) != 0)) << endl;
    return (fabs(r-k) < 1.0 || (fabs(r-k) == 1.0 && ccw(o, a, b) != 0));
}*/
bool almost(point a, point b, point c) {
    REP(i, 4){
        b.x += dx[i]; b.y += dy[i];
        if (right(a, b, c) || right(b, c, a) || right(c, a, b)) {
            return 1;
        }
        b.x -= dx[i]; b.y -= dy[i];
    }
    return 0;
}

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    point a, b, c;
    scanf("%d %d", &a.x, &a.y);
    scanf("%d %d", &b.x, &b.y);
    scanf("%d %d", &c.x, &c.y);
    if (right(a, b, c) || right(b, c, a) || right(c, a, b)) printf("RIGHT\n");
    else if (almost(a, b, c) || almost(b, c, a) || almost(c, a, b)) printf("ALMOST\n");
    else printf("NEITHER\n");
    return 0;
}
/** Happy Coding ^^ */
