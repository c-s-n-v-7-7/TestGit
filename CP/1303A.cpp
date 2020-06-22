#include<iostream>
using namespace std ;

int main()
{   
    int t ;
    cin >> t ;
        while(t--)
        {
            string  s ;
            cin >> s ;
                int first = -1 ;
                int second = -1 ;
                for ( int i=0 ; s[i]!='\0';i++)
                {
                    if ( s[i] == '1' )
                    {
                        if ( first == -1 )  first = i ;
                    }    
                    if ( s[i] == '1' )
                    {
                        if ( i > last ) last = i ;
                    }
                }
                int num = 0 ;
                if ( first!=-1) 
                {
                for ( int i=first ; i<=last ; i++ )
                {
                    if ( s[i] == '0')   num ++ ;
                }
                }
                else    cout << num << "\n" ;
            
        }
    return 0 ;
}