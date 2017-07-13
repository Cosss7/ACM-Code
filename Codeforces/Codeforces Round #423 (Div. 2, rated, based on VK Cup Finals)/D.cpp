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


int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &k);
    int ans = 0;
    if((n - k - 1) % k >= 2){
        ans = ((n - k - 1) / k + 1) * 2;
    }
    else if((n - k - 1) % k == 1){
        ans = ((n - k - 1) / k + 1) + ((n - k - 1) / k);
    }
    else{
        ans = ((n - k - 1) / k) * 2;
    }
    printf("%d\n", ans + 2);
    ///*
    REP(i, 0, k){
        for(int j = i + k; j < n - 1; j += k){
            printf("%d %d\n", j - k + 1, j + 1);
        }
    }
    REP(i, 0, k){
        printf("%d %d\n", i + 1, n);
    }
    //*/
    return 0;
}
