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

    int arr[10] = {6, 5, 4, 7, 3, 1, 8, 5, 9, 2};
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
    // 读取完毕 开始排序
    p = L.first;
    p = (*p).next;
    node *s, *t;
    while (p != NULL)
    {
        if ((*p).data < (*(*p).pre).data)
        {
            node *q;
            q = L.first;
            while ((*q).data <= (*p).data)
                q = (*q).next;
            // case 1 pass
            if ((*p).next == NULL && q == L.first)
            {
                s = (*p).pre;
                (*p).next = L.first;
                (*q).pre = p;
                (*(*p).pre).next = NULL;
                (*p).pre = NULL;
                L.first = p;
            }
            // case 2 pass
            else if ((*p).next == NULL && q != L.first)
            {
                s = (*p).pre;
                (*(*p).pre).next = NULL;
                (*p).pre = (*q).pre;
                (*(*q).pre).next = p;
                (*p).next = q;
                (*q).pre = p;
            }
            // case 3 pass
            else if (q == L.first && (*p).next != NULL)
            {
                s = (*p).next;
                (*(*p).pre).next = (*p).next;
                (*(*p).next).pre = (*p).pre;
                (*p).next = q;
                (*q).pre = p;
                (*p).pre = NULL;
                L.first = p;
            }
            // case 4
            else if (q != L.first && (*p).next != NULL)
            {
                s = (*p).next;
                (*(*p).next).pre = (*p).pre;
                (*(*p).pre).next = (*p).next;
                (*p).next = q;
                (*p).pre = (*q).pre;
                (*(*q).pre).next = p;
                (*q).pre = p;
            }
            cout << "Remove " << (*p).data << " :";
            p = s;
            t = L.first;
            while (t != NULL)
            {
                cout << " " << (*t).data;
                t = (*t).next;
            }
            cout << endl;
        }
        else
            p = (*p).next;
    }
    return 0;
}
