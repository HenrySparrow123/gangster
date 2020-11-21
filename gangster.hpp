// NOM    : SPARROW
// PRENOM : Henry

#ifndef __gangster_hpp__
#define __gangster_hpp__

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <sstream>


class Personne{
    std::string nom;

    public :
        Personne(std::string);
        std::string getNom() const;
        void setNom(std::string);

        void operator=(const Personne& _pers)
        {
            nom = _pers.getNom();
        };

        bool equals(const Personne& _pers) const
        {
            if (nom == _pers.getNom()) return true;
            else return false;
        }
};

const Personne INCONNU("INCONNU");

class Gangster{
    protected :
        int id;
        int inf;
        Personne pers;
        bool connu;
    public :
        Gangster();
        int getId() const;
        int getInfluence() const;
        Personne getPersonne() const;
        void setPersonne(const Personne&);
        bool getStatut() const;

        static int nb;

        bool operator<(const Gangster& _gangster) const
        {
            bool res = false;
            if (inf == _gangster.getInfluence())
            {
                if (id > _gangster.getId()) res = true;
            }
            else
            {
                if(inf < _gangster.getInfluence()) res = true;
            }
            return res;
        };
};

class Chef : public Gangster {

    public :
        Chef();
        void commande(Gangster*);
    std::vector<Gangster*> equipe;
};

class InconnuException : public std::exception
{
    
    public :
        virtual const char * what() const noexcept
        {
            return "personnalite inconnue";
        }
};

class Famille
{
    std::vector<Gangster*> membres;

    public :
        void ajouter(Gangster*);
        void listePersonnes(std::ostream&);

};

#endif
