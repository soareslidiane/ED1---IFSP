#include <iostream>
using namespace std;

struct No {
    int dado;
    struct No* prox;
};

struct Fila {
    No* ini;
    No* fim;
};

struct Guiche {
    int id;
    Fila* senhasAtendidas;
};

Fila* initFila() {
    Fila* f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

Guiche* initGuiche(int id) {
    Guiche* g = new Guiche;
    g->id = id;
    g->senhasAtendidas = initFila();
    return g;
}

int isEmpty(Fila* f) {
    return (f->ini == NULL);
}

void enqueue(Fila* f, int v) {
    No* no = new No;
    no->dado = v;
    no->prox = NULL;
    if (isEmpty(f)) {
        f->ini = no;
    }
    else {
        f->fim->prox = no;
    }
    f->fim = no;
}

int dequeue(Fila* f) {
    int ret;
    No* no = f->ini;
    ret = no->dado;
    f->ini = no->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    delete no;
    return ret;
}

int proxsenha(Fila* f) {
    int ret;
    No* no = f->ini;
    ret = no->dado;
    return ret;
}

void print(Fila* f) {
    No* no;
    no = f->ini;
    while (no != NULL) {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "---------------------" << endl;
}

int count(Fila* f) {
    int qtde = 0;
    No* no;
    no = f->ini;
    while (no != NULL) {
        qtde++;
        no = no->prox;
    }
    return qtde;
}

void freeFila(Fila* f) {
    No* no = f->ini;
    while (no != NULL) {
        No* temp = no->prox;
        delete no;
        no = temp;
    }
    delete f;
}

void freeGuiche(Guiche* g) {
    freeFila(g->senhasAtendidas);
    delete g;
}

int main(int argc, char** argv)
{
    bool menu = true;
    int opcao, senha = 1;
    int guichesAbertos = 0;

    Fila* senhasGeradas = initFila();
    Guiche* guiches[10];

    cout << "Bem vindo!" << endl << endl;
    while (menu == true)
    {
        cout << "---------------------" << endl;
        cout << "*Senhas aguardando atendimento: " << count(senhasGeradas) << endl;
        cout << "*Numero de guiches abertos: " << guichesAbertos << endl << endl;
        cout << "Selecione uma opcao:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Abrir guiche" << endl;
        cout << "3. Realizar atendimento" << endl;
        cout << "4. Listar senhas atendidas" << endl;
        cout << endl << "Digite a opcao desejada: ";

        cin >> opcao;

        while (!cin || opcao < 0 || opcao > 4)
        {
            cin.clear();
            cin.ignore();
            cout << "Opcao invalida! Digite um numero entre 0 e 4: ";
            cin >> opcao;
        }

        switch (opcao)
        {
        case 0:
            if (count(senhasGeradas) > 0)
            {
                cout << endl << "Ainda ha " << count(senhasGeradas) << " clientes na fila! Realizar atendimento." << endl;
            }
            else
            {
                cout << endl << "Total de atendimentos realizados: " << count(guiches[0]->senhasAtendidas) << endl;
                cout << endl << "Obrigado!" << endl;
                menu = false;
            }
            break;

        case 1:
            enqueue(senhasGeradas, senha);
            cout << endl << "Imprimindo senha numero " << senha << endl << endl;
            senha++;
            break;

        case 2:
            if (guichesAbertos == 10) {
                cout << endl << "Limite maximo de guiches atingido!" << endl;
            }
            else {
                guiches[guichesAbertos] = initGuiche(guichesAbertos + 1);
                guichesAbertos++;
                cout << endl << "Guiche " << guichesAbertos << " aberto!" << endl;
            }
            break;

        case 3:
            if (count(senhasGeradas) == 0)
            {
                cout << endl << "Nao ha pessoas na fila! Gerar nova senha." << endl << endl;
            }
            else
            {
                int idGuiche;
                cout << "Digite o ID do guiche que esta chamando a senha: ";
                cin >> idGuiche;

                if (idGuiche < 1 || idGuiche > guichesAbertos) {
                    cout << "Guiche invalido!" << endl;
                }
                else {
                    enqueue(guiches[idGuiche - 1]->senhasAtendidas, proxsenha(senhasGeradas));
                    cout << endl << "Atendendo senha numero " << dequeue(senhasGeradas) << " no guiche " << idGuiche << endl;
                }
            }
            break;

        case 4:
            int idGuiche;
            cout << "Digite o ID do guiche para listar as senhas atendidas: ";
            cin >> idGuiche;

            if (idGuiche < 1 || idGuiche > guichesAbertos) {
                cout << "Guiche invalido!" << endl;
            }
            else {
                cout << endl << "Senhas atendidas no guiche " << idGuiche << ":" << endl;
                print(guiches[idGuiche - 1]->senhasAtendidas);
            }
            break;
        }
    }

    for (int i = 0; i < guichesAbertos; i++) {
        freeGuiche(guiches[i]);
    }
    freeFila(senhasGeradas);
    return 0;
}