#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // Abrindo o arquivo com a lista de nomes
    ifstream infile("nomes.txt");

    // Verificando se o arquivo foi aberto corretamente
    if (!infile.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }

    // Abrindo o arquivo para escrita dos novos nomes
    ofstream outfile("nomes_formatados.txt");

    // Verificando se o arquivo foi aberto corretamente
    if (!outfile.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }

    // lendo cada linha do arquivo com os nomes
    string line;
    while (getline(infile, line)) {

        // Dividindo o nome
        vector<string> parts;
        string part;
        for (char c : line) {
            if (c == ' ') {
                parts.push_back(part);
                part.clear();
			}
            else {
                part += c;
            }
        }
        parts.push_back(part);

        // Organizando as partes do nome no formato desejado
        reverse(parts.begin(), parts.end());
        string formatted_name = parts[0] + ", ";
        for (int i = 1; i < parts.size() - 1; i++) {
            formatted_name += parts[i] + " ";
        }
        formatted_name += parts[parts.size() - 1];

        // Escrevendo o novo nome no arquivo
        outfile << formatted_name << endl;
    }

    // Fechando os arquivos
    infile.close();
    outfile.close();

    return 0;
}
