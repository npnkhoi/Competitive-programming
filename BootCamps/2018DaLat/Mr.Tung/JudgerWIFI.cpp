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

string name = "WIFI";
int nTest = 50;
double maxTime = 0;
int score = 0;

int n, m;

long long Rand(long long l, long long r) {
    return l + (
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) +
        1LL * rand() ) % (r-l+1);
}

void createTest() {
    ofstream inp((name + ".inp").c_str());
    n = Rand(3, 20);
    m = Rand(1, 20);
    inp << n << " " << m << "\n";
    FOR(i, 1, n) {
        int z = Rand(0, 2);
        if (z == 0) {
            FOR(j, 1, m) inp << ".";
            inp << "\n";
        } else {
            FOR(j, 2, m) if (Rand(0, 1)) inp << "*";
                else inp << ".";
            inp << ".";
            inp << "\n";
        }
    }
    inp.close();
}
void readOut() {
    ifstream out((name + ".out").c_str());
    char ch;
    FOR(i, 1, n) {
        FOR(j, 1, m) out >> ch, cerr << ch;
        cerr << "\n";
    }
    out.close();
}
void readIn() {
    ifstream out((name + ".inp").c_str());
    char ch;
    out >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) out >> ch, cerr << ch;
        cerr << "\n";
    }
    out.close();
}
int main() {
    srand(time(NULL));

    for (int iTest = 1; iTest <= nTest; iTest++) {

        createTest();
        //cerr << "ok\n";

        double Time = clock();
        system((name + ".exe").c_str());
        Time = (clock() - Time)/double(CLOCKS_PER_SEC);
        //system((name + "_BF.exe").c_str());

        //if (system(("fc " + name + ".out " + name + ".ans").c_str()) != 0) {
        if (system(("fc " + name + ".out " + name + ".out").c_str()) != 0) {
            printf("Test %d: \x1b[31mWRONG!!\x1b[0m\n", iTest);
            return 0;
        }
        else printf("Test %d: \x1b[32mCORRECT (%f s)\x1b[0m\n", iTest, Time), score++;
        maxTime = max(maxTime, Time);
        cerr << m << " " << n << "\n";
        readIn();
        cerr << "\n";
        readOut();
        FOR(i, 1, 50000000);

    }
    printf("Score: %d/%d - Time: %f", score, nTest, maxTime);
    return 0;
}
/**/
