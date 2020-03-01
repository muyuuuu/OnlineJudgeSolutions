#include <iostream>

using namespace std;

struct node
{
    node *pre;
    int data;
    node *next;
};

struct head
{
    node *first;
    int len = 0;
};

int main(int argc, char const *argv[])
{
    int arr[10] = {3, 5, 4, 7, 1, 6, 8, 5, 9, 2};
    int len = 10;
    node ans[len];
    head L;
    for (int i = 0; i < len; i++)
    {
        ans[i].data = arr[i];
        if (i == 0)
        {
            L.first = &ans[i];
            ans[i].next = &ans[i + 1];
        }
        else if (i == len - 1)
        {
            ans[i].pre = &ans[i - 1];
            ans[i].next = NULL;
        }
        else
        {
            ans[i].pre = &ans[i - 1];
            ans[i].next = &ans[i + 1];
        }
        L.len++;
    }
    cout << "The length of link is : " << L.len << endl;
    node *p;
    p = L.first;
    cout << endl << "Raw Data : ";
    while (p != NULL)
    {
        cout << (*p).data << " ";
        p = (*p).next;
    }
    cout << endl;
    
    return 0;
}
