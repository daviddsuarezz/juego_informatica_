#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMessageBox>
#include <QApplication>
#include <QProcess>

class GameOverMenu{

public:
    GameOverMenu(bool win, int time);
    void show();
private:
    QMessageBox menu;
};


#endif // GAMEOVER_H
