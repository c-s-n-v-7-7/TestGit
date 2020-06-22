//Incomplete
#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int n ;
	cin >> n ;
	string s ;
	cin >> s ;
	string a[2];
	bool f=0 ;
	for ( int i=0 ; i<n ; i++ )
	{
		if (s[i]=='1')	
		{
			a[f][i] = '1' ;
			a[!f][i] = '0' ;
		}
		if (s[i]=='2')
		{
			a[f][i]='1' ;
			a[!f][i] ='0' ;
		}
		if (s[i]=='3')
		{
			if (i<n-2&&s[i+1]=='2'&&s[i+2]=='1')
			{
				a[f][i] = '1' ;
				a[!f][i] = '0' ;
				f=!f ;
				a[f][i+1] = '2' ;
				a[!f][i+1] = '2' ;
				f=!f ;
				a[f][i+2] = '2' ;
				a[!f][i+2] = '2' ; 
			}
			if (i<n-1&&s[i+1]=='1')
			{
				a[f][i] = '1' ;
				a[!f][i] = '1' ; 
			}
		}
	}

	return 0 ;
}