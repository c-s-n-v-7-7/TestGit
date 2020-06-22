#include<iostream>
#include<map>
#include<utility>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    map<string,int> S ;
    map<string,int>:: iterator j ;
    while(t--)
    {
        int n , x ;
        int count = 0 ;
        cin >> n ;
        string s ;
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> s >> x ;
            if ( i==0 ) continue ;
            else
            {
                j = S.find(i) ;
                if( j==S.end())  
                    S.insert(pair<string,int>(s,x)) ;
                else
                {
                    if ( j->second != x )
                    {
                        j->second = 10 ; 
                    }  
                }
                
            }
            
        }
    cout << count << "\n" ;
    }
    return 0 ;
}