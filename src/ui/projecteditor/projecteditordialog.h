#ifndef PROJECTEDITORWINDOW_H
#define PROJECTEDITORWINDOW_H

#include "src/projectmanager.h"
#include "cueeditwidget.h"
#include "editortoolbarwidget.h"
#include "src/ui/cuelistwidget.h"

#include <QAction>
#include <QDialog>
#include <QGridLayout>
#include <QSplitter>
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
	//Toolbar
	void handleSaveProjectClicked();
	void handleAddAudioCueClicked();
	void handleRemoveCueClicked();
	void handleMoveUpClicked();
	void handleMoveDownClicked();

	//Projectmanager
	void handleCueListChanged();
	void handleCueMoved(int from, int to);

	//Cuelist
	void handleSelectedCueChanged(Cue * selectedCue);

private:
	ProjectManager * m_projectManager = nullptr;

	QGridLayout * m_centralLayout = nullptr;
	QSplitter * m_hSplitter = nullptr;
	EditorToolbarWidget * m_toolbar = nullptr;
	CueListWidget * m_cueListWidget = nullptr;
	CueEditWidget * m_cueEditWidget = nullptr;
	QAction * m_saveProjectAct = nullptr;
};

#endif // PROJECTEDITORWINDOW_H
