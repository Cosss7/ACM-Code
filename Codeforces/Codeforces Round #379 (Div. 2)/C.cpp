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
ll n, m, k;
ll x, s;
ll a[N], b[N], c[N], d[N];
struct Node{
    ll x, y;
    Node(){}
    Node(ll x, ll y): x(x), y(y){}
    bool operator < (const Node &t) const{
        return x < t.x;
    }
}e[N];
ll dp[N];
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    scanf("%lld%lld", &x, &s);
    REP(i, 0, m) scanf("%lld", &a[i]);
    REP(i, 0, m) scanf("%lld", &b[i]);
    REP(i, 0, k) scanf("%lld", &c[i]);
    REP(i, 0, k) scanf("%lld", &d[i]);
    a[m] = x, b[m] = 0, m ++;
    c[k] = 0, d[k] = 0, k ++;
    REP(i, 0, m) e[i] = Node(b[i], a[i] * n);
    sort(e, e + m);
    dp[0] = e[0].y;
    REP(i, 1, m) dp[i] = min(dp[i - 1], e[i].y);
    ll res = x * n;
    REP(i, 0, k){
        int p = upper_bound(e, e + m, Node(s - d[i], 0)) - e;
        if(p) Min(res, dp[p - 1] / n * (n - c[i]));
    }
    printf("%lld\n", res);
    return 0;
}
