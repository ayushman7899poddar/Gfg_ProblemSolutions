//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) 
    {
        if(head == NULL) return {NULL};
        
        Node* dummy1 = new Node(0);
        Node* ptr1 = dummy1;
        
        Node* dummy2 = new Node(0);
        Node* ptr2 = dummy2;
        
        int cnt=1;
        
        Node* temp = head;
        
        while(temp!=NULL)
        {
            if(cnt%2!=0)
            {
                ptr1->next = new Node(temp->data);
                ptr1 = ptr1->next;
            }
            else if(cnt%2==0)
            {
                ptr2->next = new Node(temp->data);
                ptr2 = ptr2->next;
            }
            cnt++;
            temp = temp->next;
        }
        
        Node* head1 = dummy1->next;
        Node* head2 = dummy2->next;
        
        vector<Node*>ans;
        ans.push_back(head1);
        ans.push_back(head2);
        return ans;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends