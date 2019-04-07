#include <bits/stdc++.h>

#define MP make_pair
#define MOD 1000000007

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

map<ll, ll> pr;

ll pow(ll x) {
	if (pr.count(x)) {
		return pr[x];
	}
	ll y = MOD - 2;
	ll res = 1, t = x;
	while (y) {
		if (y & 1) {
			res = (res * t) % MOD;
		}
		t = (t * t) % MOD;
		y >>= 1;
	}
	pr[x] = res;
	return res;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("C-small-attempt0.in", "r", stdin);
	// freopen("C-small-attempt0.out", "w", stdout);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		pr.clear();
		ll n, m;
		cin >> n >> m;
		ll s = 2 * n + 1, tot = 1;
		for (int i = 1; i <= 2 * n; i++) {
			s = s * i % MOD;
			tot = tot * i % MOD;
		}
		ll ans = 0, c = 1, two = 1;
		for (int i = 0; i <= m; i++) {
			if (i) {
				c = c * (m - i + 1) % MOD;
				c = c * pow(i) % MOD;
			}
			s = s * pow(2 * n - i + 1) % MOD;
			// cout << i << ": " << c << " " << s << " " << two << endl;
			ll tmp = c * s % MOD;
			tmp = tmp * two % MOD;
			if (i & 1) {
				ans = (ans + MOD - tmp) % MOD;
			} else {
				ans = (ans + tmp) % MOD;
			}
			two = two * 2 % MOD;
			// cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}