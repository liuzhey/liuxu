#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int exchange_the_hex(uint hex);
    Form * scene2 = NULL;
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
