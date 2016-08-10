#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int n;
	cin >> n;
	int a, b;
	a = b = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			a++;
		else
			if (x < y)
				b++;
	}
	if (a > b)
		cout << "Mishka" << endl;
	else
		if (a < b)
			cout << "Chris" << endl;
		else
			cout << "Friendship is magic!^^" << endl;
	return 0;
}