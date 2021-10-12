#include <iostream>

// Two ways to do the same thing.


int main() {
    std::cout << "Hello World" << std::endl;
    moin();
    return (0);
}

using namespace std;
int moin() {
    cout << "Hello World1" << endl;
    return (0);
}


using namespace std;
int moin(int argc, char * argv[]) {
    cout << "Hello World1" << endl;
    return (0);
}