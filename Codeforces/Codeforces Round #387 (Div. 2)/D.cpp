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
int t[N];
int pre, last;
struct Node{
    int d, x, y;
    Node(){}
    Node(int x, int y):x(x), y(y){d = y - x - 1;}
    bool operator < (const Node &t) const{
        return d < t.d;
    }
}a[N];
int cnt;
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &k);
    REP(i, 0, n){
        scanf("%d", &t[i]);
    }
    pre = last = -1;
    int num = 0;
    REP(i, 0, n){
        if(t[i] < 0){
            num ++;
            last = i;
            if(pre == -1){
                pre = i;
                continue;
            }
            a[cnt ++] = Node(pre, i);
            pre = i;
        }
    }
    k -= num;
    int res = num * 2;
    if(k < 0){
        puts("-1");
        return 0;
    }
    sort(a, a + cnt);
    REP(i, 0, cnt){
        if(a[i].d > k) break;
        k -= a[i].d;
        res -= 2;
    }
    if(last != -1 && n - last - 1 <= k) res --;
    printf("%d\n", res);
    return 0;
}
