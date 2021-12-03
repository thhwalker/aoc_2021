#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> produce_input_array()
{
    vector<int> input_array;
    int tmp;
    fstream input_file("input");
    while (input_file >> tmp) {
        input_array.push_back(tmp);
    }
    return input_array;
}

int part_one(vector<int> input_array)
{
    int cnt = 0;
    for (int i = 1; i < input_array.size(); i++) {
        if (input_array[i-1] < input_array[i]) {
            cnt += 1;
        }
    }
    return cnt;
}

int part_two(vector<int> input_array)
{
    int cnt = 0;
    for (int i = 3; i < input_array.size(); i++) {
        int prev = input_array[i-3] + input_array[i-2] + input_array[i-1];
        int cur = input_array[i-2] + input_array[i-1] + input_array[i];
        if (prev < cur) {
            cnt += 1;
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) 
{
    vector<int> test_input = {199,200,208,210,200,207,240,269,260,263};
    vector<int> input = produce_input_array();

    cout << "This should be 7: " << part_one(test_input) << endl;
    cout << "This should be 5: " << part_two(test_input) << endl;

    cout << "The answer to part one is: " << part_one(input) << endl;
    cout << "The answer to part two is: " << part_two(input) << endl;
}