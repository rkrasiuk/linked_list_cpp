// linked list implementation
// my solution submissions from hackerrank
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
}

// printing the elements of a linked list
void Print(Node *head) {
    while(head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }
}

// inserting a Node at the tail of a linked list
Node* InsertTail(Node *head,int data) {
    Node* node = new Node();
    node->data = data;
    if(head==nullptr) {
        head = node;
        return head;
    }
    Node* linker = head;
    while(linker->next!=nullptr)
        linker = linker->next;
    linker->next = node;
    return head;
}

// inserting a Node at the head of a linked list
Node* InsertHead(Node *head,int data) {
    Node* node = new Node();
    node->data = data;
    node->next = head;
    return node;
}

// inserting a Node at a specific position in a linked list
Node* InsertNth(Node *head, int data, int position) {
    Node* node = new Node;
    node->data = data;
    if(position == 0) {
        node->next = head;
        return node;
    }
    Node* curr = head;
    for(int i = 1; i < position; i++) {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = node;
    node->next = temp;
    return head;
}

// deleting a Node
Node* Delete(Node *head, int position) {
    if(position == 0) 
        return head->next;
    Node* curr = head;
    for(int i = 1; i < position; i++)
        curr = curr->next;
    curr->next = curr->next->next;
    return head;
}

// printing elements in a reverse order
void ReversePrint(Node *head) { 
  string s;
  while(head != nullptr) {
      s = to_string(head->data) + '\n' + s;
      head = head->next;
  }
  cout << s;
}

// reversing a linked list
Node* Reverse(Node *head) {
  Node* next = head->next;
  head->next = nullptr;
  while(next != nullptr) {
      Node* curr = next;
      next = next->next;
      curr->next = head;
      head = curr;
  }
  return head;
}

// comparing two linked lists
int CompareLists(Node *headA, Node* headB) {
  while(headA != nullptr && headB != nullptr) {
      if(headA->data != headB->data)
          return 0;
      headA = headA->next; headB = headB->next;
  }
  if(headA == nullptr ^ headB == nullptr)
      return 0;
    return 1;
}

// merging two sorted linked lists
Node* MergeLists(Node *headA, Node* headB) {
    if(headA == nullptr)
        return headB;
    if(headB == nullptr)
        return headA;
    Node* head = (headA->data <= headB->data) ? headA : headB;
    Node* curr = head;
    if(head == headA)
        headA = headA->next;
    else headB = headB->next;
    while(headA != nullptr && headB != nullptr) {
        if(headA->data <= headB->data) {
            curr->next = headA;
            headA = headA->next;
        } else {
            curr->next = headB;
            headB = headB->next;
        }
        curr = curr->next;
    }
    while(headA != nullptr) {
        curr->next = headA;
        headA = headA->next;
        curr = curr->next;
    }
    while(headB != nullptr) {
        curr->next = headB;
        headB = headB->next;
        curr = curr->next;
    }
    return head;
}

// getting node value with position from tail
int GetNode(Node *head,int positionFromTail) {
    Node* it = head;
    int length = 0;
    while(it!=nullptr) {
        it = it->next;
        length++;
    }
    it = head;
    int pos = 0;
    while(pos<length-positionFromTail-1) {
        it = it->next;
        pos++;
    }
    return it->data;
}

// removing duplicates from sorted linked list
Node* RemoveDuplicates(Node *head) {
    Node *curr = head->next, *prev = head;
    while(curr!=nullptr) {
        if(curr->next==nullptr && prev->data == curr->data)
            prev->next = nullptr;
        if(curr->data == prev->data)
            curr = curr->next;
        else {
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

// cycle detection
bool has_cycle(Node* head) {
    if(head == nullptr)
        return false;
    Node *tortoise = head, *hare = head;
    while(hare != nullptr && hare->next != nullptr) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(hare == tortoise)
            return true;
    }
    return false;
}

