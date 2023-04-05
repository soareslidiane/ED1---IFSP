#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Data
{
	private: 	
	   int dia;
	   int mes;
	   int ano;	
	   
    public:
    	Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
    	void setDia(int dia)
    	{
			this->dia = dia;
		}
		void setMes(int mes)
    	{
			this->mes = mes;
		}
		void setAno(int ano)
    	{
			this->ano = ano;
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}
		string getData()
		{
		    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
		}
};

class Contato : public Data
{
	private:
		string email;
		string nome;
		string telefone;
		Data dtnasc;
		
		public:
			Contato(string email, string nome, string telefone, Data dtnasc)
			{
				this->email=email;
				this->nome=nome;
				this->telefone=telefone;
				this->dtnasc=dtnasc;
			}
			
			Contato()
			{
				this->email="a";
				this->nome="aa";
				this->telefone="aaa";
			}
			
			void setEmail(string email)
			{
				this->email=email;
			}			
			void setNome(string nome)
			{
				this->nome=nome;
			}			
			void setTelefone(string telefone)
			{
				this->telefone=telefone;
			}
			
			string getEmail()
			{
				return this->email;
			}
			string getNome()
			{
				return this->nome;
			}
			string getTelefone()
			{
				return this->telefone;
			}
			
			int getIdade(int dia1, int dia2, int mes1, int mes2, int ano1, int ano2)
			{
				int idade=ano1-ano2-1;
				if(mes1>mes2)
				{
					idade++;
				}
				else
				{
				if(mes1==mes2)
				{
					if(dia1>=dia2)
					{
						idade++;
					}
				}				
				}
				
				return idade;
			}
					
};

int main(int argc, char** argv)
{
	string email, nome, telefone;
	int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dia, mes, ano;
	
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	
    Data *hoje = new Data(timePtr->tm_mday, timePtr->tm_mon+1, timePtr->tm_year + 1900);
    cout << "Hoje eh " <<hoje->getData() << endl;
	cout<<endl;
    cout<<"*Cadastro de Contato*"<< endl;
	
	Contato *pessoa=new Contato();
	
	cout<<"Digite o e-mail do contato:";
	cin>>email;
	pessoa->setEmail(email);
	
	cout<<"Digite o nome do contato:";
	cin>>nome;
	pessoa->setNome(nome);
	
	cout<<"Digite o telefone do contato:";
	cin>>telefone;
	pessoa->setTelefone(telefone);
			
	cout<<"Digite o ano de nascimento do contato: ";
	cin>>ano;
	while(ano<1900 || ano>2023) {
		cin.clear();
		cin.ignore();
		cout<<"Ano invalido! Digite o ano (entre 1900 e 2023): ";
		cin>>ano;
	}
	pessoa->setAno(ano);
		
	cout<<"Digite o mes de nascimento do contato:";
	cin>>mes;
	while(mes<1 || mes>12) {
		cin.clear();
		cin.ignore();
		cout<<"Mes invalido! Digite o mes (entre 1 e 12): ";
		cin>>mes;
	}
	pessoa->setMes(mes);
		
	cout<<"Digite o dia de nascimento do contato:";
	cin>>dia;
	while(dia<1||dia>diasNoMes[(mes-1)]){
		cin.clear();
		cin.ignore();
		cout<<"Dia invalido! Digite o dia (entre 1 e "<<diasNoMes[(mes-1)]<<"): ";
		cin>>dia;
	}
	pessoa->setDia(dia);
	
	cout<<endl<<"-Dados do contato-"<<endl;
	cout<<"Email: "<<pessoa->getEmail()<<endl;
	cout<<"Nome: "<<pessoa->getNome()<<endl;
	cout<<"Telefone: "<<pessoa->getTelefone()<<endl;
	cout<<"Data nascimento: "<<pessoa->getData()<<endl;
	cout<<"Idade: "<<pessoa->getIdade(hoje->getDia(),pessoa->getDia(),hoje->getMes(),pessoa->getMes(),hoje->getAno(),pessoa->getAno())<<endl;

	return 0;
}