#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "w", stdout);
	srand(time(0));
	int r = 10, c = 10;
	cout << 1 << endl;
	cout << r << " " << c << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (rand() % 200 < 10) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << endl;
	}
	return 0;
}