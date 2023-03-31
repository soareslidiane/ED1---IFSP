#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


std::string transforma_nome(std::string nome) {
    std::vector<std::string> partes;
    std::string parte;
    std::istringstream stream(nome);
    
    // Separando o nome em partes 
    while (std::getline(stream, parte, ' ')) {
        partes.push_back(parte);
    }
    
    // Transformando a ultima parte do nome em maiuscula
    partes.back() = partes.back().substr(0, 1) + partes.back().substr(1, partes.back().length()-1);
    
    // Abreviando as partes do meio do nome
    std::string nome_abreviado;
    for (auto i = partes.begin(); i != partes.end(); i++) {
        if (i == partes.begin()) {
            nome_abreviado += (*i).substr(0, 1) + (*i).substr(1, (*i).length()-1);
        } else if (i == partes.end() - 1) {
            nome_abreviado += " " + *i;
        } else {
            nome_abreviado += " " + (*i).substr(0, 1) + ".";
        }
    }
    
    // Colocando o sobrenome em maiuscula e abreviacao do nome
    std::string sobrenome = partes[partes.size() - 1];
    nome_abreviado = sobrenome + ", " + nome_abreviado;
    
    return nome_abreviado;
}

int main() {
    std::ifstream arquivo("nomes.txt");
    std::ofstream saida("nomes_formatados.txt");
    std::string nome;
    
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo" << std::endl;
        return 1;
    }
    
    // l cendoada nome do arquivo, formata e escreve no arquivo de saida
    while (std::getline(arquivo, nome)) {
        std::string nome_formatado = transforma_nome(nome);
        saida << nome_formatado << std::endl;
    }
    
    arquivo.close();
    saida.close();
    
    return 0;
}
