#include<iostream>
#include<map>
#include<utility>
#define intMAX 10005
using namespace std ;

int min ( int a , int b )
{
	return (a<b)? a:b ;
}
int a[intMAX] ;
int visited[intMAX] ;
multimap<int,int> ar ;

int JumpToLast ( int src , int des )
{
	visited[src] = 1 ;
	if ( src < 0 || src > des )	return intMAX ;
	
	int	var = des - src ;
	
	var = min ( var ,1 + JumpToLast ( src-1 , des ) ) ;
	var = min ( var , 1 + JumpToLast( src+1 , des ) ) ;
	
	multimap<int,int>::iterator it ;
	it = ar.find(a[src]) ;
	for ( it->first==a[src] ; ++it )
	{
		if ( !visited[it->second] )	
		var = min ( var , 1+JumpToLast(it->second,des) ) ;
	}
return var ;
} 

int main()
{
	int n ;
	cin >> n;
		
		for ( int i=0 ; i<=n ; i++ )
				visited[i] = 0 ;
		cin >> a[0] ;
		ar.insert(a[0],0) ;
	for ( int i=1 ; i<n ; i++ )
	{
		ar.insert(a[1],i) ;
	}
		cout << JumpToLast( 0, n-1 ) ;
	return 0 ;
}