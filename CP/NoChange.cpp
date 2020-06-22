#include<iostream>
#include<vector>
#define ll long long int
using namespace std ;
vector<ll> deno ;

int main()
{
        int t ;
        cin >> t ;
        while(t--)
        {
            ll p  ;
    int  n;
    cin >> n >> p ;
        ll x ;
        bool flag = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> x ;
            deno.push_back(x) ;
            if ( p%x !=0 )  flag = 1 ;
        }
        if (!flag)  cout << "NO\n" ;
        else
        {
            ll v = 0  ;
            int values[n] = {0} ;
            int j=0 ;
            while ( p>0 )
            {
                if ( p<deno[j] ) { values[j] = 1 ; break ; }
                else
                {
                    if ( p%deno[j]==0 ) 
                    {
                        ll z = p/deno[j] - 1 ;
                        p -= deno[j]*(z) ;
                        values[j] = z ;
                        j++ ;
                    }
                    else
                    {
                        values[j] = p/deno[j] + 1 ; 
                        break ;
                    }
                }
                   
            }
            cout << "YES\n" ;
            for ( int i=0 ; i<n ; i++ )
            {
                cout << values[i] << " " ;
            }         
            cout << "\n" ;
        }
        deno.clear() ;
        }
        
    return 0 ;
}