#include<bits/stdc++.h>
using namespace std ;

unordered_map<pair<int,int>,bool> dp ;

bool Sum ( int s , vector<int>& a , int i )
{
	if (s<0||i==a.size())	return 0 ;
	if (s==0)	return 1 ;
	else
	{
		pair<int,int> p ;
		p.first = i ;
		p.second = s ;
		if (dp.find(p)==dp.end())
		{
			bool f1 = Sum(s,a,i+1) ;
			bool f2 = Sum(s-a[i],a,i+1) ;
			dp.insert(pair<pair<int,int>,bool>(p,f1||f2)) ;
		}
	return dp[p] ;
	}
}

int main()
{
	int n ;
	cin >> n ;

		vector<int> a ;
		a = vector<int> (n) ;

		//unordered_map<int,int> qnt ;

	for ( int i=0 ; i<n ; i++ )
		{
			cin >> a[i] ;
			//qnt[a[i]]++ ;
		}

	int k ;
	cin >> k ;

		sort(a,a+n,greater<int>) ;

	if (Sum(k,a,0)) cout << "Exists" ;
	else	cout << "D.N.E" ;

	return 0 ;
}