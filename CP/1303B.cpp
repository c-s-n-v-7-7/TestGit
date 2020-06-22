#include<iostream>
#define ll long long int
using namespace std ;

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t ;
        while(t--)
        {
            ll n , g , b ;
            cin >> n >> g >> b ;
            ll d=0 ;
            ll spells ;
            if ( g >= n/2 )    {cout << n << "\n" ; continue ;}
            if ( n%2==0 )
            {
                if ( (n/2)%g == 0 ) spells = (n/2)/g ;
                else    spells = ((n)/2)/g + 1;
            }
            else
            {
                if ( ((n+1)%g)==0) spells =((n+1)/2)/g ;
                else    spells = ((n+1)/2)/g + 1 ;
            }
            cout << (g+b)*spells - n%(g+b) << "\n" ;
        }
    return 0 ;
}