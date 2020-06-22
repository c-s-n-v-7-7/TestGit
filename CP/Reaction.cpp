#include<iostream>
using namespace std ;

int main()
{
  int t ;
  while(t--)
  {
      int r , c ;
      cin >> r >> c ;
      int ideal[r][c] ;
      for ( int i=1 ; i<r-1 ; i++ )
      {
          for ( int j=1 ; j<c-1 ; j++ )
          {
             ideal[i][j] = 4 ;
          }
      }
      for ( int i=0 ; i<r ; i++ )
      {
          ideal[i][0] = 3 ;
          ideal[i][c-1] = 3 ;
      }
      for ( int i=0 ; i<c ; i++ )
      {
          ideal[0][i] = 3 ;
          ideal[r-1][i] = 3 ;
      }
      ideal[0][0] = ideal[r-1][c-1] = ideal[r-1][0] = ideal[0][c-1] = 2 ;
     int flag = 0 ;
     for ( int i=0 ; i<r ; i++ )
     {
         for ( int j=0 ; j<c ; j++ )
         {
             cin >> a[i][j] ;
             if ( a[i][j] >= ideal[i][j] ) flag=1 ;
         }
     }
     if (flag) cout << "Unstable\n" ;
     else cout << "Stable\n" ;
  }
    return 0 ;
}