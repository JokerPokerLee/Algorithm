#include <bits/stdc++.h>

#define MAX 1100000000000

using namespace std;

typedef long long ll;

ll pow(int x, int y) {
	int oy = y;
	ll r = 1, tr = x;
	while (y) {
		if (y & 1) {
			r *= tr;
		}
		tr *= tr;
		y >>= 1;
	}
	return r;
}

bool check(vector<int>& v, int l) {
	int i, j;
	for (i = (l - 1) / 2, j = l / 2; j < v.size() && v[i] == v[j]; i--, j++);
	return j == v.size();
}

int solve(int l, int n, ll k) {
	vector<int> pre;
	ll accu = 0;
	for (int i = 1; accu < k && i <= n; i++) {
		for (int c = 0; c < l; c++) {
			ll tmp = accu;
			pre.push_back(c);
			for (int j = i; tmp < k && j <= n; j++) {
				if (j > i * 2) {
					tmp += pow(l, (j - i * 2 + 1) / 2);
				} else {
					tmp += check(pre, j);
				}
			}
			if (tmp >= k) break;
			accu = tmp;
			pre.pop_back();
		}
		if (pre.size() < i) {
			return 0;
		}
		accu += check(pre, pre.size());
	}
	return pre.size();
}

int main() {
	// freopen("C-small-practice.in", "r", stdin);
	// freopen("C-small-practice2.out", "w", stdout);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice2.out", "w", stdout);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int l;
		ll n, k;
		cin >> l >> n >> k;
		if (k <= n) {
			cout << k << endl;
			continue;
		}
		ll append = max(n - 200 - (n & 1), 0LL);
		k -= append, n -= append;
		int res = solve(l, n, k);
		cout << (res ? append + res : 0) << endl;
	}
	return 0;
}