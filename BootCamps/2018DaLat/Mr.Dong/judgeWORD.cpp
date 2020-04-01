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
#define REP(i,n) for (int i = 0; i < (n); ++i)

string name = "WORD";
int nTest = 10000;
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
    set<string> data;
    ofstream inp((name + ".inp").c_str());
    int s = Rand(1, 100);
    FOR(i, 1, s) {
        inp << char('a' + Rand(0, 25));
    }
    inp << endl;
    int n = Rand(1, 1000);
    inp << n << endl;
    FOR(i, 1, n) {
        int tmp = Rand(1, s);
        while (tmp --)
            inp << (char)('a' + Rand(0, 25));
        inp << endl;
        /*int tmp = 2;
        while (1) {
            string s = "";
            REP(z, tmp)
                s += char('a' + Rand(0, 25));
            if (data.find(s) == data.end()) {
                inp << s << "\n";
                data.insert(s);
                break;
            }
        }*/
        inp << Rand(1, 10000) << endl;
    }
    inp.close();
}
int main() {
    srand(time(NULL));

    for (int iTest = 1; iTest <= nTest; iTest++) {

        createTest();
        cerr << "Created test\n";

        double Time1 = clock();
        system((name + ".exe").c_str());
        Time1 = (clock() - Time1)/double(CLOCKS_PER_SEC);
        cerr << Time1 << endl;

        double Time2 = clock();
        system((name + "_BF.exe").c_str());
        Time2 = (clock() - Time2)/double(CLOCKS_PER_SEC);
        cerr << Time2 << endl;

        if (system(("fc " + name + ".out " + name + ".ans").c_str()) != 0) {
        //if (system(("fc " + name + ".out " + name + ".out").c_str()) != 0) {
            printf("Test %d: \x1b[31mWRONG!!\x1b[0m\n", iTest);
            return 0;
        }
        else printf("Test %d: \x1b[32mCORRECT\x1b[0m\n", iTest), score++;
    }
    printf("Score: %d/%d - Time: %f", score, nTest, maxTime);
    return 0;
}
/**/
