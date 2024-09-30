//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void mergeSort(vector<int>&vec1, vector<int>&vec2, vector<int>&ans)
    {
        //   if(vec1.size()== 0) return vec2;
        //   if(vec2.size() == 0) return vec1;
          
        //   if(vec1.size()==0 && vec2.size()==0)
        //   {
        //       return ans;
        //   }
          
          int i=0,j=0;
          int n = vec1.size(), m = vec2.size();
          
          while(i<n && j<m)
          {
              if(vec1[i] < vec2[j])
              {
                  ans.push_back(vec1[i]);
                  i++;
              }
              else if(vec1[i] > vec2[j])
              {
                  ans.push_back(vec2[j]);
                  j++;
              }
              else if(vec1[i] == vec2[j])
              {
                  ans.push_back(vec1[i]);
                  ans.push_back(vec2[j]);
                  i++;
                  j++;
              }
          }
          
          while(i<n)
          {
              ans.push_back(vec1[i]);
              i++;
          }
          
          while(j<m)
          {
              ans.push_back(vec2[j]);
              j++;
          }
          
        //   return ans;
    }
  
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder1(Node* root1, vector<int>&vec1)
    {
        if(root1==NULL) return;
        
        inorder1(root1->left,vec1);
        vec1.push_back(root1->data);
        inorder1(root1->right,vec1);
    }
    
    void inorder2(Node* root2, vector<int>&vec2)
    {
        if(root2==NULL) return;
        
        inorder2(root2->left,vec2);
        vec2.push_back(root2->data);
        inorder2(root2->right,vec2);
    }
    
    
    vector<int> merge(Node *root1, Node *root2) 
    {
        vector<int>ans;
        
        vector<int>vec1,vec2;
        inorder1(root1,vec1);
        inorder2(root2,vec2);
        
        if(root1==NULL) return vec2;
        if(root2 == NULL) return vec1;
        if(root1==NULL && root2==NULL) return ans;
        
        mergeSort(vec1,vec2,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends