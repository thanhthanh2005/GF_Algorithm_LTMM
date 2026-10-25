#include <iostream>
#include <cstdint>
using namespace std;

const int max_degree = 8;
const string heso_dathuctoigian = "100011011";

unsigned int string_to_bit(string heso) {
    unsigned int value_bit = 0;
    for (int i = 0; i < heso.length(); i++) {
        value_bit = ( value_bit << 1) | (heso[i] - '0');
    }
    return value_bit;
}

string ToBinary(uint8_t num, int num_bits = 8) {
    string result = "";
    for (int i = num_bits - 1; i >= 0; i--) {
        result += ((num >> i) & 1) ? '1' : '0';
    }
    return result;
}

unsigned int multiple_mod_single(string hesoB) {       // x.g(x) mod m(x)
    uint8_t value1 = 0x1B;  // he so da thuc sau dich: 00011011
    uint8_t value2 = (uint8_t)string_to_bit(hesoB); 


    bool highest_bit = (value2 & 0x80) != 0;

    value2 <<= 1;

    if (highest_bit) {
        value2 ^= value1;
    }

    return value2;

}

unsigned int multiple_mod_result(string heso1, string heso2) {
    unsigned int final_result = 0;
    for (int i = heso1.length() - 1; i >= 0; i--) {
        if (heso1[i] == '1') {
            final_result ^= string_to_bit(heso2);
        }
        unsigned int tmp = multiple_mod_single(heso2);
        heso2 = ToBinary(tmp);   
    }
    return final_result;
}

int main() {
    string hesodathucA, hesodathucB;
    hesodathucA = "00100110";  // f(x) = x^5 + x^2 + x
    hesodathucB = "10011110";  // g(x) = x^7 + x^4 + x^3 + x^2 + x
    //cin >> hesodathucA >> hesodathucB;
    //cout << ketqua_phepnhan("1", "10011110") << endl;
    cout << ToBinary(multiple_mod_result(hesodathucA, hesodathucB));

}