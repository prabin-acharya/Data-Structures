// learnt the explanation in C and tried to implement myself in C++ so lot of gibberish.
#include <iostream>
//#include<cstdlib>
using namespace std;

int main()
{
    int *list = new int[3];
    /*
    int *list=malloc(3*sizeof(int));
    We need to cast (int *) because there's no implicit conversion from void* to type * in C++.
    Note that this cast is not required in C and could potentially be dangerous to do so in C.
    It is a better idea to use new/delete instead of malloc/free in C++*/
    if (list == NULL)
    {
        return 1;
    } // A good idea is to check if the memory is available or not everytime you allocate some memory.

    list[0] = 0;
    list[1] = 1;
    list[2] = 2;

    // Here,
    int *temp = new int[4];
    if (temp == NULL)
    {
        return 1;
    }

    // copy integers from old array into new array.     //This can be replaced with int *tmp=realloc(list,4*sizeof(int));
    for (int i = 0; i < 3; i++) // in C but not a best idea to use realloc with new.
    {
        temp[i] = list[i];
    }
    temp[3] = 3;
    delete (list); // to here.
    list = temp;
    for (int i = 0; i < 4; i++)
    {
        cout << list[i] << endl;
    }
}
