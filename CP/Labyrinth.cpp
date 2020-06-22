//1063B
//WA on tc13
//Check
#include<bits/stdc++.h>
#define ll long int 
using namespace std ;

//vector<vector<char>> L ;
vector<vector<bool>> vis ;

	int n , m ;
    int count ;
    
bool CanMove( int x , int y )
{
	if(x<1||y<1||x>n||y>m)	return 0 ;
	if(vis[x][y])	return 0 ;
	return 1 ;
}


int Movement ( int x , int y , ll pl , ll nl )
{
	vis[x][y] = 1 ;
	int var=1 ;
		if (CanMove(x+1,y))	var += Movement(x+1,y,pl,nl) ;
		if (CanMove(x-1,y))	var += Movement(x-1,y,pl,nl) ;
		if(pl>0)
		{
			if(CanMove(x,y+1))	var += Movement(x,y+1,pl-1,nl) ;
		}
		if(nl>0)
		{
			if(CanMove(x,y-1))	var += Movement(x,y-1,pl,nl-1) ;
		}
return var ;
}

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m ;
	
	//count = 0 ;

	int r , c ;
	cin >> r >> c ;

	ll nm , pm ;
    cin >> nm >> pm ;

    //L = vector<vector<char>> (n+2) ;
    vis = vector<vector<bool>> (n+2) ;
    for ( int i=0 ; i<vis.size() ; i++ )
    {
    	//L[i] = vector<char> (m+2) ;
    	vis[i] = vector<bool> (m+2,0) ;
    }
		string L[n+2] ;
	 for ( int i=1 ; i<=n ; i++ )
	 {
	 	cin >> L[i] ;
	 	for ( int j=0 ; j<L[i].size() ; j++ )
	 	{
	 		if (L[i][j]=='*')	vis[i][j+1]	= 1 ;
	 	}
	 }


	 /*for ( int i=1 ; i<=n ; i++ )
	 {
	 	for ( int j=1 ; j<=m ; j++ )
	 	{
	 		cout <<  L[i][j] << " " ;
	 	}
	 	cout << "\n" ;
	 }*/
	 int var = 0 ;
	 	if(!vis[r][c])	
	 		var += Movement(r,c,pm,nm) ;
    /*for ( int i=0 ; i<vis.size() ; i++ )
    {
        for ( int j=0 ; j<vis[0].size() ; j++ )
        {
            cout << vis[i][j] << " " ;
        }
        cout << "\n" ;
    }*/
    
    cout << var ;
    
	return 0 ;
}