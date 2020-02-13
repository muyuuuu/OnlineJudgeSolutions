#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string temp1, temp2, temp3, temp4;
    cin >> temp1 >> temp2 >> temp3 >> temp4;
    int day, hour, d;
    for (int i = 0; i < temp1.length(); i++)
    {
        if (temp1[i] >= 'A' && temp1[i] <= 'G' && temp1[i] == temp2[i])
        {
            day = temp1[i] - 'A' + 1;
            switch (day)
            {
                case 1: cout << "MON "; break;
                case 2: cout << "TUE "; break;
                case 3: cout << "WED "; break;
                case 4: cout << "THU "; break;
                case 5: cout << "FRI "; break;
                case 6: cout << "SAT "; break;
                case 7: cout << "SUN "; break;
            }
            d = i;
            break;
        }
    }
    for (int i = d + 1; i < temp1.length(); i++)
    {
        if (temp1[i] == temp2[i])
        {
            if ((temp1[i] >= '0' && temp1[i] <= '9') || (temp1[i] >= 'A' && temp1[i] <= 'N'))
            {
                if (temp1[i] <= '9')
                    hour = temp1[i] - '0';
                if (temp1[i] >= 'A')
                    hour = temp1[i] - 'A' + 10;
                printf("%02d", hour);
                break;
            }
        }
    }
    for (int i = 0; i < temp3.length(); i++)
    {
        if (temp3[i] == temp4[i] && isalpha(temp3[i]))
        {
            printf(":%02d", i);
            return 0;
        }
    }
    return 0;
}
