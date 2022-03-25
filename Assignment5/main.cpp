#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    int myArray[5];

    ifstream file("d:\\ints.txt");
    if(file.is_open())
    {
        for(int i = 0; i < 5; ++i)
        {
            file >> myArray[i];
        }
    }
    for(int i = 0; i < 5; i++){
        std::cout<<myArray[i];
    }

}