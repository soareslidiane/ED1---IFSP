#include <iostream>
using namespace std;

struct No {
	int dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

void enqueue(Fila *f, int v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else
	{
		f->fim->prox = no;
	}
	f->fim = no;
}

int dequeue(Fila *f) {
	int ret;
	No *no = f->ini;
	ret = no->dado;
	f->ini = no->prox;
	if (f->ini == NULL) {
		f->fim = NULL;
	}
	free(no);
	return ret;
}

int proxsenha(Fila *f) {
	int ret;
	No *no = f->ini;
	ret=no->dado;
	return ret;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "---------------------" << endl;
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
    return qtde;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
{
	bool menu=true;
	int opcao, senha=1;
	
	Fila *senhasGeradas, *senhasAtendidas;
	senhasGeradas=init();
	senhasAtendidas=init();
	
	cout<<"Bem vindo!"<<endl<<endl;
	while(menu==true)
	{
		cout << "---------------------" << endl;
		cout<<"*Senhas aguardando atendimento: "<<count(senhasGeradas)<<endl<<endl;
		cout<<"Selecione uma opcao:" << endl;
		cout<<"0. Sair"<<endl;
		cout<<"1. Gerar senha"<<endl;
		cout<<"2. Realizar atendimento"<<endl;
		cout<<endl<<"Digite a opcao desejada: ";
		
		cin>>opcao;
		
		while(!cin||opcao<0||opcao>2)
		{
			cin.clear();
			cin.ignore();
			cout<<"Opcao invalida! Digite um numero entre 0 e 2: ";
			cin>>opcao;
		}
		
		switch(opcao)
		{
		case 0:
			if(count(senhasGeradas)>0)
			{
				cout<<endl<<"Ainda ha "<<count(senhasGeradas)<<" pessoa(s) na fila! Realizar atendimento."<<endl;
			}
			else
			{
			cout<<endl<<"Total de atendimentos realizados: "<<count(senhasAtendidas)<<endl;
			cout<<endl<<"Obrigado e volte sempre!"<<endl;
			menu=false;
			}
			break;
		
		case 1:
			enqueue(senhasGeradas,senha);
			cout<<endl<<"Imprimindo senha numero "<<senha<<endl<<endl;
			senha++;
			break;
		
		case 2:
			if(count(senhasGeradas)==0)
			{
				cout<<endl<<"Nao ha pessoas na fila! Gerar nova senha."<<endl<<endl;
			}
			
			else
			{
				enqueue(senhasAtendidas,proxsenha(senhasGeradas));
				cout<<endl<<"Atendendo senha numero "<<dequeue(senhasGeradas)<<endl;
			}
			break;
		}
	}
	
	freeFila(senhasAtendidas);		
	return 0;
}