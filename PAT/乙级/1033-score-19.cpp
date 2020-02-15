#include <iostream>

using namespace std;

int arr[42] = {0};

int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.length(); i++){
        if (isdigit(str1[i]))
            arr[str1[i] - '0'] = 1;
        else if (isalpha(str1[i])){
            if (str1[i] >= 'A' && str1[i] <= 'Z')
                str1[i] += 32;
            arr[10 + str1[i] - 'a'] = 1;
        }
        else if (str1[i] == '_')
            arr[36] = 1;
        else if (str1[i] == ',')
            arr[37] = 1;
        else if (str1[i] == '.')
            arr[38] = 1;
        else if (str1[i] == '-')
            arr[39] = 1;
        else if (str1[i] == '+')
            arr[40] = 1;
    }
    
    for (int i = 0; i < str2.length(); i++){
        if (isdigit(str2[i]) && arr[str2[i] - '0'] == 0)
            cout << str2[i];
        else if (isalpha(str2[i]))
            if (str2[i] >= 'A' && str2[i] <= 'Z' && arr[40] == 0)
                if (arr[str2[i] + 32 - 'a' + 10] == 0)
                    cout << str2[i];
            if (str2[i] >= 'a' && str2[i] <= 'z' && arr[10 + str2[i] - 'a'] == 0)
                cout << str2[i];
        else if (str2[i] == '_' && arr[36] == 0)
            cout << "_";
        else if (str2[i] == ',' && arr[37] == 0)
            cout << ",";
        else if (str2[i] == '.' && arr[38] == 0)
            cout << ".";
        else if (str2[i] == '-' && arr[39] == 0)
            cout << "-";
        else if (str2[i] == '+' && arr[40] == 0)
            cout << "+";
    }
    return 0;
}
