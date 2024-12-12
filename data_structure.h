#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <iostream>
#include <string>

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;

    Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class data_structure
{
private:
    Node<T>* head;

public:
    data_structure() : head(nullptr) {}

    ~data_structure()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Add(const T& item)
    {
        Node<T>* newNode = new Node<T>(item);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T>* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void Delete(const std::string& name)
    {
        Node<T>* current = head;
        while (current)
        {
            if (current->data.getName() == name)
            {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                delete current;
                return;
            }
            current = current->next;
        }
        std::cout << "Surah " << name << " not found.\n";
    }

    bool Search(const std::string& name) const
    {
        Node<T>* current = head;
        while (current)
        {
            if (current->data.getName() == name)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    Node<T>* getHead() const
    {
        return head;
    }

};

#endif // DATA_STRUCTURE_H
