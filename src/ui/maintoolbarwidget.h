#ifndef MAINTOOLBARWIDGET_H
#define MAINTOOLBARWIDGET_H

#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>

class MainToolbarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainToolbarWidget(QWidget *parent = nullptr);

signals:
    void NewProjectClicked();
    void SaveProjectClicked();
    void OpenProjectClicked();

private slots:
    void handleNewProjectBtnClicked(bool);
    void handleSaveProjectBtnClicked(bool);
    void handleOpenProjectBtnClicked(bool);

private:
    void setTexts();

    QHBoxLayout * m_layout = nullptr;
    QPushButton * m_newProjectBtn = nullptr;
    QPushButton * m_saveProjectBtn = nullptr;
    QPushButton * m_openProjectBtn = nullptr;
};

#endif // MAINTOOLBARWIDGET_H
