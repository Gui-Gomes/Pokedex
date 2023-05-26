#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct pokemon
{
    int id;
    string name;
    string pokemon_type1;
    string pokemon_type2;
};

//Função responsável pela formatação da impressão dos pokemons
void print_pokemons(pokemon p)
{
    cout << "*-----------------------------------------------------*" << endl;
    cout << "ID: " << p.id << endl;
    cout << "NAME: " << p.name << endl;
    if (p.pokemon_type2 != "NULL")
    {
        cout << "TYPE I: " << p.pokemon_type1 << endl;
        cout << "TYPE II: " << p.pokemon_type2 << endl;
    }
    else
        cout << "TYPE: " << p.pokemon_type1 << endl;
    cout << "*-----------------------------------------------------*" << endl;
}

int compare_pokemons(pokemon p1, pokemon p2)
{
    return p1.name.compare(p2.name);
}

//Função responsável por carregar os itens do arquivo.csv para a lista
template <typename T>
void read_database(list<T>& lst)
{
    fstream data;
    data.open("data/database.csv", ios::in);
    if (data.is_open())
        cout << "File opened successfully!" << endl << endl;
    else
        cout << "Error opening file!" << endl << endl;

    string line;
    while (getline(data, line))
    {
        stringstream ss(line);
        string id, name, type1, type2;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, type1, ',');
        getline(ss, type2, ',');

        append(lst, {stoi(id), name, type1, type2});
    }
    data.close();
}

template <typename T>
void save_on_database(list<T>& lst)
{
    fstream data;
    data.open("data/database.csv", ios::out);
    if (!data.is_open())
        cout << "Error saving file!" << endl << endl;
    else
    {
        node<T>* aux = lst.begin;
        for (int i = 0; i < lst.cont; i++)
        {
            string id = to_string(aux->data.id);
            string name = (aux->data).name;
            string type1 = (aux->data).pokemon_type1;
            string type2 = (aux->data).pokemon_type2;

            aux = aux->next;

            data << id << ",";
            data << name << ",";
            data << type1 << ",";
            data << type2 << ",\n";
        }
        cout << "Files saved successfully!" << endl << endl;
    }
    data.close();
}