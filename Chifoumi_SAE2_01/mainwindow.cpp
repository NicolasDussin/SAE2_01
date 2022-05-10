#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bPierre,SIGNAL(clicked()),this,SLOT(jouerTourPierre()));
    connect(ui->bFeuille,SIGNAL(clicked()),this,SLOT(jouerTourFeuille()));
    connect(ui->bCiseaux,SIGNAL(clicked()),this,SLOT(jouerTourCiseaux()));
    connect(ui->bNouvellePartie,SIGNAL(clicked()),this,SLOT(nouvellePartie()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nouvellePartie()
{
    initCoups();
    initScores();
    ui->bPierre->setEnabled(true);
    ui->bFeuille->setEnabled(true);
    ui->bCiseaux->setEnabled(true);
}

void MainWindow::MAJScore()
{
    ui->lScoreJoueur->setText(QString::number(scoreJoueur));
    qDebug() << scoreJoueur;
    ui->lScoreMachine->setText(QString::number(scoreMachine));
    qDebug() << scoreMachine;
}

void MainWindow::determinerScore()
{
    switch (determinerGagnant())
    {
        case 'N':
            break;
        case 'J':
            scoreJoueur++;
            break;
        case 'M':
            scoreMachine++;
            break;
    }
}

void MainWindow::jouerCoupMachine()
{
    coupMachine=(genererUnCoup());
    if (coupMachine==MainWindow::pierre)
    {
        ui->lCoupMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));
    }

    else if (coupMachine==MainWindow::feuille)
    {
        ui->lCoupMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));
    }

    else if (coupMachine==MainWindow::ciseaux)
    {
        ui->lCoupMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png"));
    }
}

void MainWindow::jouerTourPierre()
{
    coupJoueur=pierre;
    ui->lCoupJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));
    jouerCoupMachine();
    determinerScore();
    MAJScore();
}

void MainWindow::jouerTourFeuille()
{
    coupJoueur=MainWindow::feuille;
    ui->lCoupJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));
    jouerCoupMachine();
    determinerScore();
    MAJScore();
}

void MainWindow::jouerTourCiseaux()
{
    coupJoueur=MainWindow::ciseaux;
    ui->lCoupJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png"));
    jouerCoupMachine();
    determinerScore();
    MAJScore();
}

        /// Getters
MainWindow::UnCoup MainWindow::getCoupJoueur() {
    return coupJoueur;
}

MainWindow::UnCoup MainWindow::getCoupMachine() {
    return coupMachine;
}

unsigned int MainWindow::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int MainWindow::getScoreMachine() {
    return scoreMachine;
}

char MainWindow::determinerGagnant()
{
    char gagnantARetourner;
    switch (coupJoueur)
            {
             case ciseaux://Le joueur a choisie Ciseau et va etre comparer avec le choix de l'ordinateur
                switch(coupMachine)
                {
                    case ciseaux:
                    gagnantARetourner = 'N';
                    break;
                    case feuille:
                    gagnantARetourner = 'J';
                    break;
                    case pierre:
                    gagnantARetourner = 'M';
                    break;
                    case rien :
                    gagnantARetourner = NULL;
                    break;
                }
                break;
              case pierre://Le joueur a choisie Pierre et va etre comparer avec le choix de l'ordinateur

                switch(coupMachine)
                {
                    case ciseaux :
                    gagnantARetourner = 'J';
                    break;
                    case feuille:
                    gagnantARetourner = 'M';
                    break;
                    case pierre:
                    gagnantARetourner = 'N';
                    break;
                    case rien :
                    gagnantARetourner = NULL;
                    break;
                }
                break;

               case feuille ://Le joueur a choisie Feuille et va etre comparer avec le choix de l'ordinateur
                switch(coupMachine)
                {
                    case ciseaux:
                    gagnantARetourner = 'M';
                    break;
                    case feuille:
                    gagnantARetourner = 'N';
                    break;
                    case pierre:
                    gagnantARetourner = 'J';
                    break;
                    case rien :
                    gagnantARetourner = NULL;
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

MainWindow::UnCoup MainWindow::genererUnCoup()
{
    MainWindow::UnCoup valeurGeneree;   // valeur à retourner
    unsigned int nbAleatoire;
    nbAleatoire = rand()%(4-1) + 1;
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = MainWindow::pierre;
        break;
    case 2 :
        valeurGeneree = MainWindow::feuille;
        break;
    case 3 :
        valeurGeneree = MainWindow::ciseaux;
        break;
    default:
        break;
    }
    return valeurGeneree;

}

        /// Setters

void MainWindow::setCoupJoueur(UnCoup p_coup) {
    coupJoueur=p_coup;
}

void MainWindow::setCoupMachine(UnCoup p_coup) {
    coupMachine = p_coup;
}

void MainWindow::setScoreJoueur(unsigned int p_score) {
    scoreJoueur = p_score;
}

void MainWindow::setScoreMachine(unsigned int p_score) {
    scoreMachine = p_score;
}

void MainWindow::majScores(char p_gagnant) {

}

void MainWindow::initScores() {
    scoreJoueur = 0;
    ui->lScoreJoueur->setText("0");
    scoreMachine = 0;
    ui->lScoreMachine->setText("0");
}

void MainWindow::initCoups() {
    setCoupJoueur(rien);
    ui->lCoupJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png"));
    setCoupMachine(rien);
    ui->lCoupMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png"));
}

