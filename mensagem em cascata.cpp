#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    // Recebendo a mensagem
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    // Centralizando a mensagem na linha 5
    int tamanhoMensagem = mensagem.length();
    int espacosAntes = (80 - tamanhoMensagem) / 2;
    for (int i = 0; i < espacosAntes; i++) {
        cout << " ";
    }
    cout << mensagem << endl;

    // Simulando a cascata 
    for (int i = 0; i < 15; i++) {
        Sleep(100); 
        system("cls"); 

        for (int j = 0; j < espacosAntes; j++) {
            cout << " ";
        }
        for (int j = 0; j < tamanhoMensagem; j++) {
            if (i == j) {
                cout << mensagem[j];
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    
	cout << mensagem;
    return 0;
    
}

