#include<iostream>
#include<utility>
#define int_MAX 100005
using namespace std ;

int fe ;
pair<int,int> arr1[int_MAX] , arr2[int_MAX] ;
int n ;

int min ( int a , int b , int c=0 )
{
    if ( a>=b && a>=c )   return a ;
    if ( b>=a && b>=c )   return b ;
    if ( c>=a && c>=b )   return c ; 
}

int firstEqual ( int p1 , int p2 )
{
	int var = -2*n ;
		if ( p1 < 0 || p2 > n )	return -2*n ;
	if ( arr1[p1].first + arr2[p2].first == arr1[p1].second + arr2[p2].second )	var = (n+p2-p1) ;
	    //cout << var << " ";
		var = min ( var , firstEqual(p1-1,p2) , firstEqual(p1,p2+1) ) ;
return var ;
}

int main()
{
	int  t ;
	cin >> t ;
		while(t--)
		{
				cin >> n ;
				int a[2*n] ;
				for ( int i=0 ; i<2*n ; i++ )
					cin >>a[i] ;
					pair<int,int> p ;
					pair<int,int> arr1[n+1] , arr2[n+1] ;
					arr1[0] = pair<int,int>(0,0);
					arr2[n] = pair<int,int>(0,0);
			
				for ( int i=1 ; i<=n ; i++ )
				{
						if ( a[i-1] == 1 )	{ arr1[i].first = arr1[i-1].first+1 ; arr1[i].second = arr1[i-1].second ;}	
						if ( a[i-1] == 2 )	{ arr1[i].second = arr1[i-1].second+1 ; arr1[i].first = arr1[i-1].first ;}	
					
					if ( a[2*n-i] == 1 )	{ arr2[n-i].first = arr2[n-i+1].first+1 ; arr2[n-i].second = arr2[n-i+1].second ; }
					if ( a[2*n-i] == 2 )	{ arr2[n-i].second = arr2[n-i+1].second+1 ; arr2[n-i].first = arr2[n-i+1].first ; }
				
				   //cout << arr1[i].first << " "  << arr1[i].second << " " << arr2[n-i].first << " "<< arr2[n-i].second << "\n" ;
				    
				}

				int fe = firstEqual( n,0 ) ;
				cout << fe << "\n" ; 
		}
	return 0 ;
}