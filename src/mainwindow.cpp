#include "mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_centralWidget = new QWidget(this);
    m_centralLayout = new QVBoxLayout(m_centralWidget);
    m_pushbtn = new QPushButton(this);

    m_pushbtn->setText(tr("Hallo Welt!"));

    m_centralLayout->addWidget(m_pushbtn);
    this->setCentralWidget(m_centralWidget);
}

MainWindow::~MainWindow()
{
}
