#include<bits/stdc++.h>
#define lint long long int
using namespace std ;

lint min ( lint a , lint b )
{
    return (a<b)? a:b ;
}

bool In( lint a )
{
    bool e=0 , t=0 ;
    while(a!=0)
    {
        if(a%10==3) t=1 ;
        if(a%10==8) e=1 ;
        a/=10 ;
    }
return ((!e&&t)||(e&&!t)) ;
    
}

map<lint,lint> factors(lint x)
{
    map<lint,lint> f ;
    for ( int i=2 ; i*i<=x ; i++ )
    {
        if (x%i==0)
        {
            while(x%i==0)
            {
                f[i]++ ;
                x/=i ;
            }
        }
    }
    if(x!=0)
    {
        f[x]++ ;
    }
return f ;    
}

set<lint> perfsq( lint r )
{
    set<lint> s ;
    for ( lint i=1 ; i<=r ; i++ )
    {
        if(!In(i))  continue ;
        map<lint,lint> m = factors(i) ;
        bool c=0 ;
        for ( auto it = m.begin() ; it!=m.end() ; ++it )
        {
            if(it->second%2==1) {   c=1 ; break ; } 
        }
        if(!c)  s.insert(i) ;
    }
return s ;
}

set<lint> perfsqb1( int r )
{
    set<lint> s ;
    for ( lint i=1 ; i<=r ; i++ )
    {
        if(!In(i))  continue ;
        map<lint,lint> m = factors(i+1) ;
        bool c=0 ;
        for ( auto it = m.begin() ; it!=m.end() ; ++it )
        {
            if(it->second%2==1) {   c=1 ; break ; } 
        }
        if(!c)  s.insert(i) ;
    }
return s ;
}

set<lint> div7(lint n)
{
    set<lint> s ; 
    for ( lint i=7 ; i<=n ; i*=7 )    
    {
        if(!In(i))  continue ;
        s.insert(i) ;
    }
return s ;
}

set<lint> all2digs(lint r)
{
    set<lint> a ;
    for ( lint i=10 ; i<=min(r,99) ; i++ )
    {
        if(!In(i))  continue ;
        a.insert(i) ;
    }
return a ;
}

bool isPrime( map<lint,lint> s )
{
    if(s.size()>1)  return 0 ;
    if(s.begin()->second!=1)    return 0 ;
return 1 ;
}

set<lint> primeb1(lint r)
{
    set<lint> s ;
    for ( lint i=1 ; i<=r ; i++ )
    {
        if(!In(i))  continue ;
       map<lint,lint> f = factors(i+1) ;
        if(isPrime(f))  s.insert(i) ;       
    }
return s ;
}

set<lint> grthan2d(lint r)
{
    set<lint> s ;
    for ( lint i=100 ; i<=r ; i++ )
    {
        if(!In(i))  continue ;
        s.insert(i) ;
    }
return s ;
}

set<lint> div11r(lint r)
{
    set<lint> s ;
    for ( int i=11 ; i<=r ; i++ )
    {
        if(!In(i))  continue ;
        s.insert(i) ;
    }
return s ;
}

set<lint> prime(lint r)
{
   set<lint> s ;
    for ( lint i=2 ; i<=r ; i++ )
    {
        if(!In(i))  continue ;
        map<lint,lint> f = factors(i) ;
        if(isPrime(f))  s.insert(i) ;       
    }
return s ;
}

int main()
{
    lint r = 10000 ;
    set<lint> p1 = perfsq(r) ;
    cout << "EX1-1\n"  ;
    set<lint> p1p = div7(r) ;
    cout << "EX1-2\n" ;
    set<lint> p2 = primeb1(r) ;
    cout << "EX2-1\n" ;
    set<lint> p2p = all2digs(r) ;
    cout << "EX2-2\n" ;
    set<lint> p3 = perfsqb1(r) ;
    cout << "EX3-1\n" ;
    set<lint> p3p = grthan2d(r) ;
    cout << "EX3-2\n" ;
    set<lint> p5 = div11r(r) ;
    cout << "EX5-1\n" ;
    set<lint> p5p = prime(r) ;
    cout << "EX5-2\n" ;
    set<lint> P1 , P2 , P3 , P5 ;
    for ( lint i : p1 )
    {
        P1.insert(i) ;
    }
    cout << "Ins1 complete\n" ;
    set<int>::iterator itr ;
    for ( lint j : p1p )
    {
        itr = P1.find(j) ;
        if (itr!=P1.end())  P1.erase(itr) ;
        else    P1.insert(j) ;
    }
 cout << "Del1 complete\n" ;
    for ( lint i : p2 )
    {
        P2.insert(i) ;
    }
 cout << "Ins2 complete\n" ;    
    for ( lint j : p2p )
    {
        itr = P2.find(j) ;
        if ( itr!= P2.end() )   P2.erase(itr) ;
        else    P2.insert(j) ;
    }
 cout << "Del2 complete\n" ;
    for ( lint i : p3 )
    {
        P3.insert(i) ;
    }
 cout << "Ins3 complete\n" ;    
    for ( lint j : p3p )
    {
        itr = P3.find(j) ;
        if ( itr!= P3.end() )   P3.erase(itr) ;
        else    P3.insert(j) ;
    }
 cout << "Del3 complete\n" ;
    for ( lint i : p5 )
    {
        P5.insert(i) ;
    }
 cout << "Ins5 complete\n" ;
    for ( lint j : p5p )
    {
        itr = P5.find(j) ;
        if ( itr!= P5.end() )   P5.erase(itr) ;
        else    P5.insert(j) ;
    }
 cout << "Del5 complete\n" ;
  // cout << (P1.find(343)!=P1.end()&&P2.find(343)!=P2.end()&&P3.find(343)!=P3.end()&&P5.find(343)!=P5.end()) ;
    for ( lint i : P1 )
    {
        cout << P2.find(i)&&P3.find(i)&&P5.find(i) << "\n" ;
    }
    /*cout << "P1 : \n" ;
    for ( int i : P1 )  cout << i << " " ;
    cout << "\nP2 : \n" ;
    for ( int i : P2 )  cout << i << " " ;
    cout << "\nP3 : \n" ;
    for ( int i : P3 )  cout << i << " " ;
    cout << "\nP5 : \n" ;
    for ( int i : P5 )  cout << i << " " ;
     */
    return 0 ;
}