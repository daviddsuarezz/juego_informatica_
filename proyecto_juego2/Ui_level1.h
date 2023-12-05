
#ifndef UI_LEVEL1_H
#define UI_LEVEL1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level1
{
public:
    QGraphicsView *graphicsView;
    QProgressBar *progressBar;
    QLCDNumber *score;
    QProgressBar *progressBar_2;
    QPushButton *stop;
    QPushButton *cont;
    QPushButton *retry;
    QPushButton *home;
    QLabel *showScore;

    void setupUi(QWidget *Level1)
    {
        if (Level1->objectName().isEmpty())
            Level1->setObjectName("Level1");
        Level1->resize(1280, 740);
        Level1->setMinimumSize(QSize(1280, 740));
        Level1->setMaximumSize(QSize(1280, 740));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/wallpaper.png"), QSize(), QIcon::Normal, QIcon::Off);
        Level1->setWindowIcon(icon);
        graphicsView = new QGraphicsView(Level1);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        progressBar = new QProgressBar(Level1);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 20, 240, 23));
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(24);
        score = new QLCDNumber(Level1);
        score->setObjectName("score");
        score->setGeometry(QRect(20, 50, 100, 40));
        score->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);\n"
                                               "border-top-color: rgb(255, 0, 0);\n"
                                               "gridline-color: rgb(255, 0, 0);\n"
                                               "selection-background-color: rgb(255, 0, 0);"));
        score->setDigitCount(5);
        score->setProperty("intValue", QVariant(0));
        progressBar_2 = new QProgressBar(Level1);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setGeometry(QRect(390, 20, 500, 23));
        progressBar_2->setStyleSheet(QString::fromUtf8(""));
        progressBar_2->setValue(24);
        stop = new QPushButton(Level1);
        stop->setObjectName("stop");
        stop->setGeometry(QRect(1210, 20, 50, 50));
        stop->setStyleSheet(QString::fromUtf8("border-image: url(:/images/stop.png);"));
        cont = new QPushButton(Level1);
        cont->setObjectName("cont");
        cont->setGeometry(QRect(490, 130, 316, 140));
        cont->setStyleSheet(QString::fromUtf8("border-image: url(:/images/continue.png);\n"
                                              "color: rgb(255, 255, 255);\n"
                                              "font: 20pt \"MV Boli\";"));
        retry = new QPushButton(Level1);
        retry->setObjectName("retry");
        retry->setGeometry(QRect(490, 271, 316, 140));
        retry->setStyleSheet(QString::fromUtf8("border-image: url(:/images/retry.png);\n"
                                               "color: rgb(255, 255, 255);\n"
                                               "font: 20pt \"MV Boli\";"));
        home = new QPushButton(Level1);
        home->setObjectName("home");
        home->setGeometry(QRect(490, 413, 316, 140));
        home->setStyleSheet(QString::fromUtf8("border-image: url(:/images/home.png);\n"
                                              "color: rgb(255, 255, 255);\n"
                                              "font: 20pt \"MV Boli\";"));
        showScore = new QLabel(Level1);
        showScore->setObjectName("showScore");
        showScore->setGeometry(QRect(420, 90, 531, 151));
        showScore->setStyleSheet(QString::fromUtf8("font: 30pt \"Papyrus\";\n"
                                                   "color: rgb(255, 0, 0);"));
#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)

        retranslateUi(Level1);

        QMetaObject::connectSlotsByName(Level1);
    } // setupUi

    void retranslateUi(QWidget *Level1)
    {
        Level1->setWindowTitle(QCoreApplication::translate("Level1", "Form", nullptr));
        stop->setText(QString());
        cont->setText(QCoreApplication::translate("Level1", "Continue", nullptr));
        retry->setText(QCoreApplication::translate("Level1", "Retry", nullptr));
        home->setText(QCoreApplication::translate("Level1", "Home", nullptr));
        showScore->setText(QCoreApplication::translate("Level1", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
class Level1: public Ui_Level1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL1_H
