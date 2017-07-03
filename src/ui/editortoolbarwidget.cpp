#include "editortoolbarwidget.h"

EditorToolbarWidget::EditorToolbarWidget(QWidget *parent) : QWidget(parent)
{
	m_layout = new QHBoxLayout(this);
	m_saveProjectBtn = new QPushButton(this);

    connect(m_saveProjectBtn, &QPushButton::clicked, this,
			&EditorToolbarWidget::handleSaveProjectBtnClicked);

    setTexts();

	m_layout->addWidget(m_saveProjectBtn);
}

void EditorToolbarWidget::handleSaveProjectBtnClicked(bool)
{
    emit SaveProjectClicked();
}

void EditorToolbarWidget::setTexts()
{
	m_saveProjectBtn->setText(tr("Save Project"));
}
