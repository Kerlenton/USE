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

    freopen("27-B (4).txt", "r", stdin);
    vector<ll> mxs(4, -INF);
    ll n; cin >> n;
    ll a, b, c; cin >> a >> b >> c;

    mxs[(a + b) % 4] = max(a + b, mxs[(a + b) % 4]);
	mxs[(b + c) % 4] = max(b + c, mxs[(b + c) % 4]);
	mxs[(c + a) % 4] = max(c + a, mxs[(c + a) % 4]);

	for (ll i = 1; i < n; i++)
    {
        ll x, y, z; cin >> x >> y >> z;

        ll s0 = mxs[0];
        ll s1 = mxs[1];
        ll s2 = mxs[2];
        ll s3 = mxs[3];

        if (s0 != -INF)
        {
            ll t = s0 + x + y;
            ll p = s0 + x + z;
            ll q = s0 + y + z;

            mxs[t % 4] = max(t, mxs[t % 4]);
            mxs[p % 4] = max(p, mxs[p % 4]);
            mxs[q % 4] = max(q, mxs[q % 4]);
        }

        if (s1 != -INF)
        {
            ll t = s1 + x + y;
            ll p = s1 + x + z;
            ll q = s1 + y + z;

            mxs[t % 4] = max(t, mxs[t % 4]);
            mxs[p % 4] = max(p, mxs[p % 4]);
            mxs[q % 4] = max(q, mxs[q % 4]);
        }

        if (s2 != -INF)
        {
            ll t = s2 + x + y;
            ll p = s2 + x + z;
            ll q = s2 + y + z;

            mxs[t % 4] = max(t, mxs[t % 4]);
            mxs[p % 4] = max(p, mxs[p % 4]);
            mxs[q % 4] = max(q, mxs[q % 4]);
        }

        if (s3 != -INF)
        {
            ll t = s3 + x + y;
            ll p = s3 + x + z;
            ll q = s3 + y + z;

            mxs[t % 4] = max(t, mxs[t % 4]);
            mxs[p % 4] = max(p, mxs[p % 4]);
            mxs[q % 4] = max(q, mxs[q % 4]);
        }
    }

    cout << mxs[0];

	return 0;
}

//682
