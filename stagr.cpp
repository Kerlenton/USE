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

/*bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
	return a.second < b.second;
}*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("27-A__kglf__ki6w.txt", "r", stdin);
	ll n; cin >> n;
	
	queue<ll> q;
	ll curs = 0;
	
	for (ll i = 0; i < 100; i++)
	{
		ll x; cin >> x;
		curs += x;
		
		q.push(curs);
	}

	ll ans = 0;
	vector<ll> k(999, 0);
	
	for (ll i = 100; i < n; i++)
	{
		ll x; cin >> x;
		curs += x;
		
		if (curs % 999 == 0)
			ans += 1;
		
		ans += k[curs % 999];
		k[(q.front()) % 999] += 1;
		q.push(curs);
		q.pop();
	}
	
	cout << ans;
	return 0;
}
