#include<iostream>
#include<unordered_map>
#include<map>
#include<utility>
#define ll long long int
using namespace std ;

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                ll n ;
                cin >> n ;
                    char a[n+1] ;
                cin >> a ;
                long int last = n , prev = -1 ;
                //Need an array to store the posn of a paricular 
                //no. of ')' 
                //Stuff required for closing brackets :-
                unordered_map<ll,ll> closers ;
                closers.insert(pair<ll,ll>(0,n-1)) ;
                unordered_map<ll,ll>::iterator it , j ;
                int del=0 ;
                int prevclose = -1 ;    int lastchange = -1 ;
                ll change[n] ;
                for ( ll i=n-1 ; i>=0 ; i-- )
                {
                    if ( a[i] == '(')
                        {
                            del -- ;
                            if ( i==n-1 )
                            {
                                change[i] = 0 ; 
                                prev = 0 ;
                            }
                            else    
                            {
                                if ( change[i+1] == 0 )
                                    {
                                        change[i] = 0 ;
                                    }
                                else
                                    {
                                        it = closers.find(-del+1) ; 
                                            
                                        if ( it == closers.end() )
                                        change[i] = 0 ;
                                        else
                                        change[i] = change[it->second] ;
                                        it->second = i ;
                                    }    
                                      prev-- ;
                            }
                             if ( del >=0 )
                          closers.insert(pair<ll,ll>(del,i)) ;   
                        }
                    if ( a[i] == ')' )
                    {
                        del++ ;
                        closers.insert(pair<ll,ll>(del,i)) ;
                        if ( prevclose == -1 )  
                        {
                            prevclose = i ;
                            change[i] = n - prevclose ;
                        }
                        else
                        {
                            it = closers.find(del-1) ;
                            change[i] = (n - prevclose)+change[it->second] ;
                            prevclose = i ;
                        }
                        lastchange = change[i] ;
                     closers.insert(pair<ll,ll>(del,i)) ;
                    }
                }
             ll total = 0 ;
                for ( ll i=0 ; i<n ; i++ )
                {
                   cout << change[i] << " " ; 
                }
               // cout << total << "\n" ;
            }
    return 0 ;
}