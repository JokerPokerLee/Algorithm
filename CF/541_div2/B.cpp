#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	int pa = 0, pb = 0;
	int ans = 0, a, b;
	while (n--) {
		scanf("%d %d", &a, &b);
		ans += max(min(a, b) - max(pa, pb) + 1, 0);
		pa = a, pb = b;
		if (a <= b) pa++;
		if (b <= a) pb++;
	}
	cout << ans << endl;
	return 0;
}