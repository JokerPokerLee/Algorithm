#include <bits/stdc++.h>

using namespace std;

multiset<long long> a[1000000];

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	while (n--) {
		string s;
		long long x;
		cin >> s >> x;
		if (s[0] == '?') {
			int k = 0, z = 1;
			while (x) {
				if (x & 1) {
					k += z;
				}
				z <<= 1;
				x /= 10;
			}
			cout << a[k].size() << endl;
		} else {
			int k = 0, z = 1;
			long long y = x;
			while (x) {
				if (x % 10 & 1) {
					k += z;
				}
				z <<= 1;
				x /= 10;
			}
			if (s[0] == '+') {
				a[k].insert(y);
			} else {
				a[k].erase(a[k].find(y));
			}
		}
	}
	return 0;
}