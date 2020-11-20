// NOM    : SPARROW
// PRENOM : Henry

#ifndef __gangster_hpp__
#define __gangster_hpp__

#include <string>
#include <iostream>
#include <vector>
#include <exception>


class Personne{
    std::string nom;

    public :
        Personne(std::string);
        std::string getNom() const;
        void setNom(std::string);
};

const Personne INCONNU("INCONNU");


class Gangster{
    protected :
        int id;
        int inf;
    public :
        Gangster();
        int getId() const;
        int getInfluence() const;

        static int nb;
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

#endif
