#include<iostream>
using namespace std ;

int a[100][100] ;
int path[100][100] ;

int max ( int a , int b )
{
    return (a<b)? b:a ;
}

bool check ( int x , int y , int z , int n )
{
    if ( x < n && y < n ) { if (mod(z-a[x][y] <=1) ) return true ; }
    return false;   
}

int SnakeLength( int x , int y  , int e )
{
    int var=0 ;
    if ( x==e && y == e  ) return 0 ;
    if ( path[x][y] == -1 ) 
    {
         int var1 = 0 ;
        if ( check( x , y+1 , a[x][y+1] , e ) ) var1 = 1+SnakeLength( x,y+1,e ) ;
    int var2 = 0 ;
        if ( check( x+1 , y , a[x+1][y] , e ) ) var2 = 1+SnakeLength( x+1,y,e ) ;
    var = max ( var1 , var2 ) ; 
    path[x][y] = var ;
    }  
return path[x][y] ;
}

int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
        {
            cin >> a[i][j] ;
        }
    }
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
        {
            path[i][j] = -1 ;
        }
    }
    cout << SnakeLength( 0 , 0 , n ) ;
    return 0 ;
}