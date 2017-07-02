#ifndef PROJECTCREATIONDIALOG_H
#define PROJECTCREATIONDIALOG_H

#include <QBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class ProjectCreationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectCreationDialog(QWidget *parent = nullptr,  Qt::WindowFlags f = 0);
    QString GetProjectName();

private:
    void setTexts();

    QHBoxLayout * m_layout = nullptr;
    QLabel * m_projetNameLbl = nullptr;
    QLineEdit * m_projectEdit = nullptr;
    QPushButton * m_okBtn = nullptr;
};

#endif // PROJECTCREATIONDIALOG_H
