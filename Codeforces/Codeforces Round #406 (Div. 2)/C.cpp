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
const int N = 1e4 + 7;

int n;
vector<int> a[2];
int dp[2][N];
int vis[2][N];
void dfs(int u, int x){
    vis[x][u] = 2;
    for(auto t : a[x]){
        int v = (u + t) % n;
        if(vis[!x][v] == 0){
            dfs(v, !x);
        }
        if(vis[!x][v] == 2) dp[x][u] = dp[!x][v] = 2;
        else if(dp[!x][v] == 0) dp[x][u] = 1;
        else if(dp[!x][v] == 2 && dp[x][u] != 1) dp[x][u] = 2;
    }
    vis[x][u] = 1;
}
int main(){
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif
    //freopen("out.txt","w",stdout);
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    REP(i, 0, k){
        int x;
        scanf("%d", &x);
        a[0].pb(x);
    }
    scanf("%d", &k);
    REP(i, 0, k){
        int x;
        scanf("%d", &x);
        a[1].pb(x);
    }

    //dp[0][0] = dp[1][0] = 0;
    REP(i, 1, n){
        REP(j, 0, 2){
            if(vis[j][i] == 0){
                dfs(i, j);
            }
        }
    }

    REP(i, 0, 2){
        REP(j, 1, n){
            if(dp[i][j] == 1) printf("Win ");
            else if(dp[i][j] == 0) printf("Lose ");
            else printf("Loop ");
        }
        puts("");
    }
    return 0;
}
