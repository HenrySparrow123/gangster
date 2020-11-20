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
    std::cout << "Here first ? " << std::endl;
    std::cout << "id =  " <<id<< std::endl; 

    std::cout << "nb =  " << Gangster::nb<< std::endl; 

    
    std::cout << "Creation ... " << std::endl; 
    Gangster::nb = id + 1;
}

int Gangster::getId() const
{
    return id;
}

int Gangster::getInfluence() const
{
    return inf;
}


Chef::Chef() : id(Gangster::nb), inf(1) 
{}

void Chef::commande(Gangster* _gangster)
{
    equipe.push_back(_gangster);
    if (! equipe.size()) inf += 10;


    inf += _gangster->getInfluence();


}


void Chef::commande(Chef* _gangster)
{
    equipe.push_back(_gangster);
    if (! equipe.size()) inf += 20;


    inf = inf + _gangster->getInfluence();

}

int Chef::getId() const
{
    return id;
}

int Chef::getInfluence() const
{
    return inf;
}

