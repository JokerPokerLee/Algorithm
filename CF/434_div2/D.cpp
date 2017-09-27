#include <bits/stdc++.h>

#define M1 1052237
#define M2 1121833
#define k1 23
#define k2 41

using namespace std;

typedef pair<int, int> PII;

PII h(char* s, int len) {
	int n1 = 0, n2 = 0;
	for (int i = 0; i < len; i++) {
		// printf("%c", s[i]);
		n1 = (n1 * k1 + s[i] - '0') % M1;
		n2 = (n2 * k2 + s[i] - '0') % M2;
	}
	// printf("\n");
	return make_pair(n1, n2);
}

char *num[70070], *sc[70070];
bool done[70070];

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		num[i] = new char[10];
		scanf("%s", num[i]);
	}
	int rem = n;
	for (int l = 1; rem > 0 && l < 10; l++) {
		map<PII, int> mp;
		for (int i = 0; i < n; i++) {
			for (int p = 0; p + l < 10; p++) {
				PII key = h(num[i] + p, l);
				if (mp.count(key)) {
					if (mp[key] != i) {
						mp[key] = -1;
					}
				} else {
					mp[key] = i;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (done[i]) {
				continue;
			}
			for (int p = 0; p + l < 10; p++) {
				PII key = h(num[i] + p, l);
				if (mp[key] == i) {
					sc[i] = new char[l + 1];
					memcpy(sc[i], num[i] + p, l);
					sc[i][l + 1] = 0;
					done[i] = true;
					rem--;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", sc[i]);
	}
	return 0;
}