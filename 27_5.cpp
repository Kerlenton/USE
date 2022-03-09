#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <utility>
#include <cstring>
#include <queue>
#include <tuple>
#include <random>
#include <time.h>
#include <climits>
#include <bitset>

#define ll long long

using namespace std;
 
const ll MOD = 998244353;
const ll INF = 1000000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("27A (15).txt", "r", stdin);
	
	ll n;
	ll c = 0;
	ll curs = 0;
	ll curk = 0;
	ll mx = 0;
	
	cin >> n;
	vector< vector<ll> > minpref(n + 1, vector<ll>(7, INF));
	
	minpref[0][0] = 0;
	
	
	for (ll i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		curs += x;
		
		if (x % 7 == 0 && x > 0)
			curk += 1;
		
		if (i >= 7)
			mx = max(mx, curs - minpref[i - 7][curk % 7]);
		
		for (ll j = 0; j < 7; j++)
			minpref[i][j] = minpref[i-1][j];
		
		minpref[i][curk % 7] = min(minpref[i][curk % 7], curs);
	}
	
	cout << mx;
	
	return 0;
}
//2908
