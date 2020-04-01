using namespace std;
#include <iostream>
#include <cmath>
unsigned long long n, m, d;
int main() {
    cin >> n >> m;
    if (n <= m) cout << n;
    else {
        d = sqrt(2*(n-m));
        while (d*d + d < 2*(n-m)) d++;
        cout << m + d;
    }
}
