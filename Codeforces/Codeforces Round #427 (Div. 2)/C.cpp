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

const int N = 1e5 + 7;
const int M = 1e2 + 7;

int n, q, c;

int a[M][M][M][11];
int g[M][M][11];
int v[M][M];

int main(){
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("/Users/cosss/out.txt","w",stdout);
    scanf("%d%d%d", &n, &q, &c);
    REP(i, 0, n){
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);

        REP(j, 0, c + 1){
            g[x][y][j] += (s + j) % (c + 1);
        }
        v[x][y] = 1;
    }

    REP(i, 1, M){
        REP(j, 1, M){
            REP(l, 0, c + 1){
                if(v[i][j])
                a[i][j][j][l] = g[i][j][l];
                else
                    a[i][j][j][l] = 0;
            }
            REP(k, j + 1, M){
                REP(l, 0, c + 1){
                    if(v[i][k])
                    a[i][j][k][l] = a[i][j][k - 1][l] + g[i][k][l];
                    else
                        a[i][j][k][l] = a[i][j][k - 1][l];
                }
            }
        }
    }

    while(q --){
        int x1, y1, x2, y2, t;

        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);

        int b = t % (c + 1);
        int res = 0;
        REP(i, x1, x2 + 1){
            res += a[i][y1][y2][b];
        }
        printf("%d\n", res);
    }
    return 0;
}
