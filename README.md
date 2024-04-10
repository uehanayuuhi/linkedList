no# linkedList
A class for linked list

First include `"linkedList.h"`.

Now you have to create a `linkedList<T>` object that refers to the start of the sequence of the linked objects.
```
linkedList<T>* const start = new linkedList<T>(startValue);
```

Please note that, if you use the default constructor to initialize the `start` object, `value` data member of the `linkedList` class will contains unexpected values.
There is no default value has written for `value` data member, so if you would like, you can change it to meet your needs.

After initialization of `start`, you can write a loop to add to the sequence of linked objects.
```
linkedList<T>* temp = start;
int tempValue;
for (int i = 1; i < inputCount; i++)
{
    cin >> tempValue;
    temp = temp->setNext(tempValue);
}
```
Obviously you can think of other ways to add the elements.


Member Functions:
1. linkedList* setNext(T next)

    This function sets the `next` member data of the current instance to the argument `next`, and then returns the `this->next`. 