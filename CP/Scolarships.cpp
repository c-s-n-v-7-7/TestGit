#include<iostream>
#define ll long long int 
#include<set>
using namespace std ;

int main()
{
ll t ;
cin >> t ;
while(t--)
{
   set<ll> taken ;
    ll n , var , x , y , r ;
    cin >> n >> r >> x >> y ;
   for ( ll i=0 ; i<x;  i++ )
   {
       cin >> var ;
     taken.insert(var);
   }
   for ( ll j=0 ; j<y ; j++ )
   {
       cin >> var ;
       taken.insert(var) ;
   }
   if ( n -taken.size() <= r ) cout << n-taken.size();
   else cout << r ;
   cout << "\n" ; 
   taken.clear() ;
}
    return 0 ;
}