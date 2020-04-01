#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;
const int N = 1000;
const int M = 1000000;
bool f[M+50];
int n,m,x;
int main()
{
    //freopen("","r",stdin);
    freopen("GIFTS.inp","w",stdout);
    memset(f,0,sizeof(f));
    srand(time(NULL));

    m = rand()% (N/2) + 1;
    //m = N;
    cout << m << endl;
    while (m--)
    {
        int x;
        do x = rand()% M + 1;
            while (f[x]);
        cout << x << endl;
        f[x] = 1;
    }
    n = rand()% M + 1;
    //n = 10;
    cout << endl;
    cout << n << endl;
    while (n--)
    {
        cout << rand()%M +1 <<endl;
    }



    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
