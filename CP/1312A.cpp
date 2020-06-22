#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			int m , n ;
			cin >> n >> m ;
			float f1 , f2 ;
			f1 = (float)(360)/(float)(n) ;
			f2 = (float)(360)/(float)(m) ;
				if ((f1/f2)-(int)(f1/f2)==0)	cout << "YES\n" ;
				else	cout << "NO\n" ;
		}
	return 0 ;
}