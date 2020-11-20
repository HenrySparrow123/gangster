// NOM    : SPARROW
// PRENOM : Henry

#ifndef __gangster_hpp__
#define __gangster_hpp__

#include <string>
#include <iostream>
#include <vector>


class Personne{
    std::string nom;

    public :
        Personne(std::string);
        std::string getNom() const;
        void setNom(std::string);
};

const Personne INCONNU("INCONNU");


class Gangster{
    int id;
    int inf;
    public :
        Gangster();
        virtual int getId() const;
        virtual int getInfluence() const;

        static int nb;
};

class Chef : public Gangster {
    int id;
    int inf;
    std::vector<Gangster*> equipe;

    public :
        Chef();
        void commande(Gangster*);
        void commande(Chef*);
        virtual int getId() const;
        virtual int getInfluence() const;
};


#endif
