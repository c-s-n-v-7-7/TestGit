#include<bits/stdc++.h>
#define ll long int 
using namespace std ;

bool move( ll n )
{
	if(n==1)	return	0 ;
	else
	{
		if(n%2!=0)	return 1 ;
		else	return 1 + 
	} 
}

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		ll n ;
		cin >> n ;

		if (move(n)%2==0)	cout << "FastestFinger\n" ;
		else	cout << "Ashishgup\n" ;

	}
	return 0 ;
}