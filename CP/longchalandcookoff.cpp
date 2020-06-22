#include<iostream>
#include<utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t ;
        while(t--)
        {
            pair<long int,long int> start , finish ;
            cin >> start.first >> start.second ;
            cin >> finish.first >> finish.second ;
            // 2020 Feb1 is sat
                int c = 7 ;
                int nc = 0 ;
                long int i ;
            for ( int i=2020 ; i>=start.second ; i-- )
            {
                    if ( c == 7 )   nc++ ;
                    if ( c==1 && ( (i%4!=0) || ((i%100==0)&&(i%400!=0)) ) )    nc++ ;
                if( ((i-1)%100 == 0 && (i-1)%400 == 0) || ((i-1)%100!=0&&(i-1)%4==0) ) 
                                c-- ;
                               c-- ;
                    if ( c == 0 )    
                        c=7 ;
                    if ( c == -1 )
                        c=6 ; 
            }
            if ( start.first > 2 ) 
             nc-- ;
            c = 2 ;
            for ( i = 2021 ; i<=finish.second ; i++ )
            {
                 if ( c == 7 ) nc++ ;
                 if ( c == 1 )
                 {
                     if ( ( (i%4!=0) || ( (i%100==0) && (i%400!=0) ) ) )    nc++ ; 
                        else    c++ ;
                 }
            //    if (  ( (i+1)%100 == 0 && (i+1)%400 == 0) || ((i+1)%100!=0&&(i+1)%4==0) )
                      c ++ ;
                    
                    if ( c == 8 )
                        c=1 ;
                    if ( c==9 )
                        c=2 ;
            }
            if ( finish.first < 2 ) nc-- ;
        cout << nc << "\n" ;
        }
    return 0 ;
}