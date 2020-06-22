#include<iostream>
using namespace std ;

int main()
{
    int t ;
    cin >>t ;
    while(t--)
    {
        int n , k ,s , days , flag=0 ;
        cin >> n >> k >> s ;
        if ( n < k || k == 1 )  { days = 0  ;   flag=1 ; } 
        if ( !flag )   
        {
            int cnt[7] ;
            int y = 0 ;
            for ( int i=0 ; i<7 ; i++ ) cnt[i] = 0 ;
            int left = k ;
            while(y<s)
            {
                cnt[k-left] ++ ;
                left-- ;
                if ( cnt[5] > cnt[6] && left == 1 ) y++ , left += k ;
            }
        }
    }
    return 0 ;
}