#include <iostream>
using namespace std;


const int max_degree = 8;
const string heso_dathuctoigain = "100011011";

unsigned int string_to_bit(string heso) {
    unsigned int value_bit = 0;
    for (int i = 0; i < heso.length(); i++) {
        value_bit = ( value_bit << 1) | (heso[i] - '0');
    }
    return value_bit;
}

string ketqua_phepnhan(string hesoA, string hesoB) {
    return nullptr;
}

int main() {
    string hesodathucA, hesodathucB;
    //cin >> hesodathucA >> hesodathucB;
    cout << string_to_bit("1101");

}