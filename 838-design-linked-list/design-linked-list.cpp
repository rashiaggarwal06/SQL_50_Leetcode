class MyLinkedList {
public:
    // Create a structure of the linked list
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) {
            val = x;
            next = NULL;
        }
    };
    // create head for list
    ListNode* head;

    // Initialize function with head NULL
    MyLinkedList() { head = NULL; }

    int get(int index) {
        // Create a pointer curr to iterate over the list
        ListNode* curr = head;
        // iterate until we reach the index we need
        while (curr != NULL && index > 0) {
            curr = curr->next;
            index--;
        }
        // If curr is null after reaching, means we have no value after that in
        // list so return -1
        if (curr == NULL)
            return -1;
        // Otherwise return the value of that node
        return curr->val;
    }

    void addAtHead(int val) {
        // Here index is 0, we have to add a node at the head position
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        // If head is NULL, return the newNode we created as head of the list
        if(head == NULL){
            head = newNode;
            return;
        }
        //Iterate until the curr's next gets null and add the new Node at that position 
        ListNode* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        //If we have to add node at index 0, call the function addAtHead and pass value to it
        if(index == 0){
            addAtHead(val);
            return;
        }
        ListNode* curr = head;
        //Iterate over the list until we reaches the index position
        while (curr != NULL && index > 1) {
            curr = curr->next;
            index--;
        }
        //Check if curr is NULL, if yes return, otherwise add the newNode's next as curr's next and make curr's next as newNode
        if (curr == NULL)
            return;
        ListNode* newNode = new ListNode(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        //If head is NULL, return
        if (head == NULL)
            return;
        //If we have to delete at index = 0
        if (index == 0) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = NULL;
            delete tmp;
            return;
        }
        ListNode* curr = head;
        //Iterate over the list until we reaches the index position
        while (curr->next != NULL && index > 1) {
            curr = curr->next;
            index--;
        }
        //Check if curr is NULL or its next is NULL, if yes return
        if (curr == NULL || curr->next == NULL)
            return;
        //Otherwise, create a tmp pointer and set it on a node we have to delete, make a link between curr's next and curr's next's next and delete tmp too so that the memory can free
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */