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
//#include <tuple>
//#include <random>
//#include <time.h>
//#include <climits>
//#include <bitset>

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
	cin.tie(0);

    freopen("27-B.txt", "r", stdin);
	vector<ll> s(3, -INF);

	ll n; cin >> n;
    ll g, q; cin >> g >> q;

    s[g % 3] = max(g, s[g % 3]);
    s[q % 3] = max(q, s[q % 3]);

	for (ll i = 1; i < n; i++)
	{
		ll x, y; cin >> x >> y;
        ll a, b;

        ll s0 = s[0];
        ll s1 = s[1];
        ll s2 = s[2];

		if (s[0] != INF)
        {
            a = s0 + x;
            b = s0 + y;

            s[a % 3] = max(s[a % 3], a);
            s[b % 3] = max(s[b % 3], b);
        }

        if (s[1] != INF)
        {
            a = s1 + x;
            b = s1 + y;

            s[a % 3] = max(s[a % 3], a);
            s[b % 3] = max(s[b % 3], b);
        }

        if (s[2] != INF)
        {
            a = s2 + x;
            b = s2 + y;

            s[a % 3] = max(s[a % 3], a);
            s[b % 3] = max(s[b % 3], b);
        }
	}

	cout << max(s[1], s[2]);
	return 0;
}
