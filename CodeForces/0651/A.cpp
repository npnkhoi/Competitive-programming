using namespace std;
#include <bits/stdc++.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int res = 0;
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a -= 2;
        b += 1;
        res++;
    }
    cout <<  res - (a < 0);
}
