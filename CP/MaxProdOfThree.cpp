#include<iostream>
#include<algorithm>
#include<utility>
using namespace std ;

int max ( int a , int b) 
{
    return (a>b)? a:b ;
}

int mod (int m )    return (m>0)? m:-m ;

int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    pair<int,int> p[n] ;
    for ( int i=0 ; i<n ; i++ )
        {
          cin >> a[i] ;
          if ( a[i] > 0 )
          {
              p[i] = (pair<int,int>)(p[i],0) ;
          }
          else
          {
              p[i] = (pair<int,int>)(-p[i],1) ;
          }
        }
    sort( p,p+n ) ;
    int max = 0 ;
    int c = 0 ; 
    for ( int i=n-1 ; i>=0 ; i-- )
    {
        c = p[i].first*p[i].second*p[i-1].first*p[i-1].second*p[i-2].first*p[i-2].second ;
        if ( c > max )  {   max = c ; cout << max << "\n" ; break ;}
     }  
    return 0 ;
}