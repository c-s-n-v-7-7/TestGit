#include<iostream>
#include<queue>
using namespace std ;

int a[101] ;

queue<int>greater , smaller ;

int min( int a , int c )
{
    return (a<c)? a:c ;
}
void Swap ( int x , int y )
{
    int temp ;
    temp = a[x] ;
    a[x] = a[y] ;
    a[y] = temp ; 
}

int AArrange( int bn , int n )
{
    if ( bn == n )  return 0 ;
    int swap = 0;
    int temp ;
     if ( a[bn] > a[bn-1] ) { Swap(bn,bn-1) ; swap += 1+AArrange(bn+1,n) ; }   
return swap ;
}

int Darrange( int bn , int n )
{
    if ( bn == n )  return 0 ;
    int swap = 0 ;
    if ( a[bn]>a[bn-1]) swap +=  { Swap(bn,bn-1) ; swap+= 1+Darrange(bn+1,n) ; }
}

int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] ;
    }
    cout << Min ( AArrange(1,n) , Darrange(1,n) ) << "\n" ;

    return 0 ;
}