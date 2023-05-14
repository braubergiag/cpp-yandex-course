//
// Created by igor on 13.05.23.
//

#ifndef CPP_YANDEX_COURSE_LINKEDLIST_H
#define CPP_YANDEX_COURSE_LINKEDLIST_H
template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList(){
        while (head) PopFront();

    };

    void PushFront(const T& value) {
        Node * node = new Node{value,nullptr};
        if (!head) {
            head = node;
        }
        else {
            auto old_head = head;
            head = node;
            node->next = old_head;
        }
    }
    void InsertAfter(Node* node, const T& value){
        if (node)
        {
            Node * new_node = new Node{value,node->next};
            node->next = new_node;
        } else
            PushFront(value);

    }
    void RemoveAfter(Node* node){
        if (node)
        {
            if (node->next){
                auto new_next = node->next->next;
                delete node->next;
                node->next = new_next;
            } else
                return;
        } else
            PopFront();


    }
    void PopFront() {
        if (!head) return;
        auto new_head = head->next;
        delete head;
        head = new_head;
    }

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};

#endif //CPP_YANDEX_COURSE_LINKEDLIST_H
