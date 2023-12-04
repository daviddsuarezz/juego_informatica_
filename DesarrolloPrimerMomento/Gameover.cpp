
GameOverMenu::GameOverMenu(bool win, int time)
{
    if (win) {
        menu.setText("Win! Time: " + QString::number(time));
    } else {
        menu.setText("Game Over");
    }

    QPushButton *quitButton = menu.addButton("Quit", QMessageBox::RejectRole);
    QPushButton *restartButton = menu.addButton("Restart", QMessageBox::AcceptRole);

    QObject::connect(quitButton, &QPushButton::clicked,  {
        qApp->quit();
    });

    QObject::connect(restartButton, &QPushButton::clicked,  {
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    });
}
