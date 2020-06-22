#include<iostream>
#include<vector>
using namespace std ;

int mod ( long int c )
{
    return (c<0)? -c: c ;
}

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                int n ;
                    cin >> n ;
                int a[n] ;
                vector<int> val ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> a[i] ;
                    if ( a[i] == -1 )   val.push_back(i) ;
                }
                //vector<float> v ;
                float v ;
                if ( val[0] == 0 )  v+=(a[1]) ;
              for ( int i : val )
              {
                  if ( i!=0 && i!=n-1 ) v+=((float)(a[i-1]+a[i+1])/float(2)) ;
              }
                if (val[val.size()-1]==-1)  v+=(a[n-2]) ;
                v /= (float)n ;
                //if ( (int)(2*v) > 2*(int)v )    v = (int)v + 1 ;
                /*else*/    v = (int)v ;
            for ( int i=0 ; i<n ; i++ )
            {
                if ( a[i] == -1 )
                {
                    a[i] = v ;
                }
            }
            int max = 0 ;
            for ( int i=0 ; i<n ; i++ )
            {
                if ( a[i+1] - a[i] > max )  max = a[i+1]-a[i] ;
            }
                cout << max << " " << v << "\n" ;
            }
    return 0 ;
}