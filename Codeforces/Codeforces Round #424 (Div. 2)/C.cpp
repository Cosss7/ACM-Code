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
#include <unordered_map>
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

int k, n;

int a[N], b[N];
int c[N], vis[N];
int sum[N];

unordered_map<int, int> id, tmp;

int main(){
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &k, &n);
    REP(i, 0, k) scanf("%d", &a[i]);
    REP(i, 0, n) scanf("%d", &b[i]);

    sum[0] = a[0];
    REP(i, 1, k) sum[i] = sum[i - 1] + a[i];

    REP(i, 0, n){
        REP(j, 0, k){
            if(i == 0 || id.find(b[i] - sum[j]) != id.end()){

                //printf("i = %d, j = %d\n", i, j);
                tmp[b[i] - sum[j]] = 1;
            }
        }
        id = tmp;
        tmp.clear();
    }

    printf("%d\n", (int)id.size());
    return 0;
}
