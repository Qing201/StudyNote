#include <string>
#include <iostream>
using namespace std;

int main(){
    string first_name, last_name;
    cout << "Please enter your first name: ";
    cin >> first_name;
    cout << "Please enter your last name: ";
    cin >> last_name;
    cout << '\n'
         << "Hello, "
         << first_name
         << " "
         << last_name
         << '\n';   

    return 0;
}