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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("27B (24).txt", "r", stdin);
	
	ll n; cin >> n;
	map<ll, ll> a;
	
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		ll sum = 0;
		
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		
		a[sum] += 1;
	}
	
	cout << max_element(a.begin(), a.end(), comp)->second;
	
	return 0;
}
