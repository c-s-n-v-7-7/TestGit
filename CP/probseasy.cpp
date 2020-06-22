#include<iostream>
#include<set>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n , m ;
        cin >> n >> m ;
        int a[n];
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> a[i] ;
        }
        set<int,greater<int>> v ;
        int x ;
        for ( int i=0 ; i<m ; i++ )
        {
            cin >> x ;
            v.insert(x) ;
        }
        int sum = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            for ( auto it=v.begin() ; it!=v.end() ; ++it )
            {
                if ( (a[i]%(*it))== 0 ) { sum += a[i]/(*it) ; break ; }
            }
        }
        cout << sum << "\n" ;
        v.clear() ;
    }
    return 0 ;
}