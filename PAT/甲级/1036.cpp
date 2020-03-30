#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    string name;
    string gender;
    string id;
    int grade;
};

vector<node> vf;
vector<node> vm;

int cmpm(node a, node b)
{
    return a.grade < b.grade;
}

int cmpf(node a, node b)
{
    return a.grade > b.grade;
}

int main(int argc, char const *argv[])
{
    int n, flagm = 0, flagf = 0;
    cin >> n;
    node temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
        if (temp.gender == "M") 
            vm.push_back(temp);
        if (temp.gender == "F") 
            vf.push_back(temp);
    }
    if (vm.size() != 0)
    {
        sort(vm.begin(), vm.end(), cmpm);
        flagm = 1;
    }
    if (vf.size() != 0)
    {
        flagf = 1;
        sort(vf.begin(), vf.end(), cmpf);
    }
    if (flagf == 1) 
        cout << vf[0].name << " " << vf[0].id << endl;
    else
        cout << "Absent" << endl;
    if (flagm == 1)
         cout << vm[0].name << " " << vm[0].id << endl;
    else
        cout << "Absent" << endl;
    if (flagm == 0 || flagf == 0)
        cout << "NA";
    else
        cout << vf[0].grade - vm[0].grade;
    
    return 0;
}
