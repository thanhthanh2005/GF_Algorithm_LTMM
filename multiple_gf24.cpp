#include <iostream>
#include <cstdint>
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

unsigned int ketqua_phepnhan(string hesoA, string hesoB) {
    unsigned int value1 = 0;
    uint8_t value2 = string_to_bit(hesoB) << 1;
    return value2;

}

string toBinaryString(uint8_t num, int num_bits = 8) {
    string result = "";
    for (int i = num_bits - 1; i >= 0; i--) {
        // Dùng toán tử ba ngôi để nối ký tự '1' hoặc '0' vào chuỗi
        result += ((num >> i) & 1) ? '1' : '0';
    }
    return result;
}

int main() {
    string hesodathucA, hesodathucB;
    //cin >> hesodathucA >> hesodathucB;
    //cout << ketqua_phepnhan("1", "10011110") << endl;

    cout << toBinaryString(60);
    

}