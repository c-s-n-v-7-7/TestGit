#include<iostream>
//#include<set>
#define ll long long int
//#define max 1000000000000000000
using namespace std ;

/*ll min ( ll a , ll b )
{
    return (a<b)? a:b ;
}*/

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
               int n , k ;
               cin >> n >> k ;
                    ll x ;
                    ll a=0 ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> x ;
                    a = (a+x)%k ;
                }
                int i=0 ;
                int j=i+1 ;
                cout << a << "\n" ;

            }
    return 0 ;
}