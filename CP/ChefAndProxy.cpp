#include<iostream>
using namespace std;

bool wpr ( int cur , int tot , char c[] )
{
    for ( int i=cur-2 ; i<cur+3 ; i++ )
    {
        if ( c[i] == 'P' )  return true ;
    }
return false ;
}
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int d ;
        cin >> d ;
        char c[d+1] ;
        cin >> c ;
        int pr=0 ;
        int flag = 0 ;
        float perc = d*0.75 ;
        for ( int i=0 ; i<d ; i++ )
        {
            if ( c[i]=='P') pr++ ;
        }
            for ( int i=2 ; i<d-2 ,pr<perc ; i++ )
            {
                if ( c[i] == 'A')
                {
                    if(wpr(i,d,c)) flag++ , pr++ ;
                }
            }
        if ( pr>=perc) cout << flag << "\n" ;
        else    cout << "-1\n" ;
    }
    return 0 ;  
}