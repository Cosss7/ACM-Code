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

const int N = 111;

int n, m;

char s[N][N];
int g[N][N];
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    REP(i, 0, n) scanf("%s", s[i]);
    REP(i, 0, n) REP(j, 0, m) g[i][j] = s[i][j] == 'B';
    int u, d, l, r;
    u = l = N;
    r = d = -1;
    int ans = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(g[i][j] == 1){
                Max(r, j);
                Max(d, i);
                Min(u, i);
                Min(l, j);
                ans --;
            }
        }
    }
    pii ld = mp(l, d);
    pii ru = mp(r, u);

    //printf("l = %d, d = %d, r = %d, u = %d\n", l, d, r, u);
    int a = d - u + 1, b = r - l + 1;
    //printf("a = %d, b= %d\n", a, b);
    if(ans == 0){
        puts("1");
        return 0;
    }
    if(a > b){
        if(n < a || m < a){
            puts("-1");
            return 0;
        }
        ans += a * a;
    }
    else{
        if(m < b || n < b){
            puts("-1");
            return 0;
        }
        ans += b * b;
    }
    printf("%d\n", ans);
    return 0;
}
