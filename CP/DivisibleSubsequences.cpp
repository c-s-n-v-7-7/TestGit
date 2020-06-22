#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

string s ;

vector<unordered_map<ll>> dp ;

ll Divs(int ind , ll pwr , int dd , ll prev )
{
	if ( ind == 0 )
	{
		if(pwr%m==0)  dp[0].insert(pair<ll,ll>(pwr,1)) ;
		else	dp[0].insert(pair<ll,ll>(pwr,0)) ;
	}
	if(ind!=0)
	{
		if(dp[ind].find(pwr)==dp[ind].end())
   		dp[ind].insert(pair<ll,ll>(pwr,Divs(ind-1,pwr,dd,prev)+Divs(ind-1,pwr+(s[i]-48)*10*prev,dd,prev*10))) ;
	}
return(dp[ind][pwr]) ;
}

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t ;
	cin >> t ;
		while(t--)
		{
			string s ;
			cin >> s ;
			dp.clear() ;
			dp = vector<ll> (s.size(),-1) ;
			unordered_map<ll> c ;
			c.insert(pair<ll,ll>(0,1)) ;
			dp[0] = c ;
				int m ;
				cin >> m ;
			cout << Divs(s,s.size()-1,0,m,1) << "\n" ;
		}
	return 0 ;
}