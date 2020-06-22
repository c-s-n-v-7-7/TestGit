#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
#include<utility>
using namespace std ;

/*int mod ( int m )
{
    return (m<0)? -m:m ;
}

int min ( int a , int b )
{
    return (a<b)? a:b ;
}

unordered_map<int,int> lookup[151] ;
unordered_set<int,int>::iterator it1 , it2 ;
int minimize( int i , int a[][2] , int n , int left=0 , int right=0 )
{
    if ( i == n )   return 0;
    int var1 = mod(left+a[i][0] - right - a[i][1]) ;
    it1 = lookup[i].find(var1) ;
    if ( it1 == lookup[i].end() )  
    lookup[i].insert(pair<int,int>( var1, var1 + minimize( i+1 , a , left+a[i][0] , right+a[i][1] ) ) ) ;
    int var2 = mod(left+a[i][1] - right - a[i][0]) ;
    
    var2 += minimize( i+1 , a , left+a[i][1] , right+a[i][0] ) ;
    it1 = lookup[i].find(var2) ;
    if ( it1 == lookup[i].end() )  
    lookup[i].insert(pair<int,int>( var1, var1 + minimize( i+1 , a , left+a[i][0] , right+a[i][1] ) ) ) ;
    int var2 = mod(left+a[i][1] - right - a[i][0]) ;
    int var = min ( var1 , var2 )   ;
    
    return var ;
}

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                int n ;
                int a[n][2] ;
                string s ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> s ;
                    int c1=0 , c2=0 ;
                     
                    for ( int i=0 ; i<n/2 ; i++ )
                        if ( s[i] == '1' )  c1++ ;
                    for ( int i=n/2+n%2 ; i<n ; i++ )
                        if ( s[i] == '1' )  c2++ ;
                    a[i][0] = c1 ;
                    a[i][1] = c2 ;
                    diff1+=c1 ;
                    diff2+=c2 ;
                }
                cout << minimize( 0 , a , n ) ; 
            }
    return 0 ;
}*/
int main()
{
    int t ;
    cin >> t ;
        while(t--)
        {
            cin >> n ;
                char s[n+1] ;
                    int a[n] ;
                    int sum = 0 ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> s ;
                        int l=0 ;
                    for ( int j=0 ; i<n/2 ; i++ )
                    {
                        if ( s[j] == '1' )  l++ ;
                    }
                    for ( int j=n/2+n%2 ; i<n ; i++ )
                    {
                        if ( s[j] == '1' )  l-- ;
                    }
                    a[i] = l ;
                    sum += l;
                }
                sort(a,a+n) ;
                if ( sum == 0 ) cout << "0\n" ;
                else
                        {
                            
                        }
        }
    return 0 ;
}