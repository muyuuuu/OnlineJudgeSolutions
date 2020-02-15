#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    float a, b;
    cin >> a >> b;
    if (b - a < 100)
    {
        if (b - a >= 50)
            printf("00:00:01");
        else
            printf("00:00:00");
        return 0;
    }
    int c = int((b - a) / 100 + 0.5);
    int hour = c / 3600;
    c = c - 3600 * hour;
    int minute = c / 60;
    c = c - 60 * minute;
    int second = c;
    printf("%02d:%02d:%02d", hour, minute, second);
    return 0;
}
