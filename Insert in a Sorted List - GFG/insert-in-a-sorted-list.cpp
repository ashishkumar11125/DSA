//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) 
    {
        // Code here
       
        Node *current = head, *prev = NULL;  // Initialize two pointers, 'current' and 'prev'.

         // Traverse the linked list until 'current' is not NULL and 'current->data' is less than 'data'.
        while (current != NULL && current->data < data) 
        {
            prev = current;  // Update 'prev' to point to the current node.
            current = current->next;  // Move 'current' to the next node.
        }

// Check if 'prev' is still NULL, indicating that the new node should be inserted at the beginning of the list.
        if (prev == NULL) 
        {
           prev = new Node(data);  // Create a new node with 'data'.
           prev->next = current;  // Set the next pointer of the new node to the current head.
           head = prev;  // Update the 'head' pointer to point to the new node.
        } 
// Check if 'current' is NULL, indicating that the new node should be inserted at the end of the list.
        else if (current == NULL)
        {
          prev->next = new Node(data);  // Create a new node with 'data' and make it the new last node.
        } 
// If 'data' should be inserted between two existing nodes.
        else
        {
          Node *temp = new Node(data);  // Create a new node with 'data'.
          temp->next = current;  // Set the next pointer of the new node to 'current'.
           prev->next = temp;  // Set the next pointer of 'prev' to the new node, effectively inserting it between 'prev' and 'current'.
        }

         return head;  // Return the updated head of the linked list.
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
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends