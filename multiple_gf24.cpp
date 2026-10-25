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
    uint8_t value1 = string_to_bit(heso_dathuctoigian);
    uint8_t value2 = string_to_bit(hesoB) << 1;
    if (hesoB[0] == '1') return value1 ^ value2;
    else return value2;

}

unsigned int multiple_mod_result(string heso1, string heso2) {
    auto final_result = 0;
    for (int i = heso1.length(); i >= 0; i--) {
        char c = heso1[i];
        if (c == '1') {
            auto tmp = multiple_mod_single(heso2);
            final_result ^= tmp;
            heso2 = ToBinary(tmp);
        }
    }
    return final_result;
}


int main() {
    string hesodathucA, hesodathucB;
    hesodathucA = "00100110";
    hesodathucB = "10011110";
    //cin >> hesodathucA >> hesodathucB;
    //cout << ketqua_phepnhan("1", "10011110") << endl;

    cout << multiple_mod_result(hesodathucA, hesodathucB);

}