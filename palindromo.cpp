#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    // Removendo os espacos
    mensagem.erase(remove(mensagem.begin(), mensagem.end(), ' '), mensagem.end());

    // Verificando se e um palindromo
    string mensagemInvertida = mensagem;
    reverse(mensagemInvertida.begin(), mensagemInvertida.end());
    if (mensagem == mensagemInvertida) {
        cout << "A mensagem e um palindromo!" << endl;
    } else {
        cout << "A mensagem nao e um palindromo." << endl;
    }

    return 0;
}
