#include<bits/stdc++.h>
using namespace std ;

unordered_map<int,int> digits ;
unordered_map<pair<int,int>,int> choice; 
int c ( int n , int r )
{

	if ( n<r )	return 0 ;
	if ( n==r )	return 1 ;
	if (r==1)	return n ;
	if(choice.find(pair<int,int>(n,r))==choice.end())	
	{
		choice.insert(pair<pair<int,int>,int>((n,r),(c(n-1,r-1)+c(n,r-1)))) ;
	}
return choice[pair<int,int>(n,r)] ;
}

void range(int k)
{
	int sum = 0 ;
	count = 2 ;
	while(sum<k)
	{
		sum += c(8+count,count-1) ;
	}
	if ( sum == k )	
}

int main()
{
	int k ;
	cin >> k ;
	range(k) ;
	return 0 ;
}