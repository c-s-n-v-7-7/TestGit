#include<bits/stdc++.h>
#include<algorithm>
#define intMAX 100005
#define dim 1000000001
using namespace std ;

int taken[intMAX][dim] ;

int Goods ( int start , int tot , long int a[] , long int p )
{
    if ( a[start] > p ) return 0 ;
    else 
    {
        if ( a[start+1] > p )
        {
            return max ( 1+Goods(start+1,tot,a,p-a[start]) , 2 + Goods(start+2,tot,a,p-a[start+1] ) ) ;
        }
        else    return 1+Goods(start+1,tot,a,p-a[start]) ;
    }
}

int main()
{
    int t ;
    cin >> t ;
        while(t--)
            {
                long int n , p , k ;
                 cin >> n >> p >> k ;
                    long int a[n] ;
                    for ( int i=0 ; i<n ; i++ )
                    {
                            cin >> a[i] ;
                    }
                //Here k=2 ;
                    sort ( a , a+ n ) ;
                    /*for ( long int i=p ; i>=0 ; i++ )
                    {
                        for ( int j=0 ; j<n ; j++ )
                        {
                            if ( a[j] > i ) taken[i][j] = 0 ;
                            else    taken[i][j] = -1 ;
                        }
                    } */
                cout << Goods ( 0 , n , a , p ) << "\n" ;
            }
    return 0 ; 
}