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

const int N = 1e3 + 7;
const int INF = 0x3f3f3f3f;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k;

char g[N][N];
int v[N][N];

int sx, sy, ex, ey;

int main(){
#ifdef LOCAL_TEST
    freopen("/Users/cosss/in.txt","r",stdin);
#endif
    //freopen("/Users/cosss/out.txt","w",stdout);

    scanf("%d%d%d", &n, &m, &k);

    REP(i, 0, n){
        scanf("%s", g[i]);
    }

    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    sx --, sy --, ex --, ey --;

    queue<pii> q;

    CLR(v, INF);
    v[sx][sy] = 0;
    q.push(mp(sx, sy));

    while(!q.empty()){
        pii t = q.front(); q.pop();

        int x = t.fi, y = t.se;
        int s = v[x][y];
//printf("x = %d, y = %d, v = %d\n", x, y, v[x][y]);

        if(ex == x && ey == y) break;

        REP(i, 0, 4){
            REP(j, 1, k + 1){
                int tx = x + dx[i] * j;
                int ty = y + dy[i] * j;

                if(tx < 0 || tx >= n || ty < 0 || ty >= m) break;

                if(g[tx][ty] == '#') break;

                if(v[tx][ty] == s + 1) continue;
                if(v[tx][ty] <= s) break;

                v[tx][ty] = s + 1;
                q.push(mp(tx, ty));
            }
        }

    }

    printf("%d\n", v[ex][ey] == INF ? -1 : v[ex][ey]);

    return 0;
}
