#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
template <class T>
class linkedList
{
    public:
        T value;
        linkedList* next = 0;
        linkedList() {}
        linkedList(T value) : value(value) {}
        
        linkedList* setNext(T next)
        {
            linkedList* temp = new linkedList(next);
            this->next = temp;
            return this->next;
        }
        void push_back(T last)
        {
            linkedList* temp = this;
            while (temp->next != 0)
            {
                temp = temp->next;
            }
            temp->next = new linkedList(last);
        }
        linkedList* push_front(T first)
        {
            linkedList* temp = new linkedList(first);
            temp->next = this;
            return temp;
        }
        void insert(int index, T value)
        {
            if (index < 0)
                throw std::invalid_argument("Index cannot be negetive.");
            if (index == 0)
                throw std::invalid_argument("\"insert\" method has a void return. Use \"push_front\" to add a value to the beginning of the linkedList.");
            
            int i;
            linkedList* temp = pointerOf(index - 1, i);
            if (i < index - 1)
            {
                i = index - i;
                while (i--)
                    temp = temp->setNext(0);
            }

            linkedList* objAfterIndex = temp->next;
            temp->next = new linkedList(value);
            temp->next->next = objAfterIndex;
        }
        void remove(int index)
        {
            if (index < 0)
                throw std::invalid_argument("Index cannot be negetive.");
            if (index == 0)
                throw std::invalid_argument("\"remove\" method has a void return. Use \"startOfLinkedList = startOfLinkedList->next\" to remove the first element.");
            
            int i;
            linkedList* temp = pointerOf(index - 1, i);
            std::cout << std::endl << i << std::endl;
            if (temp->next == 0)
                throw std::out_of_range("Index out of range");
            temp->next = temp->next->next;
        }
        T valueAt(int index)
        {
            return pointerOf(index)->value;
        }
        linkedList* pointerOf(int index)
        {
            linkedList* temp = this;
            for (int i = 0; i < index; i++)
            {
                if (temp == 0)
                    return 0;
                temp = temp->next;
            }
            return temp;
        }
        int size()
        {
            linkedList* temp = this;
            int result = 1;
            while (temp->next != 0)
            {
                temp = temp->next;
                result++;
            }
            return result;
        }
    
    private:
        linkedList* pointerOf(int index, int& i)
        {
            linkedList* temp = this;
            for (i = 0; i < index && temp->next != 0; i++)
                temp = temp->next;
            return temp;
        }
    

    // static members
    public:
        static void print(linkedList* list, char seperator = ' ')
        {
            while (list->next != 0)
            {
                std::cout << list->value << seperator;
                list = list->next;
            }
            std::cout << list->value;
        }
};

#endif