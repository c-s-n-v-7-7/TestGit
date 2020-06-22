#include<bits/stdc++.h>
#define min -100000 
using namespace std ;

vector<int> v ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

unordered_map<pair<int,int>,int> dp ;

int LIS ( int i , int prev = min ) 
{
	if (i==v.size())	return 0 ;
	pair<int,int> p ;
	p.first = i ;
	p.second = prev ;
		if (dp.find(p)==dp.end())
		{
			y = LIS (i+1,prev) ;
			if (v[i]>prev)
				y = max ( 1 + LIS(i+1,v[i]) , y ) ;
		dp.insert(pair<pair<int,int>,int>(p,y)) ;
	}
return dp[p] ;
}

int main()
{
	int  n;
	cin >>  n;

	v = vector<int> (n) ;

	for ( int i=0 ; i<n ; i++ )
			cin >> v[i] ;

	int y = LIS (0) ;
	cout << y << "\n" ;
	return 0 ;
}