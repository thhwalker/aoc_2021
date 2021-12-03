#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> Array;

Array produce_input_array()
{
    Array input_array;
    string tmp;
    fstream input_file("input");
    while (input_file >> tmp) {
        input_array.push_back(tmp);
    }
    return input_array;
}

int main(int argc, char* argv[])
{
    Array data = produce_input_array();
    int half = data.size() / 2;
    int count[data[0].length()] = {0,};

    for (string num : data) {
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '1') {
                count[i] += 1;
            }
        }
    }

    string output_g, output_e;
    for (int i : count) {
        if (i > half) {
            output_g += '1';
            output_e += '0';
        } else {
            output_g += '0';
            output_e += '1';
        }
    }
    int gam_r = stoi(output_g, 0, 2);
    int eps_r = stoi(output_e, 0, 2);

    cout << "Answer 1: " << (gam_r * eps_r) << endl;    
}