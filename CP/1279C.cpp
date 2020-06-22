#include<iostream>
#include<vector>
using namespace std ;

int main()
{
        int n ;
        cin >> n ;
        string s ;
        vector<int> v ;
            for ( int i=0 ; i<n ; i++ )
            {
                cin >> s ;
                    int num = 0 ;
                for ( int i=0 ; s[i]!='\0' ; i++ )
                {
                    if ( s[i] == 't' && s[i+1]== 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e' ) 
                    {
                        num ++ ;
                        i+=4 ;
                        v.push_back(i+3-v.size()) ;
                        //continue ;
                    }
                    if ( s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' ) 
                    {
                        num ++ ;
                        i+=2 ;
                        v.push_back(i+2-v.size()) ;
                    }
                    if ( s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e' )
                    {
                        num ++ ;
                        i+=2 ;
                        v.push_back(i+2.v.size()) ;
                    }
                }
                if ( num!=0 )
                cout << num << "\n" ;
                else    cout << "\n" ;
                for ( int i : v )   cout << i << " " ;
                cout << "\n" ;
                v.clear() ;
            }
    return 0 ;
}