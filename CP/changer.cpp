#include<iostream>
using namespace std ;

int main()
{
    int n ;
    char c[n+1] ;
    cin >> c ;
    int j++ ;
    set<pair<int,int>> change ;
    for ( int i=1 ; i<=n ; i++ )
    {
        j++ ;
        if ( c[i] != c[i-1] ) change.insert(pair<int,int>(i,j)) ;
    }
    int flag = 0 ;
    set<pair<int,int>>::iterator j = change.begin() ;
    for ( auto it=change.begin();it!=change.end();++it)
    {
        ++ j ;
        if ( it->second%2 != j->second%2 ){   flag = 1 ; break ; }
    }
    int parity ;
    change.beign()->second%2 = parity ;
    if ( change.size() == 1 )   cout << "0\n" ; 
    if ( flag ) cout << "-1\n" ;
    else
    {
        int p = 0 ;
        for ( auto it=change.begin() ; it!=change.end() ; ++it )
        {
                if ( parity%2 == 0 )    p += it->second/2 ; 
        }
    }
    return 0 ;
}