#ifndef PROJECTEDITORWINDOW_H
#define PROJECTEDITORWINDOW_H

#include "src/projectmanager.h"

#include <QAction>
#include <QGridLayout>
#include <QMainWindow>
#include <QToolBar>

namespace Ui {
	class ProjectEditorWindow;
}

class ProjectEditorWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ProjectEditorWindow(QWidget *parent = nullptr);

private slots:
	void handleSaveProjectClicked();

private:
	void createActions();
	void createToolbar();

	ProjectManager * m_projectManager = nullptr;

	QWidget * m_centralWidget = nullptr;
	QGridLayout * m_centralLayout = nullptr;
	QToolBar * m_toolbar = nullptr;
	QAction * m_saveProjectAct = nullptr;
};

#endif // PROJECTEDITORWINDOW_H
