#include <bits/stdc++.h>

using namespace std;

bool mark[100100];

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	long long tot = 0;
	vector<long long> v, cap;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		tot += x;
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		cap.push_back(x - 1);
	}
	long long ans = v[0] * v[n - 1];
	for (int i = 0; i < n - 1; i++) {
		ans += v[i] * v[i + 1];
	}
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		int c = cap[i];
		long long tmp = sum + v[c] + v[(c + 1) % n] + v[(c + n - 1) % n];
		if (mark[(c + 1) % n])
			tmp -= v[(c + 1) % n];
		if (mark[(c + n - 1) % n])
			tmp -= v[(c + n - 1) % n];
		ans += v[c] * (tot - tmp);
		sum += v[c];
		mark[c] = true;
	}
	cout << ans << endl;
	return 0;
}