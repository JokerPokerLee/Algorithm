#include <bits/stdc++.h>

#define MAXN 1010
#define MAXM 600600
#define INF 0x3f3f3f3f
const int maxint=~0U>>1;

#define PII pair<int, int>
#define MP make_pair

using namespace std;

int prop[100];
PII rag[100][100];
int n,pi1,cost=0,ans;
bool v[MAXN * 2];

struct etype
{
    int t,c,u;
    etype *next,*pair;
    etype(){}
    etype(int t_,int c_,int u_,etype* next_):
        t(t_),c(c_),u(u_),next(next_){}
    void* operator new(unsigned,void* p){return p;}
} *e[MAXN * 2];

int aug(int no,int m)
{
    if(no==n)return ans+=m,cost+=pi1*m,m;
    v[no]=true;
    int l=m;
    for(etype *i=e[no];i;i=i->next)
        if(i->u && !i->c && !v[i->t])
        {
            int d=aug(i->t,l<i->u?l:i->u);
            i->u-=d,i->pair->u+=d,l-=d;
            if(!l)return m;
        }
    return m-l;
}

bool modlabel()
{
    int d=maxint;
    for(int i=0;i<=n;++i)if(v[i])
        for(etype *j=e[i];j;j=j->next)
            if(j->u && !v[j->t] && j->c<d)d=j->c;
    if(d==maxint)return false;
    for(int i=0;i<=n;++i)if(v[i])
        for(etype *j=e[i];j;j=j->next)
            j->c-=d,j->pair->c+=d;
    pi1 += d;
    return true;
}

void addedge(etype** Pe, int s, int t, int c, int u) {
	// printf("edge from %d to %d capa %d cost %d\n", s, t, u, c);
    e[s]=new((*Pe)++)etype(t,c,u,e[s]);
    e[t]=new((*Pe)++)etype(s,-c,0,e[t]);
    e[s]->pair=e[t];
    e[t]->pair=e[s];
}

bool cross(PII a, PII b) {
	if (a.first <= b.first && b.first <= a.second) {
		return true;
	}
	if (a.first <= b.second && b.second <= a.second) {
		return true;
	}
	return false;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("B-small-attempt1.in", "r", stdin);
	// freopen("B-small-attempt1.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int p;
		scanf("%d %d", &n, &p);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &prop[i]);
		}
		vector<PII> inter;
		for (int i = 1; i <= n; i++) {
			// map<int, int> mp;
			for (int j = 1; j <= p; j++) {
				int x;
				scanf("%d", &x);
				int lower = (int)ceil(1.0 * x / 1.1 / prop[i]);
				int upper = (int)floor(1.0 * x / 0.9 / prop[i]);
				if (upper < lower) {
					rag[i][j] = MP(-1, -1);
				} else {
					rag[i][j] = MP(lower, upper);
				}
			}
		}
		int tot = n * p * 2 + 2;
		int sta = tot - 1;
		memset(e, 0, sizeof(e));
    	etype *Pe=new etype[MAXM];
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= p; j++) {
				if (rag[i][j].first != -1) {
					int id1 = (i - 1) * p + j;
					addedge(&Pe, id1, id1 + n * p, 0, 1);
					for (int k = 1; k <= p; k++) {
						if (rag[i + 1][k].first != -1) {
							int id2 = i * p + k;
							if (cross(rag[i][j], rag[i + 1][k])) {
								addedge(&Pe, id1 + n * p, id2, 1, 1);
							}
						}
					}	
				}
			}
		}
		for (int i = 1; i <= p; i++) {
			if (rag[1][i].first != -1) {
				addedge(&Pe, sta, i, 0, 1);
			}
			if (rag[n][i].first != -1) {
				addedge(&Pe, (n - 1) * p + i, tot, 0, 1);
			}
		}
		n = tot;
		pi1 = 0, cost = 0, ans = 0;
	    do do memset(v,0,sizeof(v));
	    while(aug(sta,maxint));
	    while(modlabel());
	    cout << ans << endl;
	}
	return 0;
}