#include <iostream>

using namespace std;

struct Node {
    int info;
    Node *next;
};
typedef Node NODE;

NODE *insertEnd(NODE *head, int val) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->info = val;
    p->next = NULL;
    if(head == NULL) {
        head = p;
        return head;
    }
    NODE *q = head;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    return head;
}

NODE *insertStart(NODE *head, int val) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->info = val;
    p->next = head;
    head = p;
    return head;
}

NODE *insertAfter(NODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    NODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->info = val;
    p->next = q->next;
    q->next = p;
    return head;
}

NODE *insertBefore(NODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    NODE *q=head,*p=NULL;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    NODE *r = (NODE *)malloc(sizeof(NODE));
    r->info = val;
    r->next = q;
    if(p == NULL)
        head = r;
    else
            p->next = r;
    return head;
}

NODE *deletion(NODE *head, int key, bool isFirst=false) {
    if(head == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(isFirst) {
            NODE *p = head;
            head = head->next;
            free(p);
            return head;
        } else {
            NODE *q = head, *p = NULL;
            while(q->next != NULL) {
                p = q;
                q = q->next;
            }
            p->next = q->next;
            free(q);
            return head;
        }
    }
    NODE *q=head,*p=NULL;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == NULL) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(q == head) {
        head = head->next;
        free(q);
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

void display(NODE *head) {
    if(head == NULL) {
        cout<<"List is empty."<<endl;
        return ;
    }
    cout<<"List = ";
    NODE *q = head;
    while(q!=NULL) {
        cout<<q->info<<" ";
        q = q->next;
    }
}

int main() {
    NODE *head = NULL;
    int input,val,key;
    while(true) {
        cout<<"\n1. Create a linked list."<<endl;
        cout<<"2. Insert an element at the start of the linked list."<<endl;
        cout<<"3. Insert an element at the end of the linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a linked list."<<endl;
        cout<<"6. Delete the first element of the linked list."<<endl;
        cout<<"7. Delete the last element of the linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a linked list."<<endl;
        cout<<"9. Display list."<<endl;
        cout<<"10. quit."<<endl;
        cout<<"Enter your choice: ";
        cin>>input;
        switch(input) {
            case 1:
                head = NULL;
                cout<<"New list is created."<<endl;
                break;
            case 2:
                cout<<"Enter element to insert: ";
                cin>>val;
                head = insertStart(head,val);
                break;
            case 3:
                cout<<"Enter element to insert: ";
                cin>>val;
                head = insertEnd(head,val);
                break;
            case 4:
                cout<<"Enter element to insert: ";
                cin>>val;
                cout<<"Enter key before you want to insert: ";
                cin>>key;
                head = insertBefore(head,val,key);
                break;
            case 5:
                cout<<"Enter element to insert: ";
                cin>>val;
                cout<<"Enter key after you want to insert: ";
                cin>>key;
                head = insertAfter(head,val,key);
                break;
            case 6:
                cout<<"Action performed"<<endl;
                head = deletion(head,-1,true);
                break;
            case 7:
                cout<<"Action performed"<<endl;
                head = deletion(head,-1,false);
                break;
            case 8:
                cout<<"Enter key which you want to delete: ";
                cin>>key;
                head = deletion(head,key);
                break;
            case 9:
                display(head);
                break;
            case 10:
                return 0;
            default:
                cout<<"Enter number in between 1 to 10."<<endl;
        }
    }
}
