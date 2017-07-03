#include "editorcuetablemodel.h"
#include "projecteditordialog.h"
#include "uihelper.h"

ProjectEditorDialog::ProjectEditorDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags() & (~Qt::WindowContextHelpButtonHint))
{
	this->setWindowTitle(tr("Editor"));
	m_projectManager = ProjectManager::Instance();
	m_centralLayout = new QGridLayout(this);
	m_toolbar = new EditorToolbarWidget(this);
	m_cueListWidget = new CueListWidget(new EditorCueTableModel(this), this);

	m_cueListWidget->SetDataSource(m_projectManager->GetProject()->Cues());

	m_centralLayout->addWidget(m_toolbar);
	m_centralLayout->addWidget(m_cueListWidget);
}

void ProjectEditorDialog::handleSaveProjectClicked()
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
