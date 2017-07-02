#include "mainwindow.h"

#include <QVBoxLayout>
#include <QMediaPlayer>

#include <src/data/audiocue.h>
#include <src/data/project.h>

#include <src/io/projectreader.h>
#include <src/io/projectwriter.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_centralWidget = new QWidget(this);
    m_centralLayout = new QGridLayout(m_centralWidget);
    m_toolbar = new MainToolbarWidget(this);

    connect(m_toolbar, &MainToolbarWidget::NewProjectClicked,
            this, &MainWindow::handleNewProjectClicked);

    connect(m_toolbar, &MainToolbarWidget::SaveProjectClicked,
            this, &MainWindow::handleSaveProjectClicked);

    connect(m_toolbar, &MainToolbarWidget::OpenProjectClicked,
            this, &MainWindow::handleOpenProjectClicked);

    m_centralLayout->addWidget(m_toolbar);

    this->setCentralWidget(m_centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleNewProjectClicked()
{

}

void MainWindow::handleSaveProjectClicked()
{
        Project * testProj = new Project(this);
        testProj->SetName("TestProject");
        AudioCue * cue1 = new AudioCue(testProj);
        AudioCue * cue2 = new AudioCue(testProj);

          cue1->SetId("Q1");
          cue1->SetDescription("CueNummerEins");
          cue1->SetFilePath("C:/1");
          cue1->SetPage("Page1");

        cue2->SetId("Q2");
        cue2->SetDescription("CueNummerZwei");
        cue2->SetFilePath("C:/2");
        cue2->SetPage("Page2");

        testProj->AddCue(cue1, 0);
        testProj->AddCue(cue2, 1);
        ProjectWriter::WriteProject("C:\\Users\\spaul\\Desktop\\testfile.xml", testProj);
}

void MainWindow::handleOpenProjectClicked()
{
    Project *proj = ProjectReader::ReadProject("C:\\Users\\spaul\\Desktop\\testfile.xml");
    QList<Cue *> localCues = (* proj->Cues());
    int localLength = localCues.length();
    Cue * cue1 = localCues[0];
    Cue * cue2 = localCues[1];

}
