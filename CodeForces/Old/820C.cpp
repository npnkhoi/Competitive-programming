#include <bits/stdc++.h>

using namespace std;
int a, b, l , r, x, y;
int f[50];
int diff(int x, int y)
{
    //cout << "diff " << x << " " << y << "\n";
    set<int> data;
    int s = 0;
    for (int i = x; i <= y; i++)
        if (data.find(f[i])==data.end()) s++, data.insert(f[i]);
    return s;
}
void sol1()
{
    x = x%((a+b)); if (x==0) x = (a+b);
    y = y%((a+b)); if (y==0) y = (a+b);
    if (x<y) cout << diff(x,y);
    else cout << diff(1,(a+b)) - diff(y+1, x-1);
}
void sol2()
{
    x = x%(2*(a+b)); if (x==0) x = 2*(a+b);
    y = y%(2*(a+b)); if (y==0) y = 2*(a+b);
    //cout << x << " " << y <<"\n";
    if (x<y) cout << diff(x,y);
    else cout << diff(1,2*(a+b)) - diff(y+1, x-1);
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> a >> b >> l >> r;
    x = l; y = r;
    if (a==1 && b ==1)
    {
        if (r>l) cout << 2;
        else cout << 1;
        return 0;
    }

    if (a<b)
    {
        for (int i = 1; i <= a; i++) f[i] = i;
        for (int i = 1; i <= b; i++) f[a+i] = a;
        for (int i = 1; i < a; i++) f[a+b+i] = i;
        f[a+b+a] = a+1;
        for (int i = 1; i <= b; i++) f[a+b+a+i] = a;
    }
    else
    {
        for (int i = 1; i <= a; i++) f[i] = i;
        for (int i = 1; i <= b; i++) f[a+i] = a;

        for (int i = 1; i <= b; i++) f[a+b+i] = i;
        for (int i = 1; i <= a-b; i++) f[a+2*b+i] = a+i;
        for (int i = 1; i <= b; i++) f[a+b+a+i] = a+a-b;
    }
    //for (int i = 1; i<= 2*(a+b); i++) cout << f[i] << " ";
    //cout << "\n";
    /*if (r-l+1 <= a+b)
        sol1();
    else if (r-l+1 <= 2*(a+b))
        sol2();*/
    if (r-l+1 <= (a+b)) sol1();
    else if (r-l+1<=2*(a+b)) sol2();
    else cout << diff(1, 2*(a+b));
    return 0;
}
/**/
