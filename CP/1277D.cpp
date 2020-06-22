#include<bits/stdc++.h>
#include<unordered_map>
using namespace std ;

int amin()
{
        int t ;
            cin >> t ;
                while(t--)
                {
                    unordered_map<string,string> zb , ob ;
                    int n ;
                    cin >> n ;

                    int irev = 0 ;
                        while(n--)
                        {
                            string s ;
                                cin >> s ;
                                size = s.length() ;
                            char c[size] ;
                                    if ( s[0] == s[s.length()-1] )  
                                    {
                                        if ( s[0] == '1' )  orev++ ;
                                        if ( s[1] == '0' )  zrev ++ ;
                                    }
                                for ( int i=0 ; s[i]!='\0' ; i++ )
                                {
                                    s[i] = c[size-1-i] ;
                                }
                            if ( s[0] == '0' )  zb.insert(pair<string,string>(s,c)) ;
                            else    ob.insert(pair<string,string>(s,c)) ;

                            if ( ob.size() > zb.size() )
                            {
                                if (!zrev)
                                { 
                                for ( auto it = zb.begin() ; it!=zb.end() ; ++it )
                                {
                                    ob.insert(pair<string,string>(it->second,it->first)) ;
                                }
                                    if ( ob.size() == n ) 
                                    { 
                                         cout << zb.size() << "\n" ;
                                        continue ;
                                    }
                                    else    zrev = 1 ;
                                }
                                if (zrev) cout << "-1\n" ; 
                            }
                            if ( zb.size() > ob.size() )
                            {
                                if (!zrev)
                                { 
                                for ( auto it = ob.begin() ; it!=ob.end() ; ++it )
                                {
                                    zb.insert(pair<string,string>(it->second,it->first)) ;
                                }
                                    if ( zb.size() == n ) 
                                    { 
                                         cout << ob.size() << "\n" ;
                                        continue ;
                                    }
                                    else    zrev = 1 ;
                                }
                                if (zrev) cout << "-1\n" ; 
                            }
                        }
                zb.clear() ;
                ob.clear() ;
                }
    return 0 ;
}