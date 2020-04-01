using namespace std;
#include <stdio.h>
#include <iostream>
int n, tmp;
int main()
{
    cin >> n;
    if (n<=2) {cout << -1; return 0;}
    if (n==3) {cout << 210; return 0; }
    tmp = 1000 % 210;
    for (int i = 5;i<=n;i++) tmp = (10*tmp)%210;
    cout << 1;
    for (int i=2;i<=n-3;i++) cout << 0;
    printf("%03d",210-tmp);
}
