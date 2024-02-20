//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

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

class Solution{ 
public:
    Node* reverse(Node* head)
    {
        if(head==NULL) return NULL;
        
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=NULL;
        
        while(curr!=NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    Node* findMid(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    // Node* merge(Node* left, Node* right)
    // {
    //     // if(left==NULL) return right;
    //     // if(right==NULL) return left;
        
    //     Node* temp1=left;
    //     Node* temp2=reverse(right);
        
    //     Node* dummy = new Node(0);
    //     Node* ptr = dummy;
        
    //     while(temp1!=NULL && temp2!=NULL)
    //     {
    //         if(temp1!=NULL)
    //         {
    //             ptr->next = new Node(temp1->data);
    //             ptr=ptr->next;
    //         }
    //         if(temp2!=NULL)
    //         {
    //             ptr->next = new Node(temp2->data);
    //             ptr=ptr->next;
    //         }
    //         temp1=temp1->next;
    //         temp2=temp2->next;
    //     }
        
    //     while(temp1!=NULL)
    //     {
    //         ptr->next = new Node(temp1->data);
    //         ptr=ptr->next;
    //         temp1=temp1->next;
    //     }
        
    //     while(temp2!=NULL)
    //     {
    //         ptr->next = new Node(temp2->data);
    //         ptr=ptr->next;
    //         temp2=temp2->next;
    //     }
    //     return dummy->next;
    // }
    
    void reorderList(Node* head) 
    {
        Node* mid  = findMid(head);
        
        // Node* slow=head;
        // Node* fast=head;
        
        // while(fast!=NULL && fast->next!=NULL)
        // {
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        
        Node* ptr1 = head;
        Node* temp = reverse(mid->next);
        mid->next=NULL;
        
        Node* ptr2=temp;
        
        while(ptr1!=NULL && ptr2!=NULL)
        {
            Node* ptr3=ptr1->next;
            Node* ptr4=ptr2->next;
            
            ptr1->next=ptr2;
            ptr2->next=ptr3;
            
            ptr1=ptr3;
            ptr2=ptr4;
        }
    }
};





//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends