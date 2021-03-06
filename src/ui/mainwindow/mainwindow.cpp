#include "maincuetablemodel.h"
#include "mainwindow.h"
#include "src/ui/uihelper.h"

#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>

#include "src/ui/projectcreationdialog.h"
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
	m_cueListWidget = new CueListWidget(
		new MainCueTableModel(this), this
	);

	createActions();
	createToolbar();

	connect(m_projectManager, &ProjectManager::ProjectLoaded,
			this, &MainWindow::handleProjectLoaded);

	connect(m_cueListWidget, &CueListWidget::SelectedCueChanged,
			this, [=](Cue * cue) {
				qDebug(cue->Id().toLatin1());
	});

	connect(m_projectManager, &ProjectManager::CueAdded,
			this, &MainWindow::handleCueListChanged);
	connect(m_projectManager, &ProjectManager::CueRemoved,
			this, &MainWindow::handleCueListChanged);

	m_centralLayout->addWidget(m_cueListWidget);
	this->setCentralWidget(m_centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleNewProjectClicked()
{
	ProjectCreationDialog dlg(
		this, Qt::WindowFlags() & (~Qt::WindowContextHelpButtonHint)
	);
	if(dlg.exec() == QDialog::Accepted) {
		QString name = dlg.GetProjectName();
		m_projectManager->CreateProject(name);

		//TESTCODE
		Project *project = m_projectManager->GetProject();
		AudioCue * cue1 = new AudioCue("C:/1", project);
		AudioCue * cue2 = new AudioCue("C:/2", project);

		cue1->SetId("Q1");
		cue1->SetDescription("CueNummerEins");
		cue1->SetPage("Page1");

		cue2->SetId("Q2");
		cue2->SetDescription("CueNummerZwei");
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
	ProjectEditorDialog dlg(this);
	dlg.exec();
}

void MainWindow::handleProjectLoaded()
{
	Project * project = m_projectManager->GetProject();
	m_cueListWidget->SetDataSource(project->Cues());
	this->setWindowTitle(project->Name());
	m_openEditorAct->setEnabled(true);
}

void MainWindow::handleCueListChanged()
{
	m_cueListWidget->RefreshLayout();
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

	m_openEditorAct->setEnabled(false);

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
