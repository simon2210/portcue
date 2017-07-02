#include "mainwindow.h"

#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMessageBox>

#include "projectcreationdialog.h"
#include "src/applicationconfig.h"
#include "src/data/audiocue.h"
#include "src/data/project.h"
#include "src/io/projectreader.h"
#include "src/io/projectwriter.h"
#include "src/projectmanager.h"

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
    ProjectCreationDialog dlg(this, Qt::WindowFlags());
    if(dlg.exec() == QDialog::Accepted) {
        QString name = dlg.GetProjectName();
        ProjectManager::Instance()->CreateProject(name);


        //TESTCODE
        Project *project = ProjectManager::Instance()->GetProject();
        AudioCue * cue1 = new AudioCue(project);
        AudioCue * cue2 = new AudioCue(project);

        cue1->SetId("Q1");
        cue1->SetDescription("CueNummerEins");
        cue1->SetFilePath("C:/1");
        cue1->SetPage("Page1");

        cue2->SetId("Q2");
        cue2->SetDescription("CueNummerZwei");
        cue2->SetFilePath("C:/2");
        cue2->SetPage("Page2");

        ProjectManager::Instance()->AddCue(cue1, 0);
        ProjectManager::Instance()->AddCue(cue2, 1);
    }
}

void MainWindow::handleSaveProjectClicked()
{
    ProjectManager * projectManager = ProjectManager::Instance();
    if(projectManager->GetProject() == nullptr)
        return;

    QString projectPath = projectManager->ProjectPath();

    if(projectPath.isNull() || projectPath.isEmpty()) {
        QFileDialog dlg(this, Qt::WindowFlags());
        dlg.setFileMode(QFileDialog::AnyFile);
        dlg.setAcceptMode(QFileDialog::AcceptSave);
        dlg.setNameFilter(DIALOG_PROJECT_FILTER);
        dlg.setDefaultSuffix(PROJECT_EXTENSION);
        dlg.setNameFilterDetailsVisible(true);
        if(dlg.exec() == QDialog::Accepted) {
            projectPath = dlg.selectedFiles().first();
        } else {
            return;
        }
    }

    if(!projectManager->SaveProject(projectPath)) {
        QMessageBox msgBox(
            QMessageBox::Warning, tr("Save File"), tr("Could not save project!"),
            QMessageBox::Ok, this
        );
        msgBox.exec();
    }
}

void MainWindow::handleOpenProjectClicked()
{
    QFileDialog dlg(this, Qt::WindowFlags());
    dlg.setFileMode(QFileDialog::ExistingFile);
    dlg.setAcceptMode(QFileDialog::AcceptOpen);
    dlg.setNameFilter(DIALOG_PROJECT_FILTER);
    dlg.setDefaultSuffix(PROJECT_EXTENSION);
    dlg.setNameFilterDetailsVisible(true);
    if(dlg.exec() == QDialog::Accepted) {
        QString selectedFile = dlg.selectedFiles().first();
        if(!ProjectManager::Instance()->OpenProject(selectedFile)) {
            QMessageBox msgBox(
                QMessageBox::Warning, tr("Open File"), tr("Could not open project!"),
                QMessageBox::Ok, this
            );
            msgBox.exec();
        }
    }
}
