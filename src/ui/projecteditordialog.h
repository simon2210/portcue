#ifndef PROJECTEDITORWINDOW_H
#define PROJECTEDITORWINDOW_H

#include "src/projectmanager.h"
#include "cuelistwidget.h"
#include "editortoolbarwidget.h"

#include <QAction>
#include <QDialog>
#include <QGridLayout>
#include <QToolBar>

namespace Ui {
	class ProjectEditorWindow;
}

class ProjectEditorDialog : public QDialog
{
	Q_OBJECT
public:
	explicit ProjectEditorDialog(QWidget *parent = nullptr);

private slots:
	void handleSaveProjectClicked();

private:
	ProjectManager * m_projectManager = nullptr;

	QGridLayout * m_centralLayout = nullptr;
	EditorToolbarWidget * m_toolbar = nullptr;
	CueListWidget * m_cueListWidget = nullptr;
	QAction * m_saveProjectAct = nullptr;
};

#endif // PROJECTEDITORWINDOW_H
