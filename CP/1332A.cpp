#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int  t ;
	cin >> t ;
		while(t--){
			long int a , b , c , d ;
			cin >> a >> b >> c >> d ;
			long int x , y , x1 , x2 , y1 , y2 ;
			cin >> x >> y >> x1 >> y1 >> x2 >> y2 ;
			if (( x >= x2 || x <= x1 || y <=y1 || y>=y2 )||(x==x1&&x==x2)||(y==y1&&y==y2))	cout << "NO\n" ;
			else	cout << "YES\n" ;	
		}
	return 0 ;
}