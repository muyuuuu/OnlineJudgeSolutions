#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
int getArrayLen(T& array)
{
  return (sizeof(array) / sizeof(array[0]));
}

int main()
{
	int a[] = {4, 4, 2, 9, 4, 5, 12, 7, 8, 9};
	int l = getArrayLen(a);
	cout << l <<endl;

	int nums[] = { 3, 1, 4, 1, 5, 9 };
    int* result = find( nums , nums + 5,3 );
    if( result == nums + 5 ) 
        cout<< "Did not find any number matching " << endl;
    else
         cout<< "Found a matching number: " << *result << endl;

	int *end = a + l - 1;
	cout << *end << endl;

	return 0;
}