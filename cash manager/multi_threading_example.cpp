#include <string>
#include <iostream>
#include <thread>
#include <cash_manager.h>

using namespace std;

// The function we want to execute on the new thread.

void thread1(void)
{
    dateAndTime now;

        setFgClr("L Cyan");
        Locate(59,0);
        cout << now.weekDay() << ", " << now.month() << " " << now.day() << ", " << now.year();
        Locate(59,1);
        cout << now.time12() << "\n\n";
        setFgClr("L Red");

    delay(2);

    thread1();
}

int main()
{
    // Constructs the new thread and runs it. Does not block execution.
    thread t1(thread1);

    string name;
    cout << "\n\n\n\nEnter your ________ Name:\n";
    cin >> name;

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();

    return 0;
}
