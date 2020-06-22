#include<iostream>
using namespace std; 
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n , h , y1 , y2 , l , step = 0 ;
        cin >> n >> h >> y1 >> y2 >> l ;
        int  ti , x ;
        vector<int> barrier ;
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> ti >> x ;
            if ( barrier[x] == 1 )  step++ ;
            barrier[x] = 1 ;

            if ( ti == 1 )   
            {
                if ( x < h-y1 ) step++ ;  
            }
            if ( ti == 2 )
            {
                if ( x > y2 )   step++ ;
            }
        }
        if ( l > steps ) cout << l-steps << "\n" ;
        else    cout << "0\n" ;
    }
    return 0 ;
}