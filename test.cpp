#include<iostream>
#include<vector>

int main(){

    int a, b;
    std::vector<int> v;
    a = 10;
    std::cin >> b;
    v.push_back(a);
    v.push_back(b);
    std::cout << "a=" << a << " b=" << b << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << v[i] << std::endl;
    }

    return 0;
}