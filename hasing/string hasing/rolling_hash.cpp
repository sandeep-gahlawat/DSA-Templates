// Polynomial Rolling Algorithm
// We shall use Polynomial Rolling algorithm to generate a hash code from a string
//  input. It uses the following formula:
// hash = x₁*A⁰ + x₂*Aⁱ + x₃*A² ... xₙ*Aⁿ⁻ⁱ

#include<bits/stdc++.h>
using namespace std;
const int PRIME_CONST = 31;

int hashFunction(string key) {
    int hashCode = 0;
    for (int i = 0; i < key.length(); i++) {
        hashCode += key[i] * pow(PRIME_CONST, i);
    }
    return hashCode;
}

int main() {
    cout << hashFunction("abc") << endl;

    return 0;
}