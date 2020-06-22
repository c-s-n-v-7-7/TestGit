#include<iostream>
#include<vector>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    vector<int>heights ;
    int h ;
    for (int i=0 ; i<n ; i++ )
    {
        cin >> h ;
        heights.push_back(h) ;
    }
    int n = 0 ;
    for ( int i=0 ; i<n ; i++ )
    {
        n += heights[i]/2 ;
        heights[i] = heights[i] - 2*(heights[i]/2) ;
    }
    for ( int i=0 ; i<n-1 ; i++ )
    {
        if ( heights[i] == 0 )  continue ;
        else    if(heights[i+1]!=0) 
        {
            heights[i] = heights[i+1] =0 ;
            n++ ;
        }
    }
    cout << n ;
    return 0 ;
}