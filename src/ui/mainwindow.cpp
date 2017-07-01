#include "mainwindow.h"

#include <QVBoxLayout>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_centralWidget = new QWidget(this);
    m_centralLayout = new QVBoxLayout(m_centralWidget);
    m_pushbtn = new QPushButton(this);

    connect(m_pushbtn, &QPushButton::clicked, this, &MainWindow::handleBtnClicked);


    m_pushbtn->setText(tr("Hallo Welt!"));

    m_centralLayout->addWidget(m_pushbtn);
    this->setCentralWidget(m_centralWidget);
}

MainWindow::~MainWindow()
{
}

QMediaPlayer * player;
void MainWindow::handleBtnClicked()
{
    player = new QMediaPlayer(this);
    // ...
    player->setMedia(QUrl::fromLocalFile("../testsound.mp3"));
    player->setVolume(50);
    QMediaPlayer::MediaStatus localMediaStatus = player->mediaStatus();
    player->play();
}
