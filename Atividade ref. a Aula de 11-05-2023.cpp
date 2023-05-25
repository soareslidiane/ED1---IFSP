#include <iostream>
using  namespace std;

#define MAX 30

struct No {
	int num;
	struct No *prox;
};

struct PilhaEnc {
	No *topo;
};

PilhaEnc* initenc(){
	PilhaEnc *p = new PilhaEnc;
	p->topo = NULL;
	return p;
}

void pushenc(PilhaEnc *p, float v) {
	No *no = new No;
	no->num = v;
	no->prox = p->topo;
	p->topo = no;
}

int popenc(PilhaEnc *p) {
	int ret;
	No *no = p->topo;
	ret = no->num;
	p->topo = no->prox;
	free(no);
	return ret;
}

int countenc(PilhaEnc *p) {
	int qtde = 0;
	No *no;
	no = p->topo;
	while(no != NULL) {
        qtde++;   
		no = no->prox;
	}
	return qtde;
}

void printenc(PilhaEnc *p) {
	No *no;
	no = p->topo;
	while(no != NULL) {
		cout << no->num << endl;
		no = no->prox;
	}
	cout << "------------------------" << endl<<endl;
}

void freePilhaEnc(PilhaEnc *p) {
	No *no = p->topo;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(p);
}


struct PilhaVet {
	int qtde;
	int nos[MAX];
};

PilhaVet* initvet() {
	PilhaVet *p = new PilhaVet;
	p->qtde = 0;
	return p;
}

int countvet(PilhaVet *p) {
	return p->qtde;
}

int pushvet(PilhaVet *p, int v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->nos[p->qtde] = v;
		p->qtde++;
	}
	return podeEmpilhar;
}

int popvet(PilhaVet *p) {
	int ret;
	int podeDesempilhar = (p->qtde > 0);
	if (podeDesempilhar) {
		ret = p->nos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void printvet(PilhaVet *p) {
	for(int i = p->qtde-1; i >= 0; --i) {
		cout << p->nos[i] << endl;
	} 
	cout << "------------------" << endl<<endl;
}

void freePilhaVet(PilhaVet *p)
{
	free(p);
}


int main(int argc, char** argv)
{
	PilhaVet *todos;
	todos=initvet();
	PilhaEnc *par;
	par=initenc();
	PilhaEnc *impar;
	impar=initenc();
	
	int num=0, max=0, ver=0;
	
	while (max<MAX)
	{
		cout<<"Digite o "<<max+1<<" numero: "<<endl;
		cin>>num;
		max++;
		cout<<endl;
	while(!cin||num<=ver)
	{
		cin.clear();
		cin.ignore();
		cout<<"Numero invalido! Digite um numero inteiro a partir de "<<ver+1<<": ";
		cin>>num;
	}
	ver=num;
	if(num%2==0)
	{
		pushenc(par,num);
	}
	else
	{
		pushenc(impar,num);
	}
	pushvet(todos,num);
	}
	
	cout<<"-Numeros pares-"<<endl;
	cout<<"Quantidade de numeros pares: "<<countenc(par)<<endl;
	cout<<"Pilha de numeros pares:"<<endl;
	printenc(par);
	
	cout<<"-Numeros impares-"<<endl;
	cout<<"Quantidade de numeros impares: "<<countenc(impar)<<endl;
	cout<<"Pilha de numeros impares:"<<endl;
	printenc(impar);
	
	/*while(todos->qtde>0)
	{
	cout<<"Desempilhando o numero maior :"<<*todos->nos<<endl;
	popvet(todos);		
	}
	cout<<todos->qtde;*/
	
	while(todos->qtde>0)
	{
	cout<<"Retirando o numero maior da pilha: "<<popvet(todos)<<endl;		
	}
	
	cout<<"Total de numeros apos desempilhar: "<<countvet(todos)<<endl;
	
	freePilhaVet(todos);
	freePilhaEnc(par);
	freePilhaEnc(impar);
	
	return 0;
}