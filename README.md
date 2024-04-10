A class for linked list

First include `"linkedList.h"`.

Now you have to create a `linkedList<T>` object that refers to the start of the sequence of the linked objects.
```
linkedList<T>* start = new linkedList<T>(startValue);
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

2. void push_back(T last)

    This function adds a new value to the end of the sequence.

3. linkedList* push_front(T first)

    This function adds a new value to the beginning of the sequence, and returns the pointer of the new beginning.

4. void insert(int index, T value)
    This function adds a new value to the sequence, so after insertion, `T value` can be accessable with `int index`.
    You can get `invalid_argument` if `index` is less than 0, is equal to 0.
    This function has a `void` return type, so you can't add a new element to the beginning, since you can't access the pointer to the beginning.
    Instead, you should use `push_front` member function.
    Note that the function automatically insert enough objects with value as '0', to fulfill the first note about this function.

5. void remove