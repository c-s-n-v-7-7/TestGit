#include<iostream>
#define ll long long int
using namespace std ;

ll reserve ;
ll temp ;

ll min ( ll a  , ll b )
{
	return (a<b)? a:b ;
}

bool inRange ( ll a , ll b  )
{
	if ( temp <= b && temp >= a ) return true ;
	else
	{
		if ( temp < a )
			{
				reserve -= ( a - temp ) ;
				if ( reserve < 0 )	return false ;
				temp = a ;
			}
		if ( b < temp )
			{
				reserve -= ( temp - b ) ;
				if ( reserve < 0 )	return false ;
				temp = b ;
			}
	}	
return true ;
}
int main()
{
		int t ;
		cin >> t ;
			
			while(t--)
			{
			    reserve = 0 ;
               
			    bool flag = 0 ;
				ll n , m ;
					cin >> n >> m ;
					temp = m ;
					ll timee = 0 ; 
				ll tim[n] , low[n] , high[n] ;
				
				for ( int i=0 ; i<n ; i++ )
				{
					cin >> tim[i] >> low[i] >> high[i] ;
					
					if ( i!=0 )
					{
						if ( low[i-1] > high[i] + tim[i] || low[i] > high[i-1] + tim[i] ) flag = 1 ; 
					}
					
					tim[i] -= timee ;
					timee = tim[i] ;
				}
				
				if ( !flag )
				{
						for ( int i=0 ; i<n ; i++ )
								{
									reserve += tim[i] ;
									if ( !inRange(low[i],high[i] ) ) 
										{
											flag = 1 ;
											break ;
										}
								}
				}
				
				if ( flag ) cout << "NO\n" ;
				else	cout << "YES\n" ;
			}
	return 0 ;
}