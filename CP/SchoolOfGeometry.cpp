#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
using namespace std ;

ll min ( ll a , ll b )
{
    return (a<b)? a:b ;
}

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                int n ;
                cin >> n ;
                //multiset<ll> a , b ;
                ll a[n] , b[n] ;
                ll x , y ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >>a[i]  ;
                   // a.insert(x) ;
                }
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> b[i] ;
                  //  b.insert(y) ;
                }
                ll s=0 ;
                sort(a,a+n) ;
                sort(b,b+n) ;
                for ( auto it=a.begin() , auto j=b.begin() ; it!=a.end() , j!=b.end() ; ++it , ++j  )
                {
                    s+= (min(*i,*j)) ;
                }
                cout << s << "\n" ;
                 a.clear() ;
                 b.clear() ;
            }
    return 0 ;
}