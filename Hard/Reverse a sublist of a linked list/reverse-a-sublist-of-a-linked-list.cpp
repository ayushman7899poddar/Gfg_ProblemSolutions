//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/
                    //BRUTE-FROCE APPROACH::
class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        vector<int>vec1,vec2,vec3;
        
        Node* temp=head;
        
        int cnt=1;
        while(temp!=NULL)
        {
            if(cnt<m){
                vec1.push_back(temp->data);
            }
            if(cnt>=m && cnt<=n)
            {
                vec2.push_back(temp->data);
            }
            else if(cnt>n){
                vec3.push_back(temp->data);
            }
            cnt++;
            temp=temp->next;
        }
        reverse(vec2.begin(),vec2.end());
        
        Node* dummy = new Node(0);
        Node* ptr=dummy;
        
        for(int i=0; i<vec1.size(); i++)
        {
            ptr->next=new Node(vec1[i]);
            ptr=ptr->next;
        }
        for(int i=0; i<vec2.size(); i++)
        {
            ptr->next=new Node(vec2[i]);
            ptr=ptr->next;
        }
        for(int i=0; i<vec3.size(); i++)
        {
            ptr->next=new Node(vec3[i]);
            ptr=ptr->next;
        }
        return dummy->next;
    }
};






//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends