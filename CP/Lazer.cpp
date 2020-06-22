#include<bits/stdc++.h>
#define ll long int 
using namespace std ;

ll min ( ll a , ll b )
{
    return (a<b)? a:b ;
}

ll max( ll a , ll b )
{
    return (a>b)? a:b ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t ;
	cin >> t ;
		while(t--)
		{
			ll n , q ;
			cin >> n >> q ;
				vector<ll> v ;
				v = vector<ll> (n) ;
				ll c ;
				for ( ll i=0 ; i<n ; i++ )
				{
				    cin >> v[i] ;
				}
			while(q--)
			{
				ll x1 , x2 , y ;
				ll count = 0 ;
				cin >> x1 >> x2 >> y ;
			       
			       for ( int i=x1-1 ; i<min(x2-1,n-1) ; i++ )
			       {
			           if( (v[i]-y)*(v[i+1]-y)<=0 ) 
			           {
			               count++ ;
			             //  cout << i << " " ;
			           }
			       }
			       //if(v[x1-1]==y&&v[x1]!=y) count-- ;
			       //if(v[x2-1]==y&&v[x2-2]!=y)count-- ;   
				cout << count << "\n" ;
			}
		}
	return 0 ;
}