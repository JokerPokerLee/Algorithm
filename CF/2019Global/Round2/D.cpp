#include <bits/stdc++.h>

#define MP make_pair

using namespace std;

typedef long long ll;

inline int getfa(int x, vector<int> &fa) {
	return x == fa[x] ? x : fa[x] = getfa(fa[x], fa);
}

int main() {
	ll x;
	int n;
	scanf("%d", &n);
	vector<int> fa(n);
	vector<ll> s, he(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		s.push_back(x);
		fa[i] = i;
	}
	sort(s.begin(), s.end());

	vector<pair<ll, int>> intv;
	for (int i = 0; i < n - 1; i++) {
		he[i] = s[i];
		intv.push_back(MP(s[i + 1] - s[i], i));
	}
	he[n - 1] = s[n - 1];
	sort(intv.begin(), intv.end());

	int q;
	ll l, r;
	scanf("%d", &q);
	vector<pair<ll, int>> query;
	for (int i = 0; i < q; i++) {
		scanf("%lld %lld", &l, &r);
		query.push_back(MP(r - l, i));
	}
	sort(query.begin(), query.end());

	int cur = 0;
	ll tot = n;
	vector<ll> ans(q);
	for (int i = 0; i < q; i++) {
		ll len = query[i].first;
		while (cur < intv.size() && intv[cur].first <= len) {
			// cout << intv[cur].first << endl;
			int k = intv[cur++].second;
			int f = getfa(k + 1, fa);
			fa[k] = f;
			tot += he[f] - s[k] - 1;
			// cout << k << ", " << f << ": " << he[f] << " " << s[k] << endl;
			// cout << tot << endl;
			he[f] = he[k];
		}
		ans[query[i].second] = tot + len * (n - cur);
		// cout << "ans #" << query[i].second << ": " << ans[query[i].second] << endl;
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << " \n"[i == q - 1];
	}
	return 0;
}