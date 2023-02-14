#include <iostream>
#include <string>
using namespace std;

int main(){
    string bin1, bin2;

    // accepts the 2 binary string into bin1 and bin2
    cin >> bin1 >> bin2;

    // check if the binary size if greaterthan 1
    if(bin1.length() <= 1 || bin2.length() <= 1) cout << "0000";
    else{
        // string to store the result
        string result;
        // boolean variable to store the result's sign 
        bool isNeg = bin1[0] != bin2[0];

        // reset the sign bit on bot```h binary string to zero
        bin1[0] = '0';
        bin2[0] = '0';

        // covert the binary strings to int and multiplying them 
        int product = stoi(bin1) * stoi(bin2);

        // loop to clear the carry the value
        int carry = 0;
        while(product > 0 || carry > 0){
            int digit = product % 10;
            int sum = digit + carry;
            result = ((sum % 2)? '1': '0') + result;
            carry = sum / 2; 
            product /= 10;
        }

        cout << isNeg << result;
    }

    return 0;
}