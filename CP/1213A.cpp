#include<bits/stdc++.h>
#define ll long int 
using namespace std ;

int main()
{
	int n ;
	cin >> n ;
	unordered_map<ll,int> m ;
	ll x ;
	while(n--)
	{
		cin >> x ;
		m[x]++ ;
	}
	int odd = 0;
	ll min = -1 ;
	for ( auto it=m.begin() ; it!=m.end() ; ++it )
		{
			for ( auto j=m.begin() ; j!=m.end() ; ++j )
			{
				if((it->first-j->first)%2!=0)	odd+=j->second ;
			}
			if(min==-1||min>odd)	min=odd ;
			odd=0 ; 
		}
		cout << min ;
	return 0 ;
}