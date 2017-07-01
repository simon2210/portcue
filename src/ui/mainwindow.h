#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleBtnClicked();

private:
    QWidget * m_centralWidget;
    QLayout * m_centralLayout;
    QPushButton * m_pushbtn;
};

#endif // MAINWINDOW_H
