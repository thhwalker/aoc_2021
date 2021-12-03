#include <iostream>
#include <fstream>

using namespace std;

int part_one() 
{
    string command;
    int value, depth = 0, position = 0;

    ifstream input_file("input");
    while (input_file >> command >> value) {
        if(command=="forward"){
            position += value;
        }else if(command=="up"){
            depth -= value;
        }else if(command=="down"){
            depth += value;
        }else{
            cout << "error?" << endl;
        }
    }
    return depth * position;
}

int part_two() 
{
    string command;
    int value, depth = 0, position = 0, aim = 0;

    ifstream input_file("input");
    while (input_file >> command >> value) {
        if(command=="forward"){
            position += value;
            depth += (value * aim);
        }else if(command=="up"){
            aim -= value;
        }else if(command=="down"){
            aim += value;
        }else{
            cout << "error?" << endl;
        }
    }
    return depth * position;
}

int main(int argc, char* argv[])
{
    cout << "Answer 1 is: " << part_one() << endl;
    cout << "Answer 2 is: " << part_two() << endl;
}