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
const int N = 55;
string str[N];
int res[N];
int n, k;
int q[N];
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    REP(i, 0, 26) str[i] = char('A' + i);
    REP(i, 26, 52) str[i] = 'A';
    REP(i, 26, 52) str[i] += char('a' + i - 26);
    int idx = 0;
    scanf("%d%d", &n, &k);
    REP(i, 0, n - k + 1){
        string s;
        cin >> s;
        if(s[0] == 'Y'){
            q[i] = 1;
        }
        else{
            q[i] = 0;
        }
    }
    
    if(q[0]) REP(i, 0, k) res[i] = idx ++;
    else{
        q[0] = idx;
        REP(i, 1, k) res[i] = idx ++;
    }
    REP(i, 1, n - k + 1){
        if(q[i]){
            res[i + k - 1] = idx ++;
        }
        else{
            res[i + k - 1] = res[i];
        }
    }
    REP(i, 0, n) cout << str[res[i]] << " ";
    cout << endl;

    return 0;
}
