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
	int k ;
	cin >> k ;
	int freq[26]={0} ;
		for ( int i=0 ; s[i]!='\0' ; i++ )
		{
				freq[s[i]-97]++ ;
		}
		int l=0 ; 
		for ( int i=0 ; i<26 ; i++ )
		{
			if(freq[i]>=k) l+=freq[i] ;	
		}
		cout << l << "\n" ;
	}
	return 0 ;
}