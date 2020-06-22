#include<iostream>
using namespace std ;

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                string a , b ,c ;
                cin >> a >> b >> c ;
                int count = 0 ;
                int n ;
                for ( n=0 ; a[n]!='\0' ; n++ )  {} ;
                for ( int i=0 ; a[i]!='\0';i++)
                {
                    
                    if ( a[i] == c[i] || b[i] == c[i] ) 
                    count++ ;
                    else    { count=-1 ; break ; }
                }
                if ( count == -1 ) cout << "NO\n" ;
                else    cout << "YES\n" ;
            }
    return 0 ;
}