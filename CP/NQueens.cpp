#include<iostream>
using namespace std ;

int mat[101][101] ;

void view ( int n  )
{
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
        {
            cout << mat[i][j] << "\t" ;
        }
        cout << "\n" ;
    }
}

bool isSafe ( int y , int x , int n )
{
    if ( x>=n || y>=n)  return false ;
    for ( int j=0 ; j<n ; j++ )
    {
        if(mat[j][y] || mat[j][j] || mat[x][j])   return false ; 
    }
return true ;
}

void restore( int n )
{
    for ( int i=0 ; i<n ; i++)
    {
        for ( int j=0 ; j<n ; j++ )
        {
            mat[i][j] = 0; 
        }
    }
}

bool possible( int n , int c , int r=0 )
{
    if ( r==n ) return true ;
    for ( int i=0 ; i<n ; i++ )
    {
        if(isSafe(c,r,n)) 
        {
            mat[c][r] = 1;
            if(possible(n,c,r+1)) return true ;
            mat[c][r] = 0 ;
        }
    }
return false ;
}

void Nqueens ( int n )
{
    for ( int i=0 ; i<n ; i++ )
    {
         if ( possible(n,i)) view(n) ;
        restore( n ) ;
    }
}

int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
        {
            mat[i][j] = 0 ;
        }
    }
    Nqueens( n ) ;
    return 0 ;
}