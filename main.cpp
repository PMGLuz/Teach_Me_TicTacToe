#include "tictactoe_gui.h"
#include <QApplication>
#include <QProcess>
#include <QMessageBox>
#include <QPushButton>


int whoStarts()
{

    QMessageBox *startBox= new QMessageBox;
    startBox->setText("Who plays with circle?");

    QAbstractButton *buttonYes = startBox->addButton("Human", QMessageBox::YesRole);
    startBox->addButton("CPU", QMessageBox::NoRole);

    startBox->exec();

    if(startBox->clickedButton()==buttonYes)
        return 1; //Human plays circle
    else
        return -1; //Human plays cross
}

int main(int argc, char *argv[])
{
    const int RESTART_CODE = 1234;
    int currentExitCode = 0;
    int humanScore=0, cpuScore=0;
    std::vector< std::vector<int> > dataBase;

    do{
        QApplication app(argc, argv);
        TicTacToe_Gui w(whoStarts(), dataBase);

        w.setScore(humanScore,cpuScore);
        w.show();

        currentExitCode=app.exec();
        humanScore=w.getHumanScore();
        cpuScore=w.getCPUScore();

    }
    while(currentExitCode==RESTART_CODE);

    return 0;
}
