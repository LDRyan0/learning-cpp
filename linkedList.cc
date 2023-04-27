#include <iostream>
struct node { 
    int data;
    node *next;
};

class LinkedList { 
    private:
        node *head, *tail; // can't access head and tail publicly
    public:
        LinkedList() { 
            head = NULL;
            tail = NULL;
        }

        void addStart(int n) { 
            node *tmp = new node;
            tmp->data = n;
            tmp->next = head; // can be NULL if empty
            if (head==NULL) { 
                head = tmp;
                tail = tmp;
            } else { 
                head = tmp;
            }
        }

        void addEnd(int n) { 
            node *tmp = new node; // allocating space for required node by new operator
            tmp->data = n;
            tmp->next = NULL;
            
            if (head==NULL) { 
                head = tmp;
                tail = tmp;
            } else { 
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void print() { 
            node *cur = head;
            while (cur != NULL) { 
                std::cout << cur->data << " -> ";
                cur = cur->next;
            }
            std::cout << "\n";
        }
};

int main() {
    LinkedList a;

    int num = 10;

    for(int i = 0; i < num; ++i) { 
        a.addEnd(i);
        a.print();
    } 

    for(int i = num; i < 2*num; ++i) { 
        a.addStart(i);
        a.print();
    } 


    return 0;
}