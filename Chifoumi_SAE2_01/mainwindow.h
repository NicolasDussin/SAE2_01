#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum UnCoup {pierre, feuille, ciseaux, rien};
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void MAJScore();
    void determinerScore();
    void jouerCoupMachine();
    UnCoup getCoupJoueur();
        /* retourne le dernier coup joué par le joueur */
    UnCoup getCoupMachine();
        /* retourne le dernier coup joué par le joueur */
    unsigned int getScoreJoueur();
        /* retourne le score du joueur */
    unsigned int getScoreMachine();
        /* retourne le score de la machine */
    char determinerGagnant();
        /* détermine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
           en fonction du dernier coup joué par chacun d'eux */

public slots:
    void nouvellePartie();
    void jouerTourPierre();
    void jouerTourFeuille();
    void jouerTourCiseaux();

private:
    Ui::MainWindow *ui;
    UnCoup genererUnCoup();
    void setCoupJoueur(UnCoup p_coup);
        /* initialise l'attribut coupJoueur avec la valeur
           du paramètre p_coup */
    void setCoupMachine(UnCoup p_coup);
         /* initialise l'attribut coupmachine avec la valeur
           du paramètre p_coup */
    void setScoreJoueur(unsigned int p_score);
        /* initialise l'attribut scoreJoueur avec la valeur
           du paramètre p_score */
    void setScoreMachine(unsigned int p_score);
         /* initialise l'attribut coupMachine avec la valeur
           du paramètre p_score */

    // Autres modificateurs
     void majScores(char p_gagnant);
        /* Mise à jour des scores en fonction des règles de gestion actuelles :
            - 1 point pour le gagnant lorsqu'il y a un gagnant
            - 0 point en cas de match nul
        */
    void initScores();
        /* initialise à 0 les attributs scoreJoueur et scoreMachine
           NON indispensable */
    void initCoups();
        /* initialise à rien les attributs coupJoueur et coupMachine
           NON indispensable */


     ///* Attributs du Modèle
 private:
    unsigned int scoreJoueur;   // score actuel du joueur
    unsigned int scoreMachine;  // score actuel de la Machine
    UnCoup coupJoueur;          // dernier coup joué par le joueur
    UnCoup coupMachine;         // dernier coup joué par la machine
    QString chaineScoreJoueur;
    QString chaineScoreMachine;

};
#endif // MAINWINDOW_H
