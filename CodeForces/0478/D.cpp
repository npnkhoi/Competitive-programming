using namespace std;
#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#define pb push_back
const int N = 2e5 + 10;
const int md=  1e9 + 7;
int r, g, h, res;
int f[2][N];
long long total(int h) {return 1LL*h*(h+1)/2;}
int main() {
    scanf("%d%d", &r, &g);
    f[1][0] = 1;
    for (h = 1; h*(h+1)/2 <= r+g; h++) {
        int total = h*(h+1)/2;
        for (int i = 0; i <= r; i++) {
            f[0][i] = f[1][i];
            if (i + g < total || i > total) f[1][i] = 0;
            else if (i >= h) f[1][i] = (f[0][i] + f[0][i-h]) % md;
            else f[1][i] = f[0][i];
        }
        //printf("\n");
    }
    for (int i = 0; i <= r; i++) res = (res + f[1][i]) % md;
    printf("%d", res);
}
/*using namespace std;
#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#define pb push_back
const int N = sqrt(2e5)+2;
const int md = 1e9 + 7;
vector<int> f[N];
int n, h;
int main() {
    scanf("%d%d", &n, &h);
    h += n;
    h = int(floor(sqrt(2*h)));
    printf("%d %d\n", n, h);
    f[0].pb(0);
    for (int i = 1; i <= h; i++)
    for (int j = 0; 2*j <= min(2*n, i*(i+1)); j++) {
        int s;
        if (j == 0) s = 1;
        else {
            if (2*j <= i*(i-1)) s = f[i-1][j];
            if (j>=i && 2*(j-i) <= i*(i-1)) s+= f[i-1][j-i];
        }
        f[i].pb(s);
    }
    for (int i = 0; i <= h; i++)
    for (int j = 0; j < f[i].size(); j++) cout << f[i][j] << " \n"[j==f[i].size()-1];
    printf("%d", f[h][n]);
}
*/
