#include<bits/stdc++.h>
using namespace std ;

class TreeNode{
   public :
            int val ;
            TreeNode* left ;
            TreeNode* right ;
            TreeNode ( int v )
            {
                val = v ;
                left = NULL ;
                right = NULL ;
            }
} ;

int count ;

bool inorder ( TreeNode* root )
{
    if (root==NULL) return 0 ;
    if(inorder(root->left)&&inorder(root->right))   count++ ;
    return 1 ;
}

int main()
{
    int n ;
    cin >> n ;
    count = 0 ;
        n-- ;
    TreeNode* root = TreeNode(1) ;
    queue<TreeNode*> t ;
        
        t.push(Node) ;
        /* 1-> pop 
           2->left 
           3->right
        */
        int c=0 ;
    while(1)
    {
        cin >> c ;
        if ( c == 1 )   { t.pop() ; n-- ; }
        if ( c == 2 ) 
        {
            if (tree.front()->left!=NULL)   continue ;
            cout << "Enter Value : " ;
            int u ;
            cin >> u ;
            TreeNode* nd = TreeNode(u) ;
            t.push(nd) ;
            t.front()->left = nd ;
        }
        if ( c == 3 ) 
        {
            if (tree.front()->right!=NULL)   continue ;
            cout << "Enter Value : " ;
            int u ;
            cin >> u ;
            TreeNode* nd = TreeNode(u) ;
            t.push(nd) ;
            t.front()->right = nd ;
        }
        if ( t.front()->left!=NULL && t.front()->right!=NULL) 
        {
            t.pop() ;
            n-- ;
        }
    }
    inorder(root) ;
    cout << count ; 
    return 0 ;
}