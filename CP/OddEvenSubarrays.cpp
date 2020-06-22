#include<iostream>
using namespace std ;

int a[101];
int odev[101][101] ;
//DP is done for storing 
int Possiblities( int start , int end , int odd , int even )
{
    int var = 0 ;
    if ( a[start] == 0 )    even++ ;
    else    odd++ ;
    if ( odd == even )  var ++ ;
    var += Possiblities(start+1,end,odd,even) ;
    int o = 0 , e = 0 ;
    for ( int j=0 ; j<start ; j++ )
    {
        if ( a[j] == 0 )    e++ ;
        else    o++ ;
        var += Possiblities( start+1 , end , odd-o , even-e ) ;
    }
return var ;
}

int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n ; i++ )
    cin >> a[i] ;
    return 0 ;
}   