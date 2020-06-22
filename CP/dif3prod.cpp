#include<iostream>
#include<utility>
#include<unordered_map>
#include<vector>
using namespace std ;

vector<long int> v ;
void primes(long int j = 1000000000)
{
	v.push_back(2) ;
		for ( long int i=3 ; i*i <= j ; i++ )
		{
			bool f=0 ;
			for ( long int u : v )	
			{
				if(i%u==0)	{f=1; break ;}
			}
			if(!f)	v.push_back(i) ;
		}
}
unordered_map<int,int> factorise( long int x )
{
		unordered_map<int,int> c ;
	for ( long int i : v )
	{
		if ( i > x )	break ;
		if ( x%i == 0 )	
		{
			int j=0 ;
			while(x%i==0)	
			{
				x/=i ;
				j++ ;
			}
			c.insert(pair<int,int>(i,j)) ;
		}
	}
	if (x!=1)	c.insert(pair<int,int>(-1,-1)) ;
	if (c.size() < 3 )	
	{
		int y=0 ;
		for ( auto it = c.begin() ; it!=c.end() ; ++it )
		{
			y += it->second ;
		}
		if ( y < 3 )
			{
				c.clear() ;
				c.insert(pair<int,int>(-1,-1)) ;
			}
	}
return c ;	
}

int main()
{
		int t ;
		cin >> t ;
		primes() ;
	while(t--)
	{
				long int n ;
				cin >> n ;
					unordered_map<int,int> num = factorise(n) ;
				unordered_map<int,int>::iterator it ;
				it = num.begin() ;
					if ( it->first == -1 )	cout << "NO\n" ;
	    	else
			        {
				long int a[3] = { 1 , 1 , 1 } ;
				unordered_map<int,int>::iterator j = num.begin() ;
				if ( num.size() == 1 && j->second <= 5 )    {cout << "NO\n" ; continue ; }
                    if ( num.size() == 2 )
                            {
                                int y = 0 ;
                                    for ( ;j!=num.end();++j)  y+=j->second ;
                                if(y<=3)    cout << "NO\n" ; continue ;
                            }
				        cout << "YES\n" ;
				        
				        for ( auto it = num.begin() ; ;)
				        {
				             
				             
				                 a[0]*= it->first ;
				                 it->second-- ;
				             
				             if(a[1]<2||a[1]==a[0])
				             {
				                 while(it->second>0&&a[1]==a[0])
				                 {
				                     a[1]*=it->first ;
				                     it->second-- ;
				                 }
				                 ++it ;
				             }
				        }
				             cout << a[0] << " " << a[1]  << " " <<  n/(a[0]*a[1]) << "\n" ; 
	        }
	        
	}
	return 0 ;
}