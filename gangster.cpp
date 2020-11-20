#include "gangster.hpp"

int Gangster::nb = 1;

Personne::Personne(std::string _nom) : nom(_nom)
{}

std::string Personne::getNom() const
{
    return nom;
}

void Personne::setNom(std::string _nom)
{
    nom = _nom;
}

Gangster::Gangster() : id(Gangster::nb), inf(1) 
{
    Gangster::nb ++;
}

int Gangster::getId() const
{
    return id;
}

int Gangster::getInfluence() const
{
    return inf;
}


Chef::Chef() : Gangster() 
{}

void Chef::commande(Gangster* _gangster)
{
    equipe.push_back(_gangster);

    if (equipe.size() == 1) 
    {
        inf = 10;
    }


    inf += _gangster->getInfluence();
}
