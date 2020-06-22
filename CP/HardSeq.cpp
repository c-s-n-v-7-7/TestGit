#include<iostream>
#include<map>
#include<utility>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        map<int,pair<int,int>> M ;
        map<int,pair<int,int>>::iterator it,j  ;
        int a[130] ;
        a[0] = 0 ;
        a[1] = 0 ;
        M.insert(pair(int,(pair<int,int>))(0,(1,2))) ;
        for ( int i=1 ; i<=n ; i++ )
        {
            it = M.find(a[i]) ;
            if ( it!=M.end() )
            {
                j = M.find(i-it->second.first) ;
                if ( j != M.end() )
                j->second.second++ ;
                else
                M.insert( pair<int,pair<int,int>>( (i-it->second.first) , (i,1) ) ) ;
            }  
            else
            {
                M.insert(pair<int,pair<int,int>>( a[i] , (i,1) ) ) ;
            }
        }
        map<pair<int,pair<int,int>> :: iterator j=M.rbegin() ;
        cout << j->second.second<< "\n" ;
    }
    return 0 ;
}