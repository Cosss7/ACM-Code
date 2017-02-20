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
const int N = 277;
int n;
char s[N];
int a[N];
int mx;
int num;
bool ok(){
    if(a['A' - 'A'] < mx) return false;
    if(a['G' - 'A'] < mx) return false;
    if(a['C' - 'A'] < mx) return false;
    if(a['T' - 'A'] < mx) return false;
    if(num % 4) return false;
    int flag = 0;
    REP(i, 0, n){
        if(s[i] == '?'){
            if(flag == 0) s[i] = 'A', flag ++;
            else if(flag == 1) s[i] = 'G', flag ++;
            else if(flag == 2) s[i] = 'C', flag ++;
            else s[i] = 'T', flag = 0;
        }
    }
    //REP(i, 0, n) if(s[i] == '?') return false;
    return true;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%s", &n, s);
    REP(i, 0, n){
        if(s[i] != '?') a[s[i] - 'A'] ++;
    }
    mx = 0;
    REP(i, 0, N) Max(mx, a[i]);
    REP(i, 0, n){
        if(s[i] == '?'){
            if(a['A' - 'A'] < mx){
                s[i] = 'A';
                a['A' - 'A'] ++;
            }
            else if(a['G' - 'A'] < mx){
                s[i] = 'G';
                a['G' - 'A'] ++;
            }
            else if(a['C' - 'A'] < mx){
                s[i] = 'C';
                a['C' - 'A'] ++;
            }
            else if(a['T' - 'A'] < mx){
                s[i] = 'T';
                a['T' - 'A'] ++;
            }
            else num ++;
        }
    }
    if(ok()){
        printf("%s\n", s);
    }
    else puts("===");
    return 0;
}
