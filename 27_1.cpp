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
	
	//freopen("27B (12).txt", "r", stdin);
	ll n;
	ll mxs = 0;
	ll mxk = 0;
	ll curs = 0;
	ll curk = 0;
	vector< pair<ll, ll> > minpref(69, { INF, INF });
	
	minpref[0] = { 0, 0 };
	
	cin >> n;
	
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		curs += x;
		curk += 1;
		
		if (curs % 69 == 0)
		{
			mxs = curs;
			mxk = curk;
		}
		
		else
		{
			if (mxs == curs - minpref[curs % 69].first)
			{
				if (mxk > curk - minpref[curs % 69].second)
					mxk = curk - minpref[curs % 69].second;
			}
			
			if (mxs < curs - minpref[curs % 69].first)
			{
				mxs = curs - minpref[curs % 69].first;
				mxk = curk - minpref[curs % 69].second;
			}
		
			//mx = max(mx, curs - minpref[curs % 69]);
		}
		
		if (minpref[curs % 69].first > curs)
		{
			minpref[curs % 69].first = curs;
			minpref[curs % 69].second = curk;
		}
	}
	
	cout << mxs << ' ' << mxk;
	
	return 0;
}
