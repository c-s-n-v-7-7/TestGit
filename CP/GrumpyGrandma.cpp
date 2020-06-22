#include<iostream>
#define p 1000000007
using namespace std;

int visited[1001] ;
int a[1001] ;
int n , k , m , b ;
int possiblities[1001][1001] ;
int seq ( int cur , int s )
{
    if ( s > k )   return 0 ;
    if ( possiblities[cur][s] == -1 )
    {
        int var = 0 ;
        if ( a[cur]%m == s%m )  
        {
            var += seq(cur+1,s+1)  ;
        }
        var += seq(cur+1 , s)  ;
    possiblities[cur][s] = var ;
    }    
return possiblities[cur][var] ;
}
int main()
{
    cin >> n >> k >> m ;
    int a[n+1] ;
    for ( int i=1 ; i<=n ; i++ )
    {
        cin >> a[i];
    }
        for ( int i=0 ; i<=n ; i++ )
        visited[i] = 0 ;
       for ( int i=1 ; i<=n-k ; i++ )
       {
           cout << seq( i , 1 ) ;
       } 
    return 0 ;
}