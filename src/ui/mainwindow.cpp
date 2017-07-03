#include "mainwindow.h"
#include "uihelper.h"

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

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	m_projectManager = ProjectManager::Instance();

	m_centralWidget = new QWidget(this);
	m_centralLayout = new QGridLayout(m_centralWidget);
	m_toolbar = new QToolBar(this);
	m_cueListWidget = new MainCueListWidget(this);

	createActions();
	createToolbar();

	connect(m_projectManager, &ProjectManager::ProjectLoaded, this, [=]{
		m_cueListWidget->SetDataSource(m_projectManager->GetProject()->Cues());
	});

	m_centralLayout->addWidget(m_cueListWidget);
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
		m_projectManager->CreateProject(name);

		//TESTCODE
		Project *project = m_projectManager->GetProject();
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

		m_projectManager->AddCue(cue1, 0);
		m_projectManager->AddCue(cue2, 1);
	}
}

void MainWindow::handleSaveProjectClicked()
{
	if(m_projectManager->GetProject() == nullptr)
		return;

	QString projectPath = m_projectManager->ProjectPath();

	if(projectPath.isNull() || projectPath.isEmpty()) {
		if(!UiHelper::ShowSaveProjectDlg(&projectPath))
			return;
	}

	if(!m_projectManager->SaveProject(projectPath)) {
		UiHelper::ShowSaveErrorMsgBox();
	}
}

void MainWindow::handleOpenProjectClicked()
{
	QString projectPath = nullptr;
	if(!UiHelper::ShowOpenProjectDlg(&projectPath))
		return;

	if(!m_projectManager->OpenProject(projectPath))
		UiHelper::ShowOpenErorMsgBox();
}

void MainWindow::handleProjectEditorClicked()
{
	if(m_editor == nullptr) {
		m_editor = new ProjectEditorWindow(this);
	}
	m_editor->show();
}

void MainWindow::createActions()
{
	m_newProjectAct = new QAction(tr("New Project"), this);
	m_saveProjectAct = new QAction(tr("Save Project"), this);
	m_openProjectAct = new QAction(tr("Open Project"), this);
	m_openEditorAct = new QAction(tr("Editor"), this);

	m_newProjectAct->setShortcuts(QKeySequence::New);
	m_saveProjectAct->setShortcut(QKeySequence::Save);
	m_openProjectAct->setShortcut(QKeySequence::Open);

	m_newProjectAct->setCheckable(false);
	m_saveProjectAct->setCheckable(false);
	m_openProjectAct->setCheckable(false);
	m_openEditorAct->setCheckable(false);

	connect(m_newProjectAct, &QAction::triggered,
			this, &MainWindow::handleNewProjectClicked);
	connect(m_saveProjectAct, &QAction::triggered,
			this, &MainWindow::handleSaveProjectClicked);
	connect(m_openProjectAct, &QAction::triggered,
			this, &MainWindow::handleOpenProjectClicked);
	connect(m_openEditorAct, &QAction::triggered,
			this, &MainWindow::handleProjectEditorClicked);

}

void MainWindow::createToolbar()
{
	addToolBar(m_toolbar);
	m_toolbar->addActions({
		m_newProjectAct, m_saveProjectAct, m_openProjectAct, m_openEditorAct
	});
}
