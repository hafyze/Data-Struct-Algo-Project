#include <iostream>
#include <fstream>
using namespace std;

int main(){
std::ifstream input_file("text_input.txt");
std::string line;

while (std::getline(input_file, line)) {
    std::cout << line << std::endl;
}
input_file.close();

return 0;
}