#include "editortoolbarwidget.h"

EditorToolbarWidget::EditorToolbarWidget(QWidget *parent) : QWidget(parent)
{
	m_layout = new QHBoxLayout(this);
	m_saveProjectBtn = new QPushButton(this);
	m_addAudioCueBtn = new QPushButton(this);
	m_removeCueBtn = new QPushButton(this);
	m_moveUpBtn = new QPushButton(this);
	m_moveDownBtn = new QPushButton(this);

	connect(m_saveProjectBtn, &QPushButton::clicked, this,
			&EditorToolbarWidget::handleSaveProjectBtnClicked);
	connect(m_addAudioCueBtn, &QPushButton::clicked, this,
			&EditorToolbarWidget::handleAddAudioCueBtnClicked);
	connect(m_removeCueBtn, &QPushButton::clicked, this,
			&EditorToolbarWidget::handleRemoveCueBtnClicked);
	connect(m_moveUpBtn, &QPushButton::clicked, this,
			&EditorToolbarWidget::handleMoveUpBtnClicked);
	connect(m_moveDownBtn, &QPushButton::clicked, this,
			&EditorToolbarWidget::handleMoveDownBtnClicked);

	setTexts();

	m_layout->addWidget(m_saveProjectBtn);
	m_layout->addWidget(m_addAudioCueBtn);
	m_layout->addWidget(m_removeCueBtn);
	m_layout->addWidget(m_moveUpBtn);
	m_layout->addWidget(m_moveDownBtn);
}

void EditorToolbarWidget::handleSaveProjectBtnClicked(bool)
{
	emit SaveProjectClicked();
}

void EditorToolbarWidget::handleAddAudioCueBtnClicked(bool)
{
	emit AddAudioCueClicked();
}

void EditorToolbarWidget::handleRemoveCueBtnClicked(bool)
{
	emit RemoveCueBtnClicked();
}

void EditorToolbarWidget::handleMoveUpBtnClicked(bool)
{
	emit MoveUpBtnClicked();
}

void EditorToolbarWidget::handleMoveDownBtnClicked(bool)
{
	emit MoveDownBtnClicked();
}

void EditorToolbarWidget::setTexts()
{
	m_saveProjectBtn->setText(tr("Save Project"));
	m_addAudioCueBtn->setText(tr("Add Audio Cue"));
	m_removeCueBtn->setText(tr("Remove Cue"));
	m_moveUpBtn->setText(tr("Up"));
	m_moveDownBtn->setText(tr("Down"));
}
