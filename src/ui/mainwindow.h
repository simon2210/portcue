#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cuelistwidget.h"
#include "editortoolbarwidget.h"
#include "projecteditordialog.h"
#include "src/projectmanager.h"

#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleNewProjectClicked();
    void handleSaveProjectClicked();
    void handleOpenProjectClicked();
	void handleProjectEditorClicked();
	void handleProjectLoaded();
	void handleCueListChanged();

private:
	void createActions();
	void createToolbar();

	ProjectManager * m_projectManager = nullptr;

    QWidget * m_centralWidget = nullptr;
    QGridLayout * m_centralLayout = nullptr;
	QToolBar * m_toolbar = nullptr;
	CueListWidget * m_cueListWidget = nullptr;
	QAction * m_newProjectAct = nullptr;
	QAction * m_saveProjectAct = nullptr;
	QAction * m_openProjectAct = nullptr;
	QAction * m_openEditorAct = nullptr;
};

#endif // MAINWINDOW_H
