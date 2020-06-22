#include<iostream>
using namespace std ;

int NoOfDigits( long int n )
{
    int j=0 ;
    while(n!=0)
    {
        n/=10 ;
        j++ ;
    }
return j ;
}

long int power ( int a , int y )
{
    long int k = 1; 
    while(y>0)
    {
        k*=a ;
        y--;
    }
return k ;
}

long int similar(long int d)
{
    long int y = 0 ;
    while( d>0 )
    {
        y += d ;
        d/=10 ;
    }
return y ;
}

int main()
{
    int t ;
        cin >> t ;

        while(t--)
        {
            
            long int n ;
            cin >> n ;
            
            if ( n/10==0 ) cout << n << "\n" ;
            else
                {
                   
                    int num = 9 ;
                    long int y = 11 ;
                    
                     long int d = power(10,2) ;
                        long int t1=11 ;
                        while(y<=n)
                        {
                            num ++ ;
                           // cout << y << " " ;
                            y+=t1 ;
                            if ( y%d==1) { y = (similar(d)) ; d*=10 ; t1 = y ;}
                      // cout << t1 << " ";
                        
                        }
                    //cout << num << "\n" ;
                }
        }
    return 0 ;
}