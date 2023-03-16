   #include<iostream>
#include<stdio.h>
#include<iomanip>


using namespace std;
int main(){

    int a;
    int b;
    int opcao;
    int fileira;
    int poltrona;
    int lugar = 0;
    int faturamento = 0;
    

    bool poltronas[15][40];

    for ( a = 0; a< 15; ++a){
        for (b = 0; b< 40; ++b){
            poltronas[a][b] = true;
        }
    }
     do 
    {
        cout << "[0] Finalizar" << endl;
        cout << "[1] Reservar poltrona" << endl;
        cout << "[2] Mapa de Ocupacao" << endl;
        cout << "[3] Faturamento" << endl;

        cin >>opcao;

        if(opcao == 0){
            cout << endl
            <<"Finalizar aplicacao" << endl;
        }
       
        else if (opcao == 1){
            cout << endl
            << "O teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada." << endl;

            cout << "Selecione o numero da fileria que deseja de 1 a 15:";
            cin >> fileira;

            cout << "Selecione o numero da coluna que deseja de 1 a 40:";
            cin >> poltrona;

            if(poltronas[fileira][poltrona]){
                poltronas[fileira][poltrona] = true;

                if(fileira >= 1 && fileira <= 5 ){
                    faturamento += 50;
                }else if(fileira >= 6 && fileira <=10){
                    faturamento +=30;
                }else if(fileira >= 11 && fileira <= 15){
                    faturamento +=15;
                }

                lugar++;
                cout << endl
                << "Reserva realizada!!" << endl;
                
            } else{
                 poltronas[fileira][poltrona] = false;
                cout << endl
                <<"Poltrona jÃ¡ reservada" << endl;
            }
        }
    
        else if(opcao ==2)
        
        {
            for(a = 0; a < 15; ++a)
            {
                for(b =0; b <40; ++b)
                {
                    if (poltronas[a][b])
                    {
                    cout << "|.|";
                    }
                    else 
                    {
                    cout << "|#|";
                    }
                }
                cout << endl;
            }
        }
        
        else if(opcao == 3){
            
            cout << endl
            << "Poltronas Ocupadas : " << lugar;

            cout << endl
            <<"Faturamento total da bilheteria R$"<< setprecision(2)<< fixed << faturamento << endl;
        }

}while (opcao !=0);
return 0;
}
