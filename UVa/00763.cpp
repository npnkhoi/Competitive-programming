using namespace std;
#include <stdio.h>
#include <iostream>
#include <string>

string a, b, z;
int main() {
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int tc = 0;
    while (getline(cin, a)) {
        tc++;
        getline(cin, b);
        scanf("\n");
        if (tc >= 2) printf("\n");
        while (a.size() < b.size()) a = '0' + a;
        while (b.size() < a.size()) b = '0' + b;

        //printf("%s\n%s\n%s\n", a.c_str(), b.c_str(), z.c_str());

        int n = a.size();

        for (int i = 0; i < n; i++) a[i] += b[i] - '0';
        a = '0' + a;
        printf("%s\n", a.c_str());

        while (1) {
            bool ok = true;
            for (int i = 1; i <= n; i++) if (a[i] >= '2') {
                int t = a[i] - '0';
                ok = false;
                a[i-1] += t/2;
                if (i < n) a[i+1] += t/2;
                a[i] = '0' + t%2;
                printf("%s\n", a.c_str());
            }
            if (ok) break;
        }

        printf("%s\n", a.c_str());
    }
}
