//realizado por: Herson Giron, 2025
#include <iostream>
using namespace std;
int main() {
    int digito;
    cout << "Ingrese un digito:"<<endl;
    cin >> digito;

    cout << "El digito invertido es:"<<endl;
    while (digito > 0) {
        cout << digito % 10;
        digito = digito / 10;
    }
    return 0;
}
