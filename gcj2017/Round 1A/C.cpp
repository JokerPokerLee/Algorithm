#include <bits/stdc++.h>

using namespace std;

struct con{
	int Hd, Ad, Hk, Ak, rnd;
	con(int a, int b, int c, int d, int e) : Hd(a), Ad(b), Hk(c), Ak(d), rnd(e) {}
};

inline bool operator<(const con& a, const con& b)
{
	if (a.Hd < b.Hd) return true;
	if (a.Hd > b.Hd) return false;
	if (a.Ad < b.Ad) return true;
	if (a.Ad > b.Ad) return false;
	if (a.Hk < b.Hk) return true;
	if (a.Hk > b.Hk) return false;
	if (a.Ak < b.Ak) return true;
	if (a.Ak > b.Ak) return false;
	return a.rnd < b.rnd;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	freopen("C-small-practice.in", "r", stdin);
	freopen("C-small-practice.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int Hd, Ad, Hk, Ak, B, D;
		scanf("%d %d %d %d %d %d\n", &Hd, &Ad, &Hk, &Ak, &B, &D);
		queue<con> q;
		set<con> s;
		q.push(con(Hd, Ad, Hk, Ak, 0));
		s.insert(con(Hd, Ad, Hk, Ak, 0));
		int ans = -1;
		while (q.size()) {
			con preCon = q.front();
			q.pop();
			// printf("rnd %d: Hd %d Ad %d Hk %d Ak %d\n", preCon.rnd, preCon.Hd, preCon.Ad, preCon.Hk, preCon.Ak);
			// for hash
			con newCon = preCon;
			// Attack
			newCon = preCon;
			newCon.rnd = 0;
			if (preCon.Hk <= preCon.Ad) {
				ans = preCon.rnd + 1;
				break;
			}
			if (preCon.Hd > preCon.Ak) {
				newCon.Hk = preCon.Hk - preCon.Ad;
				if (s.count(newCon) == 0) {
					s.insert(newCon);
					newCon.Hd = preCon.Hd - preCon.Ak;
					newCon.rnd = preCon.rnd + 1;
					q.push(newCon);
				}
			}
			// Buff
			newCon = preCon;
			newCon.rnd = 0;
			if (preCon.Hd > preCon.Ak) {
				newCon.Ad = preCon.Ad + B;
				if (s.count(newCon) == 0) {
					s.insert(newCon);
					newCon.Hd -= preCon.Ak;
					newCon.rnd = preCon.rnd + 1;
					q.push(newCon);
				}
			}
			// Cure
			newCon = preCon;
			newCon.rnd = 0;
			if (Hd > preCon.Ak) {
				newCon.Hd = Hd;
				if (s.count(newCon) == 0) {
					s.insert(newCon);
					newCon.Hd -= preCon.Ak;
					newCon.rnd = preCon.rnd + 1;
					q.push(newCon);
				}
			}
			// Debuff
			newCon = preCon;
			newCon.rnd = 0;
			int tmp = preCon.Ak - D;
			if (tmp < 0) {
				tmp = 0;
			}
			if (preCon.Hd > tmp) {
				newCon.Ak = tmp;
				if (s.count(newCon) == 0) {
					s.insert(newCon);
					newCon.Hd -= tmp;
					newCon.rnd = preCon.rnd + 1;
					q.push(newCon);
				}
			}
		}
		if (ans == -1) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}