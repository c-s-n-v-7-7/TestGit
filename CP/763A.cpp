#include<iostream>
using namespace std ;

long long int mod ( long long int x )
{
	return (x<0)? -x:x ;
}
int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			long long int a[3] ;
			cin >> a[0] >> a[1] >> a[2] ;
			long long int dist=0 ;
			sort(a,a+3) ;
			for ( int i=0 ;i<3 ; i++ )
			{
				if(a[2]-a[1] <= 1 )	a[2]=a[1] ;
				else
					a[2] = a[2]-1 ;
				if(a[0]-a[1] <= 1 )	a[0]=a[1] ;
				else
					a[0]=a[0]+1 ;
				cout << a[1]-a[0] + a[2]-a[1] + a[2]-a[0] << "\n" ;
			}
		}
	return 0 ;
}
#include<iostream>
using namespace std ;

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                string s ;
                cin >> s ;
                    int x=0 , y=0 ;
                    int prevx=0 , prevy=0 ;
                    for ( int i=0 ; s[i]!='\0' ; i++ )
                    {
                        if(s[i]=='R') x++ ;
                        if(s[i]=='L') x-- ;
                        if(s[i]=='U') y++ ;
                        if(s[i]=='D') y-- ;
                    }
            }
    return 0 ;
}
#include<iostream>
using namespace std ;

int main()
{
        int n , k ;
        cin >> n >> k ;
        char s[n+1] ;
        cin >> s;
            char x ;
            bool av[26] = {0} ;
            for ( int i=0 ; i<k ; i++ )
                {
                    cin >> x ;
                    av[x-97]=1 ;
                }
            int l=0 ;
            int sum = 0 ;
            for ( int i=0 ; s[i]!='\0' ; i++ )
            {
                l++ ;
                if (!av[s[i]-97])  
                {
                    sum += ((l-1)*(l))/2 ;
                    l=0 ;
                }
            }
            cout << sum ;
    return 0 ;
}
#include<iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    int a[n+1] ;
    a[n] = 0 ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] ;
    }
    int l=1 , maxl=0 ;
    bool f=0 ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
        if (!f&& (a[i] > a[i+1] && a[i]<=a[i+2])&&(a[i]<=a[i+2]&&a[i+1]>a[i+2]))
        {
            i++ ; f=1; 
        }
       
        if ((f&&a[i]>a[i+1])||(a[i] > a[i+1] && a[i]>a[i+2]))
        {
            if(l>maxl)  maxl=l ;
            l=1 ;
        f=0 ;
        }
        
        l++ ;
    }
    if ( l > maxl ) maxl = l ;
    cout << maxl ;
    return 0 ;
}
https://codeforces.com/contest/1272/problem/F