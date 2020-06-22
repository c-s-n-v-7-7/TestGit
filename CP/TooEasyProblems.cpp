#include<bits/stdc++.h>
#include<algorithm>
#define ll long int 
using namespace std ;

class prob{
	public :
	pair<int,int> p ;
	bool operator < ( const prob& x )
	{
		if ( p.first < x.p.first )	return 1 ;
		
		if ( p.first == x.p.first )
		{
			if(p.second < x.p.second)	return 1 ;
		}	
		
		return 0 ;
	}
} ;

int main()
{
	ll t ;
	cin >> t ;
		while(t--)
		{
			int n ;
			cin >> n ;
			//	prob x[n] ;
			pair<prob,int> x[n] ;
			for ( int i=0 ; i<n ;  i++ )
			{
				cin >> x[i].first.p.first >> x[i].first.p.second ;
 				x[i].second = i+1 ;
 			}
 			sort(x,x+n) ;
 			vector<int> scorer ;
 			int count = 0 ;
 		  for ( int i=0 ; i<n ; i++ )
 		  {
 		 	if (x[i].first.p.first<=(i+1))
 		 	{	
 		 		scorer.push_back(x[i].second) ;
 		 		count = i+1 ; 
 		 	}
 		  }
 		  	cout << count << "\n" << scorer.size() << "\n" ;
 		  	for ( int i : scorer )
 		  		cout << i << " " ;
 		  	cout << "\n" ;
		}
	return 0 ;
}