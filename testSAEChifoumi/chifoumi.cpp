/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe métier (= modèle) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


    ///* ---- PARTIE MODèLE ---------------------------

Chifoumi::Chifoumi():
scoreJoueur(0),
scoreMachine(0),
coupJoueur(rien),
coupMachine(rien)
{}

Chifoumi::~Chifoumi()
{
    //dtor
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return scoreMachine;
}

char Chifoumi::determinerGagnant()
{
    char gagnantARetourner;
    switch (coupJoueur)
            {
             case ciseau://Le joueur a choisie Ciseau et va etre comparer avec le choix de l'ordinateur
                switch(coupMachine)
                {
                   case ciseau:
                    gagnantARetourner = 'N';
                    break;
                    case papier:
                    gagnantARetourner = 'J';
                    break;
                    case pierre:
                    gagnantARetourner = 'M';
                    break;
                    case rien:
                    break;
                }
                break;
              case pierre://Le joueur a choisie Pierre et va etre comparer avec le choix de l'ordinateur

                switch(coupMachine)
                {
                    case ciseau :
                    gagnantARetourner = 'J';
                    break;
                    case papier:
                    gagnantARetourner = 'M';
                    break;
                    case pierre:
                    gagnantARetourner = 'N';
                    break;
                    case rien:
                    break;
                }
                break;

               case papier ://Le joueur a choisie Feuille et va etre comparer avec le choix de l'ordinateur
                switch(coupMachine)
                {
                    case ciseau:
                 gagnantARetourner = 'M';
                 break;
                 case papier:
                 gagnantARetourner = 'N';
                 break;
                 case pierre:
                 gagnantARetourner = 'J';
                 break;
                 case rien:
                 break;
                }
                break;

                case rien ://Le joueur a choisie rien et va etre comparer avec le choix de l'ordinateur
                    switch(coupMachine)
                    {
                        case ciseau:
                        break;
                        case papier:
                        break;
                        case pierre:
                        break;
                        case rien:
                        break;
                     }
                        break;
            }

    return gagnantARetourner;
}

         ///* Méthodes utilitaires du Modèle

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
    return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    Chifoumi::UnCoup valeurGeneree;   // valeur à retourner
    unsigned int nbAleatoire;
    nbAleatoire = rand()%(4-1) + 1;
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = Chifoumi::pierre;
        break;
    case 2 :
        valeurGeneree = Chifoumi::papier;
        break;
    case 3 :
        valeurGeneree = Chifoumi::ciseau;
        break;
    default:
        break;
    }
    return valeurGeneree;
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    coupJoueur=p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    scoreJoueur = p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    scoreMachine = p_score;
}

void Chifoumi::majScores(char p_gagnant) {
    if (p_gagnant == 'M'){
        scoreMachine = scoreMachine +1;
    }
    else if (p_gagnant=='J'){
        scoreJoueur = scoreJoueur +1;
    }
    else{}
}

void Chifoumi::initScores() {
    scoreJoueur = 0;
    scoreMachine = 0;
}

void Chifoumi::initCoups() {
    coupJoueur = rien;
    coupMachine = rien;
}
