#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

string s ;
char look[4] ;

ll total( int ind=0 , int li=0 )
{
	ll count = 0 ;
	if(li==3)	return count ;
	for ( int i=ind ; s[i]!='\0' ; i++ )
	{
		if(s[i] == look[li] )
		{
					count += (total(ind+1,j)+total(ind+1,j+1) ) ;
		}
	}
return count ;
}

int main()
{
	cin >> s ;
	
	look[0] = 'a' ;
	look[1] = 'b' ;
	look[2] = 'c' ;
	
	cout << total(0,0) ;
	return 0 ;
}