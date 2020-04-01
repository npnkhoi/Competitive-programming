using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define ll long long
#define ii pair<int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

string name = "substr";
int nTest = 10;
double maxTime = 0;
int score = 0;

long long Rand(long long l, long long r) {
    return l + (
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) +
        rand() ) % (r-l+1);
}

void createTest() {
    ofstream inp((name + ".inp").c_str());
    int m = Rand(10, 10000);
    int n = Rand(1, m/2);
    for (int i = 1; i <= m; i++) inp << char('a' + Rand(0, 25));
    inp << endl;
    for (int i = 1; i <= n; i++) inp << char('a' + Rand(0, 25));
}
int main() {
    srand(time(NULL));

    for (int iTest = 1; iTest <= nTest; iTest++) {

        createTest();

        double Time = clock();
        system((name + ".exe").c_str());
        Time = (clock() - Time)/double(CLOCKS_PER_SEC);
        system((name + "_BF.exe").c_str());

        if (system(("fc " + name + ".out " + name + ".ans").c_str()) != 0)
            printf("Test %d: \x1b[31mWRONG!!\x1b[0m\n", iTest);
        else printf("Test %d: \x1b[32mCORRECT :))\x1b[0m\n", iTest), score++;

        maxTime = max(maxTime, Time);
    }
    printf("Score: %d/%d - Time: %f", score, nTest, maxTime);
    return 0;
}
/**/
