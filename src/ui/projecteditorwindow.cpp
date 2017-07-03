#include "projecteditorwindow.h"
#include "uihelper.h"

ProjectEditorWindow::ProjectEditorWindow(QWidget *parent) : QMainWindow(parent)
{
	m_projectManager = ProjectManager::Instance();
	m_centralWidget = new QWidget(this);
	m_centralLayout = new QGridLayout(m_centralWidget);
	m_toolbar = new QToolBar(this);

	createActions();
	createToolbar();

	this->setCentralWidget(m_centralWidget);
}

void ProjectEditorWindow::handleSaveProjectClicked()
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

void ProjectEditorWindow::createActions()
{
	m_saveProjectAct = new QAction(tr("Save Project"), this);

	m_saveProjectAct->setShortcut(QKeySequence::Save);

	m_saveProjectAct->setCheckable(false);

	connect(m_saveProjectAct, &QAction::triggered,
			this, &ProjectEditorWindow::handleSaveProjectClicked);
}

void ProjectEditorWindow::createToolbar()
{
	addToolBar(m_toolbar);
	m_toolbar->addActions({
		m_saveProjectAct
	});
}
