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
const int N = 2e5 + 7;

int n, k;
ll dp[N][10], pd[N][10];
ll tp[N][10], pt[N][10];
vector<int> G[N];
ll res;

void dfs(int u, int f){
    ll num[10] = {0};
    ll tt[10] = {0};

    for(auto v : G[u]){
        if(v == f) continue;
        dfs(v, u);
        REP(i, 0, k){

            pd[u][(i + 1) % (k + 1)] += pd[v][i];
            dp[u][(i + 1) % (k + 1)] += dp[v][i];

            tp[v][(i + 1) % (k + 1)] = dp[v][i];
            pt[v][(i + 1) % (k + 1)] = pd[v][i];

        }

        dp[u][1] += dp[v][k] + pd[v][k];
        pd[u][1] += pd[v][k];

        tp[v][1] += dp[v][k] + pd[v][k];
        pt[v][1] += pd[v][k];

        REP(i, 0, k + 1){
            num[i] += pt[v][i];
            tt[i] += tp[v][i];
        }
    }
    //REP(i, 0, k + 1) num[i] += pd[u][i];
    for(auto v : G[u]){
        if(v == f) continue;
        REP(i, 0, k + 1){
            REP(j, 0, k + 1){
                if(i + j <= k){
                    res += tp[v][i] * (num[j] - pt[v][j]) + (tt[j] - tp[v][j]) * pt[v][i] - (num[j] - pt[v][j]) * pt[v][i];
                }
                else{
                    res += tp[v][i] * (num[j] - pt[v][j]) + (tt[j] - tp[v][j]) * pt[v][i];
                }
            }
        }
    }
    //printf("res[%d] = %lld\n", u, res);
    REP(i, 0, k + 1) res += dp[u][i] * 2;
    //REP(i, 0, k + 1) printf("dp[%d][%d] = %lld\n", u, i, dp[u][i]);
    //printf("res[%d] = %lld\n", u, res);
    dp[u][0] ++;
    pd[u][0] ++;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &k);
    REP(i, 1, n){
        int u, v;
        scanf("%d%d", &u, &v);
        u --, v --;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(0, -1);
    printf("%lld\n", res / 2);
    return 0;
}
