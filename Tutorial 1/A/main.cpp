#include <iostream>
#include "A.hpp"
using namespace std;


int main(){
    A x('1');
    A y('2');
    A z = x;

    z = y;
    y.show();

    return 0;
}