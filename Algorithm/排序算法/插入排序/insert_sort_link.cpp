#include <iostream>
#include <fstream>
#include <ctime>

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

int arr[1000002] = {0};
node ans[300002];

int main(int argc, char const *argv[])
{
    int len = 0;

    string path = "one_hundred_thousand.txt";
    string out = "one_hundred_thousand_link.txt";
    
    ifstream in(path.c_str());
    ofstream ou(out.c_str());
    
    if (!in.is_open())
    {
        cerr << "open file failed!" << endl;
        exit(-1);
    }

    if (!ou.is_open())
    {
        cerr << "create file failed!" << endl;
        exit(-1);
    }
    
    int a = 0;
    while (in >> a)
        arr[len++] = a;
    
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
    node *p;
    p = L.first;
    p = (*p).next;
    node *s;
    clock_t start = clock();
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
            p = s;
        }
        else
            p = (*p).next;
    }
    clock_t end = clock();
    cout <<  (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    in.close();
    p = L.first;
    while (p != NULL)
    {
        ou << (*p).data << endl;
        p = (*p).next;
    }
    ou.close();
    return 0;
}
