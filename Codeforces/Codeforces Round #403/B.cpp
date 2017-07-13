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
const int N = 6e4 + 7;

int n;
struct Node{
    ll x, v;
    Node(){}


}a[N];
bool ok(double m){
    double L = -1e18, R = 1e18;
    REP(i, 0, n){
        double dis = a[i].v * m;
        double l = a[i].x - dis;
        double r = a[i].x + dis;
        Min(R, r);
        Max(L, l);
    }
    if(L <= R) return true;
    return false;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%lld", &a[i].x);
    }
    REP(i, 0, n){
        scanf("%lld", &a[i].v);
    }
    double l = 0, r = 1e18 + 7;
    REP(i, 0, 200){
        double m = (l + r) / 2;
        if(ok(m)) r = m;
        else l = m;
    }
    printf("%.12lf\n", r);
    return 0;
}
