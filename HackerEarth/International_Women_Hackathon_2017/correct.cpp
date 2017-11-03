#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef string st;
typedef vector<st> vs;
typedef map<int, int> mii;
typedef map<st, int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

const int maxn = 128;
int m1[maxn][maxn], m2[maxn][maxn], a[maxn][maxn];
int v1[maxn], v2[maxn];
pii moves[maxn], best_moves[maxn];
ll bestVal;
int res = 0;
int n, K, sz;
ll finish_time;
int xmove[100000], ymove[100000];

ll getVal() {
	ll res = 0;
	forn(i, n) {
		res += (ll) v1[i] * v2[i];
	}
	return res;
}

inline ll swapVal(int x, int y) {
	ll res = (ll) a[x][y] * (v2[x] - v1[y]);
	if (x == y) res -= (ll) a[x][x] * a[x][x];
	return res;
}

inline void swap(int x, int y) {
	int t = a[x][y];
	v1[x] += t;
	a[x][y] = -t;
	v2[y] -= t;
}

inline void relax(ll val, int k) {
	if (val > bestVal) {
		bestVal = val;
		res = k;
		forn(i, k) {
			best_moves[i] = moves[i];
		}
	}
}

void gready(ll val, int k) {
	relax(val, k);
	if (k == K) return;
	int bi = -1, bj = -1;
	ll bDiff = 0;
	forn(i, n) {
		ll T = v2[i];
		forn(j, n) {
			ll diff = a[i][j] * (T - v1[j]);
			if (i == j) diff -= (ll) a[i][i] * a[i][i];
			if (diff > bDiff) {
				bDiff = diff;
				bi = i;
				bj = j;
			}
		}
	}
	if (bi < 0) return;
	moves[k] = {bi, bj};

	swap(bi, bj);
	gready(val + bDiff, k + 1);
	swap(bi, bj);
}

void randomSearch(ll val, int k) {
	relax(val, k);
	if (k == K) return;
	int t = rand() % sz;
	int x = xmove[t];
	int y = ymove[t];
	moves[k] = pii{x, y};
	ll d = swapVal(x, y);
	swap(x, y);
	if (k%3==0) gready(val + d, k + 1);
	randomSearch(val + d, k + 1);
	swap(x, y);
}

int main() {
	srand(713449);
	//freopen("input.txt", "r", stdin);
	finish_time = clock() + CLOCKS_PER_SEC * 2.95;
	scanf("%d%d", &n, &K);
	forn(i, n) {
		forn(j, n) {
			scanf("%d", &m1[i][j]);
			v1[j] += m1[i][j];
		}
	}
	forn(i, n) {
		forn(j, n) {
			scanf("%d", &m2[i][j]);
			v2[i] += m2[i][j];
		}
	}
	forn(j, n) {
		forn(i, n) {
			a[i][j] = m2[j][i] - m1[j][i];
			if (a[i][j] != 0) {
				xmove[sz] = i;
				ymove[sz] = j;
				sz++;
			}
		}
	}

	if (sz == 0) {
		cout << 0;
		return 0;
	}

	ll initial = getVal();
	gready(initial, 0);
	while (clock() < finish_time) {
		randomSearch(initial, 0);
	}

	cout << res << endl;
	forn(i, res) {
		cout << best_moves[i].second + 1 << " " << best_moves[i].first + 1 << endl;
	}
}
