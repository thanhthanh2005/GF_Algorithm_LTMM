#include <iostream>
#include <cstdint>
using namespace std;

const int max_degree = 4;
const string heso_dathuctoigian = "10011";  // m(x) = x^4 + x + 1

unsigned int string_to_bit(string bit_string) {
    unsigned int value_bit = 0;
    for (int i = 0; i < bit_string.length(); i++) {
        value_bit = ( value_bit << 1) | (bit_string[i] - '0');
    }
    return value_bit;
}

string NumToBinary(uint8_t num, int num_bits = 4) {
    string result = "";
    for (int i = num_bits - 1; i >= 0; i--) {
        result += ((num >> i) & 1) ? '1' : '0';
    }
    return result;
}

unsigned int multiple_mod_single(string coeff) {       // x.g(x) mod m(x)
    uint8_t value1 = 0x03;  // he so da thuc sau dich: 0011
    uint8_t value2 = (uint8_t)string_to_bit(coeff); 
    bool highest_bit = (value2 & 0x08) != 0;           // kiem tra bit dau tien cua da thuc sau khi nhan 
    value2 <<= 1;
    value2 &= 0x0F;            // giu lai 4 bit thap nhat
    if (highest_bit) {
        value2 ^= value1;
    }
    return value2;
}

unsigned int multiple_mod_result(string coeff_fx, string coeff_gx) {   // cong cac phan tu sau khi mod
    unsigned int final_result = 0;
    for (int i = coeff_fx.length() - 1; i >= 0; i--) {
        if (coeff_fx[i] == '1') {                                   // co 1 thi cong
            final_result ^= string_to_bit(coeff_gx);
        }
        unsigned int tmp = multiple_mod_single(coeff_gx);
        coeff_gx = NumToBinary(tmp);   
    }
    return final_result;
}

int main() {
    string coefficient_fx, coefficient_gx;
    coefficient_fx = "0110";  
    coefficient_gx = "1011";  
    cout << NumToBinary(multiple_mod_result(coefficient_fx, coefficient_gx));
}