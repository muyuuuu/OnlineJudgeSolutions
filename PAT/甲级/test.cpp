#include <iostream>
#define lowbit(i) ((i) & (-i))

using namespace std;

int main(int argc, char const *argv[])
{   
    // int i = 10;
    for (int i = 0; i < 10; i++)
        cout << i << " " << lowbit(i) << endl;
}
