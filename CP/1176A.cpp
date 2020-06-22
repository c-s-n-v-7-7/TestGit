#include<bits/stdc++.h>
#define ll long long int
using namepsace std ;

ll s ;

ll min ( ll a , ll b ){
	return (a<b)? a:b ;
} 

void Div ( ll n , ll st = 0 ){
	if ( n==1 ){
		if ( s==-1 )	s = st ;
		else	s = min ( st , s ) ;
	return ;
	}
	if (n%2==0)	{
		Div(n/2,st+1) ; 
	} 
	if (n%3==0) {
		Div((2*n)/3,st+1) ;
	}
	if (n%5==0) {
		Div((4*n)/5,st+1) ;
	}
return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t ;
	cin >> t ;
	while(t--)
	{
		s = -1 ;
		ll n ;
		cin >> n ;
		Div(n) ;
	}
	return 0 ;
}