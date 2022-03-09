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
	
	freopen("27B (14).txt", "r", stdin);
	
	ll n;
	ll curs = 0;
	ll curk = 0;
	ll mx = 0;
	
	vector<ll> minpref(30, INF);
	
	minpref[0] = 0;
	
	cin >> n;
	
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		curs += x;
		
		if (x > 0 && x % 2 == 0)
			curk += 1;
		
		mx = max(mx, curs - minpref[curk % 30]);
		minpref[curk % 30] = min(minpref[curk % 30], curs);
	}
	
	cout << mx;
	
	return 0;
  
  //2907
}
