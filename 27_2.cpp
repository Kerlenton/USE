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
	
	freopen("27B (13).txt", "r", stdin);
	
	ll n;
	ll mns = INF;
	ll mxk = 0;
	ll curs = 0;
	ll curk = 0; 
	vector< pair<ll, ll> > maxpref(2077, { -INF, -INF });
	
	cin >> n;
	
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		curs += x;
		curk += 1;
		
		if (mns > curs - maxpref[((curs % 2077) + 2077) % 2077].first)
		{
			mns = curs - maxpref[((curs % 2077) + 2077) % 2077].first;
			mxk = curk - maxpref[((curs % 2077) + 2077) % 2077].second;
		}

		if (mns == curs - maxpref[((curs % 2077) + 2077) % 2077].first)
		{
			if (mxk < curk - maxpref[((curs % 2077) + 2077) % 2077].second)
				mxk = curk - maxpref[((curs % 2077) + 2077) % 2077].second;
		}

		if (maxpref[((curs % 2077) + 2077) % 2077].first < curs)
		{
			maxpref[((curs % 2077) + 2077) % 2077].first = curs;
			maxpref[((curs % 2077) + 2077) % 2077].second = curk;
		}
	}
	
	cout << mns << ' ' << mxk;
	
	return 0;
}

//2904
