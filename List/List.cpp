#include <iostream>

using namespace std;

class MyLinkedList {
    class Node {
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(NULL) {};
    };

    Node* head;

public:
    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        if (!head) {
            return -1;
        }
        Node* temp = head;
        int i = 0;
        for (; temp != NULL && i < index; i++) {
            temp = temp->next;
        }

        if (temp) {
            return temp->val;
        }
        else {
            return -1;
        }
    }

    void addAtHead(int val) {
        Node* cur = new Node(val);
        cur->next = head;
        head = cur;
    }

    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        Node* cur = new Node(val);
        temp->next = cur;
    }

    void addAtIndex(int index, int val) {
        if (!index) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        int i = 1;
        for (; temp != NULL && temp->next != NULL && i < index; i++) {
            temp = temp->next;
        }

        if (temp==NULL || i != index) {
            return;
        }
        if (temp->next == NULL) {
            addAtTail(val);
            return;
        }

        Node* cur = new Node(val);
        cur->next = temp->next;
        temp->next = cur;
    }

    void deleteAtIndex(int index) {
        Node* temp;
        if (!index) {
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        temp = head;
        int i = 1;
        for (; temp->next != NULL && i < index; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            return;
        }

        Node* cur = temp->next;;

        temp->next = temp->next->next;
        delete cur;
    }
};


int main()
{
    MyLinkedList* obj = new MyLinkedList();
    /*obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    cout<< obj->get(1);
    obj->deleteAtIndex(1);
    cout<< obj->get(1);*/
   /* obj->addAtIndex(0, 10);
    obj->addAtIndex(0, 20);
    obj->addAtIndex(1, 30);
    cout << obj->get(0);*/

  /*  obj->addAtHead(4);
    cout << obj->get(1);
    obj->addAtHead(1);
    obj->addAtHead(5);
    obj->deleteAtIndex(3);
    obj->addAtHead(7);
    cout << obj->get(3);
    cout << obj->get(3);
    cout << obj->get(3);
    obj->addAtHead(1);
    obj->deleteAtIndex(4);*/

    obj->addAtIndex(1, 0);
    cout << obj->get(0);
}
