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

ll n;
ll b[N], c[N];
ll a[N];
ll sum;
int bit[33];
bool solve(){
    REP(i, 0, n){
        if((2 * n * (b[i] + c[i]) - sum) % (2 * n * n)) return false;
        a[i] = (2 * n * (b[i] + c[i]) - sum) / (2 * n * n);
        REP(j, 0, 33) bit[j] += (a[i] >> j) & 1;
    }
    REP(i, 0, n){
        ll x = a[i], y = a[i];
        REP(j, 0, 33){
            if((a[i] >> j) & 1)
                x += (1ll << j) * (bit[j] - 1),
                y += (1ll << j) * (n - 1);
            else y += (1ll << j) * bit[j];
        }
        //printf("x = %lld, y = %lld\n", x, y);
        if(x != b[i] || y != c[i]) return false;
    }
    return true;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%lld", &n);
    REP(i, 0, n) scanf("%lld", &b[i]);
    REP(i, 0, n) scanf("%lld", &c[i]);
    REP(i, 0, n) sum += b[i] + c[i];
    if(solve()) REP(i, 0, n) printf("%lld\n", a[i]);
    else puts("-1");
    return 0;
}
