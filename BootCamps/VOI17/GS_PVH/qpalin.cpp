#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: GS.PVH */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Bignum {
    static const int numDigits = 18;
    static const long long BASE = (long long)1e18;
    long long dig[2];

    Bignum(long long x = 0) {
        memset(dig, 0, sizeof dig);
        dig[0] = x % BASE;
        dig[1] = x / BASE;
    }

    Bignum(string s) {
        reverse(ALL(s));
        while (s.size() < numDigits * 2) s.push_back('0');
        reverse(ALL(s));

        memset(dig, 0, sizeof dig);

        REP(i, s.size()) {
            int cur = i < numDigits ? 1 : 0;
            dig[cur] = dig[cur] * 10 + s[i] - '0';
        }
    }

    void operator += (const Bignum &a) {
        REP(i, 2) dig[i] += a.dig[i];
        if (dig[0] >= BASE) {
            dig[0] -= BASE;
            dig[1]++;
        }
        REP(i, 2) assert(dig[i] < BASE);
    }

    void operator -= (const Bignum &a) {
        assert(*this >= a);

        REP(i, 2) dig[i] -= a.dig[i];
        if (dig[0] < 0) {
            dig[0] += BASE;
            dig[1]--;
        }
    }

    #define COMP(a, b) (((a) > (b)) - ((a) < (b)))
    int compare(const Bignum &a) const {
        return dig[1] == a.dig[1] ? COMP(dig[0], a.dig[0]) : COMP(dig[1], a.dig[1]);
    }

    #define DEF_OPER(x) bool operator x (const Bignum &a) const { return compare(a) x 0; }
    DEF_OPER(>) DEF_OPER(>=) DEF_OPER(==)
};
istream& operator >> (istream &is, Bignum &x) {
    string s; is >> s;
    x = Bignum(s);
    return is;
}
ostream& operator << (ostream &os, const Bignum &x) {
    if (x.dig[1] != 0) os << x.dig[1];
    return os << x.dig[0];
}

bool canPalin(int mask) {
    return __builtin_popcount(mask) <= 1;
}

#define MAX   55
#define NUM_CHAR   6
Bignum f[MAX][MAX][MASK(NUM_CHAR)];
Bignum countWay(int len, int need, int oddChar, int numChar) {
    REP(i, len + 1) REP(j, need + 1) REP(k, MASK(numChar)) f[i][j][k] = 0;
    f[0][0][oddChar] = 1;

    REP(i, len) REP(j, need + 1) REP(k, MASK(numChar)) if (f[i][j][k] > 0) REP(l, numChar) {
         int newK = k ^ MASK(l);
         int newJ = min(j + canPalin(newK), need);
         f[i + 1][newJ][newK] += f[i][j][k];
    }

    Bignum res = 0;
    REP(i, MASK(numChar)) if (canPalin(i)) res += f[len][need][i];

    return res;
}

string solve(int len, int need, Bignum pos, string str) {
    sort(ALL(str));
    str.resize(unique(ALL(str)) - str.begin());

    string res;
    int oddChar = 0;
    int numPos = 0;

    FOR(i, 1, len) {
        bool ok = false;
        REP(j, str.size()) {
            int newOddChar = oddChar ^ MASK(j);
            int newNumPos = numPos + canPalin(newOddChar);

            Bignum cnt = countWay(len - i, max(need - newNumPos, 0), newOddChar, str.size());
            if (cnt >= pos) {
                res.push_back(str[j]);
                oddChar = newOddChar;
                numPos = newNumPos;
                ok = true;
                break;
            } else pos -= cnt;
        }
        assert(ok);
    }

    assert(pos == 1);
    return res;
}

void backtrack(string cur, int len, int need, int oddMask, int numChar, vector<string> &v) {
    if (cur.size() == len) {
        if (need <= 0 && __builtin_popcount(oddMask) <= 1) v.push_back(cur);
        return;
    }

    REP(i, numChar) {
        cur.push_back(i + 'a');
        int newOddMask = oddMask ^ MASK(i);
        int newNeed = need - (__builtin_popcount(newOddMask) <= 1);
        backtrack(cur, len, newNeed, newOddMask, numChar, v);
        cur.pop_back();
    }

}
void check(int len, int need, int numChar) {
    printf("checking len = %d, need = %d, numChar = %d\n", len, need, numChar);

    vector<string> v;
    backtrack("", len, need + 2, 0, numChar, v);
    sort(ALL(v));

    string s;
    REP(i, numChar) s.push_back(i + 'a');
    REP(love, 10) s.push_back(rand() % numChar + 'a');
    random_shuffle(ALL(s));

    REP(i, v.size()) {
        string ans = v[i];
        string out = solve(len, need + 2, i + 1, s);
        if (out != ans) {
            //printf("At len = %d | need = %d | pos = %lld | numChar = %d\n", len, need, i + 1, numChar);
            printf("Output: %s\n", out.c_str());
            printf("Answer: %s\n", ans.c_str());
            return;
        }
    }

    printf("OK %d tests\n", (int)v.size());
}

int main(void) {
#ifdef THEMIS
    freopen("qpalin.inp", "r", stdin);
    freopen("qpalin.out", "w", stdout);
#endif // THEMIS

//    srand(time(NULL));
//    FOR(i, 2, 7) FOR(j, 0, i - 2) FOR(k, 1, 6) check(i, j, k);
//    return 0;

    int len, need;
    Bignum pos;
    string str;
    while (cin >> len >> need >> str >> pos)
        cout << solve(len, need + 2, pos, str) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
