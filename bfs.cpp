/*
    Matheus Catalan Ferreira - 210419
    Daniel Maffi - 209862

    Atividade: Busca em profudindade em arvora de multiplos nós
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Tree
{
    int value;
    list<int> *node;

public:
    Tree(int value);
    void addNode(int v, int w);
    void BFS(int s);
};

Tree::Tree(int value)
{
    this->value = value;
    node = new list<int>[value];
}

void Tree::BFS(int current)
{
    std::string cities[20] = {
        "oradea",
        "arad",
        "Zenrid",
        "Timisora",
        "Lugoj",
        "Medahia",
        "Dobreta",
        "Sibiu",
        "Rimnicu",
        "Pitesti",
        "Craiova",
        "Fagaras",
        "Bucharest",
        "Girguiu",
        "Urzeceni",
        "Hirsova",
        "Eforie",
        "Valui",
        "Lasi",
        "Neamt",
    };
    bool *cheked = new bool[value];
    list<int> tmp;
    tmp.push_back(current);
    list<int>::iterator i;

    for (int i = 0; i < value; i++)
        cheked[i] = false;

    cheked[current] = true;

    while (!tmp.empty())
    {
        current = tmp.front();

        // cities[current] mostra as cidade corrente de onde esta expandindo a busca
        // cities[*i] mostra a cidade que esta visando apartir da cidade corrente
        // apenas esta fazendo a percurso de expansão, não esta retornando o melhor caminho, nem procurando um determinado index'

        cout << "Expandindo: " << cities[current] << "\n";
        tmp.pop_front();

        for (i = node[current].begin(); i != node[current].end(); ++i)
        {
            if (!cheked[*i])
            {
                cheked[*i] = true;
                tmp.push_back(*i);
            }
            printf("Visitando: %s\n", cities[*i].c_str());
            // cout << node[current];
        }
    }
}

void Tree::addNode(int v, int w)
{
    node[v].push_back(w);
}

int main()
{
    Tree tree(20);

    // conexões para o arad
    tree.addNode(0, 1);
    tree.addNode(0, 7);

    // conexões para o arad
    tree.addNode(1, 2);
    tree.addNode(1, 7);
    tree.addNode(1, 3);

    // conexões para o zenrid
    tree.addNode(2, 0);
    tree.addNode(2, 1);

    // conexões para o timissora
    tree.addNode(3, 1);
    tree.addNode(3, 4);

    // conexões para o lugoj
    tree.addNode(4, 3);
    tree.addNode(4, 5);

    // conexões para o Medahia
    tree.addNode(5, 4);
    tree.addNode(5, 6);

    // conexões para o Dobreta
    tree.addNode(6, 5);
    tree.addNode(6, 10);

    // conexões para o Sibiu
    tree.addNode(7, 0);
    tree.addNode(7, 1);
    tree.addNode(7, 8);
    tree.addNode(7, 11);

    // conexões para o Rimnicu
    tree.addNode(8, 7);
    tree.addNode(8, 9);
    tree.addNode(8, 10);

    // conexões para o Pitesti
    tree.addNode(9, 8);
    tree.addNode(9, 10);
    tree.addNode(9, 12);

    // conexões para o Craiova
    tree.addNode(10, 6);
    tree.addNode(10, 8);
    tree.addNode(10, 7);

    // conexões para o Fagaras
    tree.addNode(11, 7);
    tree.addNode(11, 12);

    // conexões para o Bucharest
    tree.addNode(12, 9);
    tree.addNode(12, 11);
    tree.addNode(12, 13);
    tree.addNode(12, 14);

    // conexões para o Giurgiu

    // conexões para o Urzeceni
    tree.addNode(14, 15);
    tree.addNode(14, 12);

    tree.addNode(14, 17);

    // conexões para o Hirsova
    tree.addNode(15, 14);
    tree.addNode(15, 16);

    // conexões para o Eforie
    tree.addNode(16, 15);

    // conexões para o Vaslui
    tree.addNode(17, 14);
    tree.addNode(17, 18);

    // conexões para o Lasi
    tree.addNode(18, 17);
    tree.addNode(18, 19);

    // conexões para o Neamt
    tree.addNode(19, 18);

    /*
        oradea - 0
        arad - 1
        Zenrid - 2
        Timisora - 3
        Lugoj - 4
        Medahia - 5
        Dobreta - 6
        Sibiu - 7
        Rimnicu Vilcea - 8
        Pitesti - 9
        Craiova - 10
        Fagaras - 11
        Bucharest - 12
        Girguiu - 13
        Urzeceni - 14
        Hirsova - 15
        Eforie - 16
        Valui - 17
        Lasi - 18
        Neamt - 19

    */

    tree.BFS(1);

    return 0;
}