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

string name = "H";
int nTest = 50;
double maxTime = 0;
int score = 0;

long long Rand(long long l, long long r) {
    return l + (
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) +
        1LL * rand() ) % (r-l+1);
}

void createTest() {
    ofstream inp((name + ".inp").c_str());
    inp << "1\n";
    int maxA = 10;
    int n = Rand(1, 100);

    inp << "5\n";
    inp << "1 2 " << Rand(1, (ll)maxA) << "\n";
    inp << "2 5 " << Rand(1, (ll)maxA) << "\n";
    inp << "2 3 " << Rand(1, (ll)maxA) << "\n";
    inp << "3 4 " << Rand(1, (ll)maxA) << "\n";
    //inp << "5 8 " << Rand(1, (ll)1e9) << "\n";
    //inp << "5 6 " << Rand(1, (ll)1e9) << "\n";
    //inp << "1 3 " << Rand(1, (ll)maxA) << "\n";
    inp.close();
}
int main() {
    srand(time(NULL));

    for (int iTest = 1; iTest <= nTest; iTest++) {

        //createTest();

        double Time = clock();
        system((name + ".exe").c_str());
        Time = (clock() - Time)/double(CLOCKS_PER_SEC);
        system((name + "_BF.exe").c_str());

        if (system(("fc " + name + ".out " + name + ".ans").c_str()) != 0) {
        //if (system(("fc " + name + ".out " + name + ".out").c_str()) != 0) {
            printf("Test %d: \x1b[31mWRONG!!\x1b[0m\n", iTest);
            return 0;
        }
        else printf("Test %d: \x1b[32mCORRECT (%f s)\x1b[0m\n", iTest, Time), score++;
        maxTime = max(maxTime, Time);
    }
    printf("Score: %d/%d - Time: %f", score, nTest, maxTime);
    return 0;
}
/**/
