#include<iostream>
#include<map>
#define ll long long int 
using namespace std ;

int main()
{
    ll t ;
    cin >> t ;
    while(t--)
    {
        ll n ;
        double time = 0 ;
        map<string,int> M ;
        map<string,int> :: iterator it ;
        cin >> n ;
        string s[n] ;
        for ( ll i=0 ; i<n ; i++ )
            {
                cin >> s[i] ;
                it = M.find(s[i]) ;
                if ( it == M.end()) M.insert( pair<string,int> (s[i],1)) ;
                else    it->second++ ;
            }
            time = 0.0 ;
            double r = 0 ;
        for ( it = M.begin() ; it!=M.end() ; ++it )
        {   r=0.2 ;
            for ( int i=1 ; it->first[i] !='\0' ; i++ )
            {
                if ( it->first[i] == 'd' || it->first[i-1] == 'f' )
                {
                    if ( it->first[i-1] == 'j' || it->first[i-1] == 'k')
                        r += 0.2 ;
                    else    r += 0.4 ;
                }
                if ( it->first[i]=='j' || it->first[i] == 'k' )
                {
                    if ( it->first[i-1]=='f' || it->first[i-1]=='d') 
                    r += 0.2 ;
                    else    r += 0.4 ;
                }
            }
            time += r*((2**it->second)-1)
        }
    cout << time << "\n" ;
    }
    return 0 ;
}