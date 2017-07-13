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

int n;
int mx[N << 2];
struct Node{
    int a, b, h;
    Node(){}
    Node(int a, int b, int c): a(a), b(b), h(c){}
    bool operator < (const Node& t) const{
        return (a < t.a) || (a == t.a && b < t.b);
    }
}a[N];
void pushUp(int rt){
    int lch = rt << 1, rch = rt << 1 | 1;
    if(a[mx[lch]].b < a[mx[rch]].b){
        mx[rt] = mx[lch];
    }
    else{
        mx[rt] = mx[rch];
    }
}
void build(int rt, int L, int R){
    if(L + 1 == R){
        mx[rt] = L;
        return ;
    }
    int m = (L + R) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}
int query(int rt, int L, int R, int l, int r){
    if(l <= L && r >= R){
        return mx[rt];
    }
    int m = (L + R) >> 1;
    int pos = n + 1;
    int t = n + 1;
    if(l < m){
        t = query(lson, l, r);
        if(a[t].b <= a[pos].b) pos = t;
    }
    if(r > m){
        t = query(rson, l, r);
        if(a[t].b <= a[pos].b) pos = t;
    }
    return pos;
}
ll dp[N];

bool ok(int x, int m){
    int pos = query(1, 0, n, x + 1, m + 1);
    if(pos == n + 1) return false;
    if(a[pos].b >= a[x].a) return false;
    return true;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d%d%d", &a[i].b, &a[i].a, &a[i].h);
    }
    sort(a, a + n);
    build(1, 0, n);
    a[n + 1].b = 1e9 + 7;
    ll res = 0;
    for(int i = 0; i < n; i ++){
        //printf("i = %d\n", i);
        Max(dp[i], (ll)a[i].h);
        Max(res, dp[i]);
        if(i == n - 1) break;
        int l = i + 1, r = n - 1;
        while(r > l){
            int m = (l + r) >> 1;
            if(ok(i, m)) r = m;
            else l = m + 1;
        }
        if(!ok(i, r)) break;
        Max(dp[r], dp[i] + a[r].h);
    }
    printf("%lld\n", res);
    return 0;
}
