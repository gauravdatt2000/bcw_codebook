#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define REP(i,x) for (int i=0; i<(x); i++)
#define REP1(i,a,b) for (int i=(a); i<=(b); i++)
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#else
#define FILEIO(name)
#endif
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
    return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s<<"[ ";
    for (auto it : c) s << it << " ";
    s<<"]";
    return s;
}
// Let's Fight!

const int MAXN = 202020;

int N;
double arr[MAXN];

double eval(double y)
{
	double ans = 0;
	for(int i=0; i<N; i++)
		ans += sqrt(1 + (arr[i]-i-y) * (arr[i]-i-y));
	return ans;
}

double calc()
{
	double lb = -1E7, rb = 1E7;
	for(int i=0; i<100; i++)
	{
		if(rb - lb < 1E-16) break;

		double m1 = (lb + lb + rb) / 3, m2 = (lb + rb + rb) / 3;
		double v1 = eval(m1), v2 = eval(m2);
		if(v1 > v2)
			lb = m1;
		else
			rb = m2;
	}

	return eval((lb + rb) / 2);
}

int main() {
	IOS;

	cin>>N;
	N *= 2;
	for(int i=0; i<N; i++)
		cin>>arr[i];
	sort(arr, arr+N);

	double ans = calc();
	cout<<fixed<<setprecision(12)<<ans<<endl;

	return 0;
}

