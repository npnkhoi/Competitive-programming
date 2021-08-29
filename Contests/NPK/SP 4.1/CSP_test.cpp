#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

int main()
{
    //freopen("","r",stdin);
    freopen("CSP.inp","w",stdout);
    srand (time(NULL));
    int n = rand()%1000 + 1;
    int m = rand()%1000 + 1;
    cout << n << " " << m << endl;
    while (n--) cout << rand() % m << " ";
    system("csp.exe");
    system("csp_bf.exe");
    system("fc csp.out cspbf.out");
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
