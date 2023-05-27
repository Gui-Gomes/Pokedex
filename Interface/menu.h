#include "app/app.h"
#include "models/pokemon.h"
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main (){
    // O Setlocale não está funcionando no meu terminal.
    setlocale(LC_ALL, "Portuguese");
    cout << "Seja bem-vindo à Pokédex programada pelos alunos:\n\nGabriel Emanuel, Caio Gabriel, Guilherme Gomes e João Gabriel.\n\n";
    int opcao, opcao2;
    do {
        cout << "Digite qual opção você deseja realizar nesse programa:\n\n1. Adicionar um Pokémon\n2. Alterar um Pokémon\n3. Excluir um Pokémon\n4. Listar todos os Pokémons\n5. Pesquisar um pokémon\n9. Sair do Programa\n\n";
        cin >> opcao;
        switch (opcao){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "Deseja listar todos os pokémons de qual forma?\n\n1. Por ordem alfabética\n2. Por ordem de ID na Pokédex\n\n";
                cin >> opcao2;
                if (opcao2 == 1){

                }
                else if (opcao2 == 2){

                }
                else {
                    cout << "Você digitou um valor inválido!\n";
                }
                break;
            case 5:
                cout << "Deseja pesquisar um pokémon através de qual forma?\n\n1. Pelo nome\n2. Pelo ID da Pokédex\n\n";
                cin >> opcao2;
                if (opcao2 == 1){

                }
                else if (opcao2 == 2){

                }
                else {
                    cout << "Você digitou um valor inválido!\n";
                }
                break;
                break;
            case 9:
                return false;
                break;
            default:
                cout << "Você digitou um valor inválido!\n";
                break;
        }
        system("cls");
    } while(true);
    return 0;
}