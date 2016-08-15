#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int q;
	scanf("%d%*c", &q);
	multiset<int> a;
	a.insert(0);
	while (q--) {
		char ty;
		int x;
		scanf("%c %d%*c", &ty, &x);
		if (ty == '+') {
			a.insert(x);
		}
		if (ty == '-') {
			a.erase(a.find(x));
		}
		if (ty == '?') {
			int now = 0;
			for (int i = 1 << 30; i; i >>= 1) {
				now ^= (~x & i);
				auto it = a.lower_bound(now);
				if (it == a.end() || *it >= now + i) {
					now ^= i;
				}
				// cout << ((it == a.end()) ? -1 : (*it)) << " " << now << endl;
			}
			printf("%d\n", x ^ now);
		}
	}
	return 0;
}