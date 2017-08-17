#include <iostream>
using namespace std;

/* stack: All of your local variables take up memory from the stack. (predetermined memory)
   The heap: Unused program memory that can be used when the program runs to dynamically allocate (runtime memory) */
int main()
{
    int *p = new int; // allocates a memory for int in the heap and that's memory address is stored in p.

    *p = 5; // stores the integer 5 in the allocated memory (*p is now alias for 5 that is stored on heap).

    cout << *p; // let's assume that after printing *p (5) it's no more needed in the program further.
                // the problem is that compiler or language only manages stack's memory but not heap.
                // so once the heap allocated memory is utilized completely it better be deleted to avoid memory loss.

    delete p; // this frees up memory p is pointing towards. But remember the pointer p is not deleted. Now p points to
             // an arbitrary location and it's called a dangling pointer.

    // sometimes when the pointer is declared it's better to assign it with the value NULL whose value is 0, ex:

    int *a = NULL;

    return 0;
}
