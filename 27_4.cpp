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
	
	freopen("27_B (2).txt", "r", stdin);
	
	ll n;
	ll c = 0;
	ll curs = 0;
	
	cin >> n;
	vector< vector<ll> > dp(n + 1, vector<ll>(117, 0));
	
	dp[0][0] = 1;
	
	for (ll i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		curs += x;
		
		if (i - 5 >= 0)
			c += dp[i-5][curs % 117];
		
		dp[i][curs % 117] += 1;
		
		for (ll j = 0; j < 117; j++)
		{
			dp[i][j] += dp[i - 1][j];
		}
	}
	
	cout << c << endl;
	
	return 0;
}

//2363
