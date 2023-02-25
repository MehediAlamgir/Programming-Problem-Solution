#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct Node{
    int key;
    Node* next;
};

void reverseList(Node* head)
{
    Node* current = head;
    Node *prev = nullptr, *next = nullptr;

    while(current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

void deleteNthNode(Node* head, int position)
{
    Node *temp1 = head;
    if (position == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }

    for(int i=0;i<position-2;i++)
        temp1 = temp1->next;

    //now temp1 points to (n-1)th node

    Node* temp2 = temp1->next; // n-th Node

    temp1->next = temp2->next;

    delete temp2;

}

/*
     Intersection of two Sorted Linked Lists
     (find common element of 2 linked list)

    //Hashing

    https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
*/


vector<int> intersection(Node* list1, Node* list2)
{
    vector<int>res;
    unordered_set<int> s;

    while(list1 != nullptr)
    {
        s.insert(list1->key);
        list1 = list1->next;
    }

    int cnt = 0;
    while(list2 != nullptr)
    {
        if (s.find(list2->key) != s.end())
        {
            res[cnt] = list2->key;
            cnt++;
        }
        list2 = list2->next;
    }

    return res;
}


//Get Intersection node of Two Linked Lists
 Node *getIntersectionNode(Node *headA, Node *headB) {
        unordered_map<Node*, int>listValue;
        while(headA != nullptr)
        {
            listValue[headA]++;
            headA = headA->next;
        }

        while(headB != nullptr)
        {
            if(listValue.count(headB)>0)
                return headB;
            headB = headB->next;
        }

        return nullptr;
}

//Detect cycle
bool hasCycle(ListNode *head) {
        while(head != nullptr)
        {
            if (head->val == INT_MIN)
                return true;
            head->val = INT_MIN;
            head = head->next;
        }

        return false;
}

//Cycle detection using Two pointer approach
bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

             if (slow == fast)
                return 1;

            /*
                // this is for finding the start of the loop
                if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                    return slow; // loop starts from this node
                }
            */
        }

        return 0;
}


//find middle element of a linked list
void printMiddle(Node *head){
        Node *slow_ptr = head;
        Node *fast_ptr = head;

        if (head!=NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->key << "]" << endl;
        }
}

//Delete duplicate elements from a linked list which is not sorted

void deleteDuplicates(Node* head)
{
    unordered_set<int>listValue;
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr)
    {
        if (listValue.find(current->key) != listValue.end())
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else
        {
            listValue.insert(current->key);
            prev = current;
            current = current->next;
        }
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout<<endl;
}

/*
//Reverse Doubly LinkedList using Recursion

Node* reverseDoublyLL(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if (head->prev == nullptr)
        return head;

    return reverseDoublyLL(head->prev);

}
*/


int main()
{
    Node* head = new Node{1, new Node{2, new Node{3, new Node{2, new Node{4, nullptr}}}}};
    cout << "Original list: ";
    printList(head);

    deleteDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
