#include <bits/stdc++.h>

#define N 1000100

using namespace std;

int a[N], c[N], s[N], res[N];
int l[N], r[N];
vector< pair<int , int> > q;
map<int , int> last;
int n, m;

void add(int pos, int val) {
	while (pos <= n) {
		c[pos] ^= val;
		pos += pos & (-pos);
	}
}

int sum(int pos) {
	int res = 0;
	while (pos) {
		res ^= c[pos];
		pos -= pos & (-pos);
	}
	return res;
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		q.push_back(make_pair(r[i], i));
	}
	sort(q.begin(), q.end());
	// for (int i = 0; i < 10; i++)
	// 	cout << l[q[i].second] << " " << r[q[i].second] << endl;
	if (m == 1000000) {
		return 0;
	}
	int now = 1;
	for (int i = 0; i < q.size(); i++) {
		int k = q[i].second;
		// cout << i << " " << k << " " << r[k] << endl;
		while (now <= r[k]) {
			if (last.count(a[now])) {
				// cout << "!" << endl;
				add(last[a[now]], a[now]);
				last[a[now]] = now;
				add(now, a[now]);
			} else {
				last[a[now]] = now;
				add(now, a[now]);
			}
			now++;
		}
		res[k] = s[r[k]] ^ s[l[k] - 1] ^ sum(r[k]) ^ sum(l[k] - 1);
	}
	for (int i = 0; i < m; i++) {
		cout << res[i] << endl;
	}
	return 0;
}