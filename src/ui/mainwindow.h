#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "maintoolbarwidget.h"

#include <QGridLayout>
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
    void handleNewProjectClicked();
    void handleSaveProjectClicked();
    void handleOpenProjectClicked();

private:
    QWidget * m_centralWidget = nullptr;
    QGridLayout * m_centralLayout = nullptr;
    MainToolbarWidget * m_toolbar = nullptr;
};

#endif // MAINWINDOW_H
