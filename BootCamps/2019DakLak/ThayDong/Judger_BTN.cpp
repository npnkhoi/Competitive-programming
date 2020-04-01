#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define task "btn3"

const int nTest = 100;
const double TimeLimit = 1.0;

double maxTime = 1.0;
int score = 0;

long long Rand(long long l, long long r) {
    return l + (1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) +
                1LL * rand() ) % (r-l+1);
}

void randSign(string &s, int l, int r) {
    int x = Rand(0, 2);
    if (x == 0) s[l] = '(', s[r] = ')';
    else if (x == 1) s[l] = '[', s[r] = ']';
    else s[l] = '{', s[r] = '}';
}
int idx = 0;
void randBrac(string &s, int l, int r) {
    if (l > r) return;
    idx ++;
    //cerr << "rand bracker " << l << " " << r << " " << idx << "\n";
    int deci = Rand(0, 3);
    if (deci && r - l + 1 > 2) {
        int len = Rand(2, r-l+1); len -= len % 2;
        int mid = l + len - 1;
        randBrac(s, l, mid); randBrac(s, mid+1, r);
    } else {
        randSign(s, l, r);
        randBrac(s, l+1, r-1);
    }
    idx --;
}

int depth(string &s) {
    int res = 0, tmp = 0;
    REP(i, s.size()) if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        tmp ++;
        res = max(res, tmp);
    } else tmp --;
    return res;
}

void test() {
    ofstream inp(task".inp");
    int n = 2 * Rand(5, 5);
    int k = Rand(1, n/2);
    string s; s.resize(n);
    randBrac(s, 0, n-1);
    inp << n << " " << Rand(depth(s), n/2) << "\n";
    inp << s << "\n";
    cerr << s << "\n";
    inp.close();
}
int main() {
    srand(time(NULL));

    FOR(iTest, 1, nTest) {
        printf("* TEST NUMBER %d\n", iTest);

        test();

        double Time1 = clock();
        system(task".exe");
        Time1 = (clock() - Time1)/double(CLOCKS_PER_SEC);

        double Time2 = clock();
        system(task"_old.exe");
        Time2 = (clock() - Time2)/double(CLOCKS_PER_SEC);

        printf("Time: %f - %f\n", Time1, Time2);

        if (system("fc "task".out "task".ans")) {
        //if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        else {
            printf("CORRECT\n");
            if (Time1 > TimeLimit) {
                printf("TIME LIMIT EXCEEDED\n");
                return 0;
            }
        }
    }
    return 0;
}
/**/
