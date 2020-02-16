#include <iostream>
#include <vector>

using namespace std;

vector<string> hand;
vector<string> eye;
vector<string> mouse;

int main(int argc, char const *argv[])
{
    string str[4];
    getline(cin, str[1]);
    getline(cin, str[2]);
    getline(cin, str[3]);
    string temp = "";
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < str[i].length(); j++)
        {
            if (str[i][j] == '[')
            {
                j += 1;
                while (str[i][j] != ']')
                {
                    temp += str[i][j];
                    j++;
                }
                if (i == 1)
                    hand.push_back(temp);
                if (i == 2)
                    eye.push_back(temp);
                if (i == 3)
                    mouse.push_back(temp);
                temp = "";
            }
        }
    }
    int n;
    cin >> n;
    int flag = 0;
    int value;
    string result = "";
    cin.get();
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a < 1 || b < 1 || c < 1 || d < 1 || e < 1 || a > hand.size() || e > hand.size() || b > eye.size() || d > eye.size() || c > mouse.size())
        {
            cout << "Are you kidding me? @\\/@" << endl;
            continue;     
        }
        else
        {
            cout << hand[a-1] << "(" << eye[b-1] <<  mouse[c-1] << eye[d-1] << ")" << hand[e-1] << endl;
        }
    }
    return 0;
}
