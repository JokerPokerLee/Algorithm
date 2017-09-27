#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	int ori = n;
	int f = 0, t = 0;
	while (n % 5 == 0) {
		f++;
		n /= 5;
	}
	while (n % 2 == 0) {
		t++;
		n /= 2;
	}
	long long ans = ori;
	long long d = 1;
	while (k) {
		d *= 10;
		k--;
	}
	while (ans % d) {
		if (f < t) {
			ans *= 5;
			f++;
		} else
		if (t < f) {
			ans *= 2;
			t++;
		} else {
			ans *= 10;
		}
	}
	cout << ans << endl;
	return 0;
}