#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

template <typename T>
struct node
{
    T data;
    node<T>* previous = NULL;
    node<T>* next = NULL;
};

template <typename T>
struct list
{
    node<T>* begin = NULL;
    node<T>* end = NULL;
    int cont = 0;
};

//Função responsável por adicionar pokemons a lista.
template <typename T>
void append(list<T>& lst, T value)
{
    node<T>* new_data = new node<T>;
    new_data->data = value;
    if (lst.cont == 0)
        lst.begin = lst.end = new_data;
    else
    {
        lst.end->next = new_data;
        lst.end = new_data;
    }
    lst.cont++;
}

//Função responsável por limpar a memória.
template <typename T>
void clear_memory(list<T>& lst)
{
    while (lst.cont > 0)
    {
        node<T>* aux = lst.end;
        lst.end = lst.end->previous;
        delete aux;
        lst.cont--;
    }
    lst.begin = lst.end = NULL;
}

//Função responsável por selecionar um nó da lista.
template <typename T>
node<T>* get_node(list<T>& lst, int position)
{
    if (position < 0 || position > lst.cont - 1)
        throw invalid_argument("Invalid position!");
    node<T>* aux = lst.begin;
    for (int i = 0; i < position; i++)
        aux = aux->next;
    return aux;
}

//Função responsável por remover um item da lista.
//Apresenta um bug que remove os itens anteriores.
template <typename T>
void remove_node(list<T>& lst, int position)
{
    if (position < 0 || position >= lst.cont)
    {
        cout << "Invalid position!" << endl << endl;
    }
    node<T>* aux = get_node(lst, position);
    if (aux->next != NULL)
        aux->next->previous = aux->previous;
    else
        lst.end = aux->previous;
    if (aux->previous != NULL)
        aux->previous->next = aux->next;
    else
        lst.begin = aux->next;
    delete aux;
    lst.cont--;
}

//Função responsável por imprimir os itens da lista.
template <typename T>
void print(list<T>& lst, void(*print_function)(T))
{
    node<T>* aux = lst.begin;
    for (int i = 0; i < lst.cont; i++)
    {
        print_function(aux->data);
        aux = aux->next;
    }
}

//Função responsável por trocar itens na lista.
template<typename T>
void swap_nodes(list<T>& lst, int position1, int position2)
{
    node<T>* node1 = get_node(lst, position1);
    node<T>* node2 = get_node(lst, position2);
    T aux = node1->data;
    node1->data = node2->data;
    node2->data = aux;
}

template <typename T>
void bubble_sort(list<T>& lst, int(*sort_function)(T,T))
{
    bool sort = false;
    while (!sort)
    {
        sort = true;
        for (int i = 1; i < lst.cont; i++)
        {
            node<T>* node1 = get_node(lst, i - 1);
            node<T>* node2 = get_node(lst, i);
            if (sort_function(node1->data, node2->data) > 0)
            {
                sort = false;
                swap_nodes(lst, i, i - 1);
            }
        }
    }
}

//Função quicksort responsável por organizar a lista em ordem de ID;
template <typename T>
void quicksort(list<T>& lst, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int pivotIndex = left + (right - left) / 2;
        node<T>* pivotNode = get_node(lst, pivotIndex);
        while (i <= j)
        {
            while (get_node(lst, i)->data.id < pivotNode->data.id)
                i++;
            while (get_node(lst, j)->data.id > pivotNode->data.id)
                j--;
            if (i <= j)
            {
                swap_nodes(lst, i, j);
                i++;
                j--;
            }
        }
        if (left < j)
            quicksort(lst, left, j);
        if (i < right)
            quicksort(lst, i, right);
    }
}