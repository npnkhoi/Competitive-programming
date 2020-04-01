#include <bits/stdc++.h>
using namespace std;

const int ntest = 50;
const string name = "virus";

long long Rand(long long l, long long r) {
    return l + (
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) +
        rand() ) % (r-l+1);
}
void create() {
    ofstream inp((name + ".inp").c_str());
    int n = 3000, q = 11;
    //cout << "in\n";
    inp << q << "\n";
    for (int i = 1; i <= n; i++) inp << char(Rand(0, 25) + 'a');
    inp << "\n";
    for (int i = 0; i <= 10; i++) inp << i << "\n";
    inp.close();
    //cout << "ok\n";
}
int main() {
    for (int itest = 1; itest <= ntest; itest++) {
        //printf("%d\n", itest);
        create();

        double Time = clock();
        //printf("run\n");
        system((name + ".exe").c_str());
        Time = (clock() - Time) / double(CLOCKS_PER_SEC);
        //system((name + "_BF.exe").c_str());

        if (system(("fc " + name + ".out " + name + ".out").c_str())) {
            printf("@@@@@@@@@@@@@@@@@@@ WRONG ANSWER\n");
            return 0;
        }
        else printf("==> Test %d: %lf\n", itest, Time);
    }
    printf("Accepted");
    return 0;
}
