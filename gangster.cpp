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

Gangster::Gangster() : id(Gangster::nb), inf(1), pers(""), connu(false) 
{
    Gangster::nb ++;
}

bool Gangster::getStatut() const
{
    return connu;
}


Personne Gangster::getPersonne() const
{
    if (getStatut() == false) throw InconnuException();
    else return pers;
}

void Gangster::setPersonne(const Personne& _pers)
{
    pers = _pers;
    connu = true;
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

void Famille::ajouter(Gangster* _gangster)
{
    membres.push_back(_gangster);
}

/*std::vector<Gangter*> sortVector(std::vector<Gangster*>_vect)
{
    std::vector<Gangster*> res;
    Gangster * min = _vect.at(0);
    for (std::vector<Gangster*>::iterator i=_vect.begin(); i!= _vect.end(); ++i)
    {
        if (**i < *min) min =
    }

    
}*/

void Famille::listePersonnes(std::ostream& ss)
{
    for (std::vector<Gangster*>::iterator i=membres.begin(); i!= membres.end(); ++i)
    {
        if((*i)->getStatut() == true)
        {
            ss << (*i)->getPersonne().getNom() << ", ";
        }    
    } 
}

