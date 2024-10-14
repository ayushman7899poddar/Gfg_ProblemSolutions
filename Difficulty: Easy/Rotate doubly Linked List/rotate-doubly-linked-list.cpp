//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;


// } Driver Code Ends
//User function Template for C++

/*
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;
*/

class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        if(start == NULL || start->next == NULL) return start;
        
        vector<int>temp;
        
        Node* ptr = start;
        
        while(ptr!=NULL)
        {
            temp.push_back(ptr->data);
            ptr = ptr->next;
        }
        
        int n = temp.size();
        p = p%n;
        
        vector<int>vec(n,0);
        
        
        for(int i=n-1; i>=0; i--)
        {
            int index = i-p;
            
            if(index<0)
            {
                index = n+index;
            }
           
            
            vec[index] = temp[i];
        }
        
        // for(auto i : vec)
        // {
        //     cout<<i<<" ";
        // }cout<<endl;
        
        
        
        Node* head = new Node(vec[0]);
        Node* tail = head;
        
        for(int i=1; i<vec.size(); i++)
        {
            Node* newNode = new Node(vec[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        
        tail->next = NULL;
        
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start = NULL;
        struct node* cur = NULL;
        struct node* ptr = NULL;
        
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new node(a);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        Solution obj;
        struct node*str=obj.rotateDLL(start,p);
        while(1)
        {
            cout<<str->data<<" ";
            if(str->next==NULL)break;
            str=str->next;
        }
        // while(str!=NULL)
        // {
        //     cout<<str->data<<" ";
        //     str=str->prev;
        // }
        cout<< "\n";   
    }
}


// } Driver Code Ends