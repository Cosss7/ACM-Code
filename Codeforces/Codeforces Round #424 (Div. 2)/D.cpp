#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define reveach(i, v) for (__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++ i)
#define REP(i,a,n) for ( int i=a; i<int(n); i++ )
#define FOR(i,a,n) for ( int i=n-1; i>= int(a);i-- )
#define lson rt<<1, L, m
#define rson rt<<1|1, m, R
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
#define CLR(a, b) memset(a, b, sizeof(a))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define lowbit(x) (x) & (-(x))


const int N = 2e3 + 7;
const int INF = 2e9 + 7;

int n, k, p;

int a[N], b[N];

int dp[N][N];

int main(){
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d%d", &n, &k, &p);
    REP(i, 1, n + 1) scanf("%d", &a[i]);
    REP(i, 1, k + 1) scanf("%d", &b[i]);

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + k);

    REP(j, 0, k + 1) dp[0][j] = 0;

    REP(i, 1, n + 1){
        dp[i][0] = INF;
        REP(j, 1, k + 1){
            dp[i][j] = min(max(abs(a[i] - b[j]) + abs(b[j] - p), dp[i - 1][j - 1]), dp[i][j - 1]);
            //dp[i][j] = max(abs(a[i] - b[j]) + abs(b[j] - p), dp[i - 1][j - 1]);

        }
        //REP(j, 1, k + 1) Min(dp[i][j], dp[i][j - 1]);
    }
    printf("%d\n", dp[n][k]);
    return 0;
}
