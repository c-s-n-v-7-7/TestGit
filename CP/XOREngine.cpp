#include<iostream>
using namespace std ;

bool parity(long int n)
{
    bool p=0 ;
    while(n!=0)
    {
        if(n%2==1)p=!p;
        n/=2;
    }
return p ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t ;
    while(t--)
    {
        long int n , q ;
        cin >> n >> q;
        long int x ;
        int odd = 0 ;
        int even = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> x ;
            if(parity(x))odd++ ;
            else    even++ ;
        }
        int p ;
        while(q--)
        {
            cin >> p ;
            if(parity(p))
            {
                cout << odd << " " << even << "\n" ;
            }
            else
            {
                cout << even << " " << odd << "\n" ;
            }
        }
    }
    return 0 ;
}