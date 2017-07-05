#include "editorcuetablemodel.h"
#include "projecteditordialog.h"
#include "uihelper.h"

#include <src/data/audiocue.h>

ProjectEditorDialog::ProjectEditorDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags() & (~Qt::WindowContextHelpButtonHint))
{
	this->setWindowTitle(tr("Editor"));
	m_projectManager = ProjectManager::Instance();
	m_centralLayout = new QGridLayout(this);
	m_toolbar = new EditorToolbarWidget(this);
	m_cueListWidget = new CueListWidget(new EditorCueTableModel(this), this);

	m_cueListWidget->SetDataSource(m_projectManager->GetProject()->Cues());

	connect(m_toolbar, &EditorToolbarWidget::SaveProjectClicked,
			this, &ProjectEditorDialog::handleSaveProjectClicked);
	connect(m_toolbar, &EditorToolbarWidget::AddAudioCueClicked,
			this, &ProjectEditorDialog::handleAddAudioCueClicked);
	connect(m_toolbar, &EditorToolbarWidget::RemoveCueBtnClicked,
			this, &ProjectEditorDialog::handleRemoveCueClicked);
	connect(m_toolbar, &EditorToolbarWidget::MoveUpBtnClicked,
			this, &ProjectEditorDialog::handleMoveUpClicked);
	connect(m_toolbar, &EditorToolbarWidget::MoveDownBtnClicked,
			this, &ProjectEditorDialog::handleMoveDownClicked);

	connect(m_projectManager, &ProjectManager::CueAdded,
			this, &ProjectEditorDialog::handleCueListChanged);
	connect(m_projectManager, &ProjectManager::CueRemoved,
			this, &ProjectEditorDialog::handleCueListChanged);
	connect(m_projectManager, &ProjectManager::CueMoved,
			this, &ProjectEditorDialog::handleCueMoved);

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

void ProjectEditorDialog::handleAddAudioCueClicked()
{
	Project * project = m_projectManager->GetProject();
	int index = m_cueListWidget->GetRowIndex();
	QStringList selectedFiles;
	if(UiHelper::ShowOpenAudioDlg(&selectedFiles, this)) {
		foreach (const QString &file, selectedFiles) {
			AudioCue * cue = new AudioCue(file, project);
			m_projectManager->AddCue(cue, index);
		}
	}
}

void ProjectEditorDialog::handleRemoveCueClicked()
{
	Cue * selectedCue = m_cueListWidget->GetSelectedCue();
	if(selectedCue != nullptr) {
		m_projectManager->RemoveCue(selectedCue);
	}
}

void ProjectEditorDialog::handleMoveUpClicked()
{
	Cue * selectedCue = m_cueListWidget->GetSelectedCue();
	int idx = m_cueListWidget->GetRowIndex();
	if(selectedCue != nullptr ){
		m_projectManager->MoveCue(selectedCue, idx - 1);
	}
}

void ProjectEditorDialog::handleMoveDownClicked()
{
	Cue * selectedCue = m_cueListWidget->GetSelectedCue();
	int idx = m_cueListWidget->GetRowIndex();
	if(selectedCue != nullptr ){
		m_projectManager->MoveCue(selectedCue, idx + 1);
	}
}

void ProjectEditorDialog::handleCueListChanged()
{
	m_cueListWidget->RefreshLayout();
}

void ProjectEditorDialog::handleCueMoved(int from, int to)
{
	m_cueListWidget->RefreshData(from, to);
}
