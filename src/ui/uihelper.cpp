#include "uihelper.h"
#include "src/applicationconfig.h"

#include <QFileDialog>
#include <QMessageBox>

bool UiHelper::ShowSaveProjectDlg(QString *projectPath, QWidget *parent)
{
	QFileDialog dlg(parent, Qt::WindowFlags());
	dlg.setFileMode(QFileDialog::AnyFile);
	dlg.setAcceptMode(QFileDialog::AcceptSave);
	dlg.setNameFilter(DIALOG_PROJECT_FILTER);
	dlg.setDefaultSuffix(PROJECT_EXTENSION);
	dlg.setNameFilterDetailsVisible(true);
	if(dlg.exec() == QDialog::Accepted) {
		*projectPath = dlg.selectedFiles().first();
		return true;
	} else {
		projectPath = nullptr;
		return false;
	}
}

void UiHelper::ShowSaveErrorMsgBox(QWidget *parent)
{
	QMessageBox msgBox(
		QMessageBox::Warning, tr("Save File"), tr("Could not save project!"),
		QMessageBox::Ok, parent
	);
	msgBox.exec();
}

bool UiHelper::ShowOpenProjectDlg(QString *projectPath, QWidget *parent)
{
	QFileDialog dlg(parent, Qt::WindowFlags());
	dlg.setFileMode(QFileDialog::ExistingFile);
	dlg.setAcceptMode(QFileDialog::AcceptOpen);
	dlg.setNameFilter(DIALOG_PROJECT_FILTER);
	dlg.setDefaultSuffix(PROJECT_EXTENSION);
	dlg.setNameFilterDetailsVisible(true);
	if(dlg.exec() == QDialog::Accepted) {
		*projectPath = dlg.selectedFiles().first();
		return true;
	} else {
		projectPath = nullptr;
		return false;
	}
}

void UiHelper::ShowOpenErorMsgBox(QWidget *parent)
{
	QMessageBox msgBox(
		QMessageBox::Warning, tr("Open File"), tr("Could not open project!"),
		QMessageBox::Ok, parent
	);
	msgBox.exec();
}

bool UiHelper::ShowOpenAudioDlg(QStringList *files, QWidget *parent)
{
	QFileDialog dlg(parent, Qt::WindowFlags());
	dlg.setFileMode(QFileDialog::ExistingFiles);
	dlg.setAcceptMode(QFileDialog::AcceptOpen);
	dlg.setNameFilter(DIALOG_AUDIO_FILTER);
	dlg.setNameFilterDetailsVisible(true);
	if(dlg.exec() == QDialog::Accepted) {
		*files = dlg.selectedFiles();
		return true;
	} else {
		files = nullptr;
		return false;
	}
}
