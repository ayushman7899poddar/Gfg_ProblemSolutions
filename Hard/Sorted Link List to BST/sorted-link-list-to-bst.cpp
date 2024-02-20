//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */

        // CONSTRUCT A TREE LIKE AN ARRAY CONFIRMED INTO TREE::
class Solution{
  public:
  TNode* formTree(vector<int>&vec, int i, int j)
  {
      if(i>j) return NULL;
    //   int mid = (i+j)/2;
    int mid=0;
    if((i+j)%2!=0){
        mid = (i+j)/2+1;
    }
    else{
        mid=(i+j)/2;
    }
      
      TNode* newNode = new TNode(vec[mid]);
      newNode->left = formTree(vec,i,mid-1);
      newNode->right = formTree(vec,mid+1,j);
      
      return newNode;
  }
    TNode* sortedListToBST(LNode *head) 
    {
        if(head==NULL) return NULL;
        
        if(head->next == NULL)
        {
             int val = head->data;
            TNode* newNode = new TNode(val);
            return newNode;
        }
         vector<int>vec;
         LNode* temp=head;
         
         while(temp!=NULL)
         {
             vec.push_back(temp->data);
             temp=temp->next;
         }
         
         return formTree(vec,0,vec.size()-1);
        
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends