#ifndef TICTACTOE_GUI_H
#define TICTACTOE_GUI_H

#include "ai.h"
#include <QMainWindow>
#include <QMap>
#include <QBitmap>

class QButtonGroup;
class QLabel;

namespace Ui {
class TicTacToe_Gui;
}

class TicTacToe_Gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe_Gui(int, std::vector< std::vector<int> > &, QWidget *parent = 0);

    void setScore(int, int);
    int getHumanScore();
    int getCPUScore();

    ~TicTacToe_Gui();

private slots:
    void onCellClicked(int);

private:
    Ui::TicTacToe_Gui *ui;
    QButtonGroup *buttonGroup;
    QPixmap *circleImage, *crossImage;
    QMap<int, QLabel *> buttonCellMap;
    AI *ai;

    int freeCellCounter;
    int humanScore, cpuScore;
    int activePlayer;                                           //activePlayer==1 implies circle, -1 for cross
    bool isHumanStarting;
    std::vector<int> stateHolder;                               //Holdes the current state of the board
    std::vector< std::vector<int> > *dataBase  ;                //Is equal, by reference, to an external data base

    void setupCells();
    void setWhoStarts(int);
    void setDisabledButtons(bool enable);
    void setupReplayBox();
    bool isWin();                                               //returns true if somebody won and updates the score
    void updateScore();                                         //updates humanScore and cpuScore
    void updateScoreLabels();                                   //Updates the labels that display the score
    bool stateExists(std::vector<int>);                         //returns true if state is already in dataBase
    void setDataBase(std::vector< std::vector<int> > & );       /*gets the data from an external source
                                                                  and copies it by ref to this->dataBase to
                                                                  avoid double memory usage*/
    std::vector<int> getReversedState(const std::vector<int> &);
    std::vector<int> getRotatedState(const std::vector<int> &);
    std::vector<int> getHMirroredState(const std::vector<int> &);
    std::vector<int> getVMirroredState(const std::vector<int> &);


    void addToDataBase(const std::vector<int>&);
    void updateDataBase(std::vector<int> state,
                        int numberOfRotations=0);                /*Updates the dataBase - also updates the external
                                                                  data base - the method is called only if game ended*/

};

#endif // TICTACTOE_GUI_H
