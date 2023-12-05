#ifndef GAMEROVERDIALOG_H
#define GAMEROVERDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTime>
class GameOverDialog : public QDialog {
    Q_OBJECT
public:
    GameOverDialog(bool win, QTime* time2, QWidget* parent = nullptr)
        : QDialog(parent)
    {
        QVBoxLayout* layout = new QVBoxLayout(this);

        if (win) {
            QLabel* winLabel = new QLabel("You Win");
            winLabel->setFont(QFont("comic sans", 50));
            layout->addWidget(winLabel);

            QLabel* timeLabel = new QLabel("Time: " + time2->toString("mm:ss"));
            timeLabel->setFont(QFont("comic sans", 16));
            layout->addWidget(timeLabel);
        } else {
            QLabel* loseLabel = new QLabel("Game Over");
            loseLabel->setFont(QFont("comic sans", 50));
            layout->addWidget(loseLabel);
        }

        QPushButton* restartButton = new QPushButton("Reiniciar");
        connect(restartButton, &QPushButton::clicked, this, &QDialog::accept);
        layout->addWidget(restartButton);

        QPushButton* quitButton = new QPushButton("Quit");
        connect(quitButton, &QPushButton::clicked, this, &QDialog::reject);
        layout->addWidget(quitButton);
    }
};


#endif // GAMEROVERDIALOG_H
