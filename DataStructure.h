#include <iostream>
#include <stdlib.h>
typedef struct Node
{
    int Value;
    Node *Next;
} Node;
class SingularLinkedList
{
private:
    Node *First;

public:
    // Create the list
    SingularLinkedList()
    {
        this->First = nullptr;
    }
    //Create List with specified head
    SingularLinkedList(Node *x)
    {
        this->First = x;
    }
    // to get the first node
    Node *getFirst()
    {
        return First;
    }
    // Checks if the list is empty or not
    bool IsEmpty()
    {
        return (First == nullptr);
    }
    // Function to add a node in the beginning of the list
    void InsertFirst(int x)
    {
        Node *temp = new Node;
        if (!IsEmpty())
            temp->Next = First;
        else
            temp->Next = nullptr;
        temp->Value = x;
        First = temp;
    }
    // Function to show all Values in the list
    void ShowAll()
    {
        if (!IsEmpty())
        {
            Node *temp = new Node;
            temp = First;
            while (temp != nullptr)
            {
                if (temp->Next != nullptr)
                    std::cout << temp->Value << "->";
                else
                    std::cout << temp->Value;
                temp = temp->Next;
            }
        }
        else
        {
            std::cout << "List is Empty!" << std::endl;
        }
    }
    // Returns the number of nodes in a list
    int Size()
    {
        if (!IsEmpty())
        {
            int count;
            Node *temp = new Node;
            temp = First;
            while (temp != nullptr)
            {
                temp = temp->Next;
                count++;
            }
            return count;
        }
        else
        {
            return 0;
        }
    }
    // Function to find the node contain the value given as argument
    Node *Find(int x)
    {
        if (!IsEmpty())
        {
            Node *temp = new Node;
            temp = First;
            while (temp != nullptr)
            {
                if (temp->Value == x)
                    return temp;
                temp = temp->Next;
            }
            return nullptr;
        }
        else
            return nullptr;
    }
    // Function to add a node at the end of the list
    void InsertLast(int x)
    {
        if (!IsEmpty())
        {
            Node *Insert = new Node;
            Insert->Value = x;
            Insert->Next = nullptr;
            Node *temp = new Node;
            temp = First;
            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }

            temp->Next = Insert;
        }
        else
        {
            InsertFirst(x);
        }
    }
    // Function to add a node after a specified node
    void InsertAfter(int x, Node *y)
    {
        if (!IsEmpty())
        {
            if (y != nullptr)
            {
                Node *temp = new Node;
                temp->Value = x;
                temp->Next = y->Next;
                y->Next = temp;
            }
            else
            {
                InsertLast(x);
            }
        }
        else
        {
            return;
        }
    }
    // Function to delete the first node
    void DeleteFirst()
    {
        if (!IsEmpty())
        {
            Node *temp = new Node;
            temp = First;
            First = temp->Next;
            delete temp;
        }
        else
        {
            return;
        }
    }
    // Function to delete a node after a specified node
    void DeleteAfter(Node *x)
    {
        if (!IsEmpty())
        {
            Node *temp = new Node;
            temp = x->Next;
            x->Next = temp->Next;
            delete temp;
        }
        else
        {
            return;
        }
    }
    // Function to make the list pure(there is only one copy of each element)
    void PurgeList()
    {
        if (!IsEmpty())
        {
            Node *p = new Node;
            p = First;
            while (p != nullptr)
            {
                Node *q = new Node;
                q = p;
                while (q->Next != nullptr)
                {
                    if (p->Value == q->Next->Value)
                    {
                        DeleteAfter(q);
                    }
                }
            }
        }
    }
    // Function to reverse the list non-recursively
    void Reverse()
    {
        if (!IsEmpty() && First->Next != nullptr)
        {
            Node *prev = new Node;
            Node *next = new Node;
            Node *current = new Node;
            prev = nullptr;
            next = nullptr;
            current = First;
            while (current != nullptr)
            {
                next = current->Next; // Store the next node
                current->Next = prev; // Reverse the current node's pointer
                prev = current;       // Move prev one step forward
                current = next;       // Move current one step forward
            }
            First = prev;
        }
        else
        {
            return;
        }
    }
};
// Circular list class
class CircularLinkedList
{
private:
    Node *First;
    Node *Last;

public:
    Node *getFirst()
    {
        return First;
    }
    // Create the list
    CircularLinkedList()
    {
        this->First = nullptr;
    }
    // Checks if the list is empty or not
    bool IsEmpty()
    {
        return (First == nullptr);
    }
    // Function to show all Values in the list
    void ShowAll()
    {
        if (!IsEmpty())
        {
            Node *temp = new Node;
            temp = First;
            while (temp->Next != First)
            {
                std::cout << temp->Value << "\t";
                temp = temp->Next;
            }
            std::cout << temp->Value << std::endl;
        }
        else
        {
            std::cout << "List is Empty!" << std::endl;
        }
    }
    // Returns the number of nodes in a list
    int Size()
    {
        if (!IsEmpty())
        {
            int count;
            Node *temp = new Node;
            temp = First;
            while (temp->Next != First)
            {
                count++;
                temp = temp->Next;
            }
            return count;
        }
        else
        {
            return 0;
        }
    }
    // Function to find the node contain the value given as argument
    Node *Find(int x)
    {
        if (!IsEmpty())
        {
            Node *temp = new Node;
            temp = First;
            while (temp->Next != First)
            {
                if (temp->Value == x)
                    return temp;
                temp = temp->Next;
            }
            return nullptr;
        }
        else
            return nullptr;
    }
    // Function to add a node
    void Insert(int x)
    {
        Node *newNode = new Node;
        newNode->Value = x;
        newNode->Next = nullptr;
        if (!IsEmpty())
        {
            Node *temp = First;
            while (temp->Next != First)
            {
                temp = temp->Next;
            }
            temp->Next = newNode;
        }
        else
        {
            First = newNode;
        }
        newNode->Next = First;
    }
    // Function to insert an element after a node
    void InsertAfter(Node *x)
    {
        if (!IsEmpty() && x != nullptr)
        {
            Node *temp = new Node;
            x->Next = temp;
            temp->Next = x->Next->Next;
        }
        else
        {
            return;
        }
    }
    // Function to delete a node after a specified node
    void DeleteAfter(Node *x)
    {
        Node *temp = new Node;
        temp = x->Next;
        if (temp == First)
        {
            First = temp->Next;
            x->Next = temp->Next;
            delete temp;
            return;
        }
        else
        {
            x->Next = temp->Next;
            delete temp;
            return;
        }
    }
    // Function to make the list pure(there is only one copy of each element)
    void PurgeList()
    {
        if (!IsEmpty())
        {
            Node *p = new Node;
            p = First;
            while (p->Next != First)
            {
                Node *q = new Node;
                q = p;
                while (q->Next->Next != First)
                {
                    if (p->Value == q->Next->Value)
                    {
                        DeleteAfter(q);
                    }
                }
            }
        }
    }
};

class Queue {
    private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation (add an element to the rear)
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->Value = value;
        newNode->Next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->Next = newNode;
            rear = newNode;
        }
    }

    // Dequeue operation (remove an element from the front)
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Or throw an exception
        }

        Node* temp = front;
        int dequeuedValue = temp->Value;
        front = front->Next;

        if (front == nullptr) {
            rear = nullptr; // If the queue becomes empty, reset rear as well
        }

        delete temp;
        return dequeuedValue;
    }

    // Peek operation (view the front element without removing it)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            return -1; // Or throw an exception
        }
        return front->Value;
    }
    
    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }
    
    // Display the queue elements
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->Value << " ";
            current = current->Next;
        }
        std::cout << std::endl;
    }
    
    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->Next;
            delete temp;
        }
        rear = nullptr;
    }
};