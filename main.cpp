#include "app/app.h"
#include "models/pokemon.h"
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <algorithm>
#include <string>

using namespace std;

int main (){
    // O Setlocale não está funcionando no meu terminal.
    setlocale(LC_ALL, "pt_BR.UTF-8");

    list <pokemon> Pokemons;
    pokemon Pokemon;

    read_database(Pokemons);
    presentationInitial();

    cout << "Seja bem-vindo à Pokédex programada pelos alunos:\n\nGabriel Emanuel, Caio Gabriel, Guilherme Gomes e João Gabriel.\n\n";
    
    int opcao, opcao2;
    do {
        cout << "Digite qual opção você deseja realizar nesse programa:\n\n";
        cout << "1. Adicionar um Pokémon\n2. Alterar um Pokémon\n3. Excluir um Pokémon\n4. Listar todos os Pokémons\n5. Pesquisar um pokémon\n6. Salvar os pokémon\n9. Sair do Programa\n\n";
        cin >> opcao;
        switch(opcao){
            case 1:
                system("cls");
                cout << "Digite o nome do Pokémon: ";
                cin >> Pokemon.name;
                transform(Pokemon.name.begin(), Pokemon.name.end(), Pokemon.name.begin(), ::toupper);
                cout << endl << "Digite o tipo 1 do Pokémon: ";
                cin >> Pokemon.pokemon_type1;
                transform(Pokemon.pokemon_type1.begin(), Pokemon.pokemon_type1.end(), Pokemon.pokemon_type1.begin(), ::toupper);
                cout << endl << "OBS: Caso não queira adicionar um segundo tipo, digite NULL" << endl;
                cout << "Digite o tipo 2 do Pokémon: ";
                cin >> Pokemon.pokemon_type2;
                transform(Pokemon.pokemon_type2.begin(), Pokemon.pokemon_type2.end(), Pokemon.pokemon_type2.begin(), ::toupper);
                cout << endl << "Digite o ID do Pokémon: ";
                cin >> Pokemon.id;
                append(Pokemons, Pokemon);
                cout << endl << "Pokémon adicionado com sucesso!" << endl << endl;
                break;
            case 2:
                system("cls");
                quicksort(Pokemons, 0, Pokemons.cont - 1);
                int id_2;
                print(Pokemons, print_pokemons);
                cout << "Digite o ID do Pokémon que você deseja alterar: ";
                cin >> id_2;
                cout << "Digite para mudar:\n1 - ID\n2 - Nome\n3 - Tipo 1 do Pokémon\n4 - Tipo 2 do Pokémon\n";
                edit_node_data(Pokemons, id_2, compare_by_id);
                break;
            case 3:
                system("cls");
                int id_3;
                quicksort(Pokemons, 0, Pokemons.cont - 1);
                print(Pokemons, print_pokemons);
                cout << "Digite o ID do Pokémon que você deseja remover: ";
                cin >> id_3;
                system("cls");
                remove_node(Pokemons, id_3, compare_by_id);
                print(Pokemons, print_pokemons);
                break;
            case 4:
                system("cls");
                cout << "Deseja listar todos os pokémons de qual forma?\n\n1. Por ordem alfabética\n2. Por ordem de ID na Pokédex\n\n";
                cin >> opcao2;
                if (opcao2 == 1){
                    bubble_sort(Pokemons, compare_pokemons);
                    cout << "Pokémons em ordem alfabética:" << endl;
                    print(Pokemons, print_pokemons);
                    cout << endl;
                }
                else if (opcao2 == 2){
                    quicksort(Pokemons, 0, Pokemons.cont - 1);
                    cout << "Pokémons em ordem de ID:" << endl;
                    print(Pokemons, print_pokemons);
                    cout << endl;
                }
                else {
                    cout << "Você digitou um valor inválido!\n";
                }
                break;
            case 5:
                system("cls");
                cout << "Deseja pesquisar um pokémon através de qual forma?\n\n1. Pelo nome\n2. Pelo ID da Pokédex\n\n";
                cin >> opcao2;
                if (opcao2 == 1){
                    string namePoke;
                    bubble_sort(Pokemons, compare_pokemons);
                    cout << "Insira o nome do pokémon a ser procurado: \n";
                    cin >> namePoke;
                    transform(namePoke.begin(), namePoke.end(), namePoke.begin(), ::toupper);
                    print_one_node(Pokemons, sequential_search(Pokemons, namePoke), print_pokemons);
                }
                else if (opcao2 == 2){
                    int id_5;
                    quicksort(Pokemons, 0, Pokemons.cont - 1);
                    cout << "Insira o ID do pokémon a ser procurado: \n";
                    cin >> id_5;
                    print_one_node(Pokemons, binary_search(Pokemons, 0, Pokemons.cont - 1, id_5, compare_by_id), print_pokemons);
                }
                else {
                    cout << "Você digitou um valor inválido!\n";
                };
                break;
            case 6:
                system("cls");
                save_on_database(Pokemons);
                cout << endl;
                break;
            case 9:
                return false;
                break;
            default:
                cout << "Você digitou um valor inválido!\n";
                break;
        }
        system("pause");
        system("cls");
    } while(true);
    clear_memory(Pokemons);
    return 0;
}