#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>
 
int main(){

    std::map<int, int> m1, m2;
    for (int i = 1; i < 18; i++) {
        m1[i] = i;
    }

    std::map<int, int>::iterator it1, it2;
    it1 = m1.lower_bound(11);
    it2 = m1.upper_bound(17);

    std::cout << it2->first << "==" << it2->second << std::endl;

    return 0;
}
