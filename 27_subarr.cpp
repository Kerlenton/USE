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

    freopen("27_B (1).txt", "r", stdin);
    ll n; cin >> n;

    vector<ll> mxsub(17, -INF);

    ll x; cin >> x;

    mxsub[x % 17] = max(x, mxsub[x % 17]);

    for (ll i = 1; i < n; i++)
    {
        ll a; cin >> a;

        vector<ll> mx(17);
        mx = mxsub;

        for (ll i = 0; i < 17; i++)
        {
            if (mx[i] != -INF)
            {
                ll s = mx[i] + a;

                mxsub[((s % 17) + 17) % 17] = max(s, mxsub[((s % 17) + 17) % 17]);
            }
        }

        mxsub[((a % 17) + 17) % 17] = max(a, mxsub[((a % 17) + 17) % 17]);
    }

    cout << mxsub[0];

	return 0;
}
