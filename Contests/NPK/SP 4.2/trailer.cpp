using namespace std;
#include <bits/stdc++.h>
struct Point {int x, y;};
struct Line {int a, b, c;};
const int N = 1e5 + 50;

int n;
Point p[N];
long long res;
double ptich(Point p, Point l1, Point l2) // Point p vs Line l1l2
{
    //printf("%d %d, %d %d, %d %d: ",p.x, p.y, l1.x, l1.y, l2.x, l2.y);
    double _a = l2.y - l1.y;
    double _b = l1.x - l2.x;
    double _c = l2.x * l1.y - l1.x * l2.y;
    //cout << _a * p.x + _b * p.y + _c << endl;
    return (_a * p.x + _b * p.y + _c);
}


int main()
{
    freopen("trailer.inp","r",stdin);
    freopen("trailer.out","w",stdout);
    Point O;
    O.x = 0; O.y = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &p[i].x, &p[i].y);

    for (int i = 1; i <= n-2; i++)
    for (int j = i+1; j <= n-1; j++)
    for (int k = j+1; k <= n; k++)
        if (i != j && j !=k && k != i)
        {
            //cout << i << " " << j << " " << k << "\n";
            double pt1, pt2, pt3;
            res +=
            ((ptich(p[i], p[j], p[k]) * ptich(O, p[j], p[k])) > 0) &&
            ((ptich(p[j], p[i], p[k]) * ptich(O, p[i], p[k])) > 0) &&
            ((ptich(p[k], p[i], p[j]) * ptich(O, p[i], p[j])) > 0);
            //cout << res << endl;
        }
    cout << res;
}
