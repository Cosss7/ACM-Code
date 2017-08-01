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



string a, b , s;

unordered_map<char, int> id;


int main(){
    ios::sync_with_stdio(false);
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    cin >> a >> b >> s;
    //std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    //std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    //std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    REP(i, 0, a.length()){
        id[a[i]] = i;
    }
    for(auto x : s){
        char c;
        if(x >= 'A' && x <= 'Z'){
            x += 32;
            c = b[id[x]];
            c -= 32;
        }
        else if(x >= 'a' && x <= 'z'){
            c = b[id[x]];
        }
        else{
            c = x;
        }
        cout << c;
    }
    cout << endl;
    return 0;
}
