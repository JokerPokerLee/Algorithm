#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int l = 0, r = 0;
	while (l < s.size()) {
		while (r < s.size() && s[l] == s[r]) {
			r++;
		}
		if (r - l > k) {
			cout << "NO" << endl;
			return 0;
		}
		l = r;
	}
	cout << "YES" << endl;
	return 0;
}