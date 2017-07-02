#include "maintoolbarwidget.h"

MainToolbarWidget::MainToolbarWidget(QWidget *parent) : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);
    m_newProjectBtn = new QPushButton(this);
    m_saveProjectBtn = new QPushButton(this);
    m_openProjectBtn = new QPushButton(this);

    connect(m_newProjectBtn, &QPushButton::clicked, this,
            &MainToolbarWidget::handleNewProjectBtnClicked);

    connect(m_saveProjectBtn, &QPushButton::clicked, this,
            &MainToolbarWidget::handleSaveProjectBtnClicked);

    connect(m_openProjectBtn, &QPushButton::clicked, this,
            &MainToolbarWidget::handleOpenProjectBtnClicked);

    setTexts();

    m_layout->addWidget(m_newProjectBtn);
    m_layout->addWidget(m_saveProjectBtn);
    m_layout->addWidget(m_openProjectBtn);
}

void MainToolbarWidget::handleNewProjectBtnClicked(bool)
{
    emit NewProjectClicked();
}

void MainToolbarWidget::handleSaveProjectBtnClicked(bool)
{
    emit SaveProjectClicked();
}

void MainToolbarWidget::handleOpenProjectBtnClicked(bool)
{
    emit OpenProjectClicked();
}

void MainToolbarWidget::setTexts()
{
    m_newProjectBtn->setText(tr("New Project"));
    m_saveProjectBtn->setText(tr("Save Project"));
    m_openProjectBtn->setText(tr("Open Project"));
}
