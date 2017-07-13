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
const int N = 100;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
int dp[N][N][N][2];
vector<int> X, V, K;
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d", &n);
    scanf("%s", s);
    REP(i, 0, n){
        if(s[i] == 'V') V.pb(i);
        else if(s[i] == 'K') K.pb(i);
        else X.pb(i);
    }
    CLR(dp, INF);
    dp[0][0][0][0] = 0;
    REP(a, 0, SZ(X)){
        int x = X[a];
        REP(b, 0, SZ(V)){
            int v = V[b];
            REP(c, 0, SZ(K)){
                int k = K[c];
                int sp = 0;

                Min(dp[a][b][c][0], min(dp[a - 1][b][c][0], dp[a - 1][b][c][1]);
            }
        }
    }
    return 0;
}
