#include "cuemetawidget.h"

CueMetaWidget::CueMetaWidget(QWidget *parent) : QWidget(parent)
{
	m_layout = new QGridLayout(this);
	m_idLbl = new QLabel(this);
	m_pageLbl = new QLabel(this);
	m_descriptionLbl = new QLabel(this);
	m_idEdit = new QLineEdit(this);
	m_pageEdit = new QLineEdit(this);
	m_descriptionEdit = new QLineEdit(this);

	connect(m_idEdit, &QLineEdit::textChanged,
			this, &CueMetaWidget::handleIdChanged);
	connect(m_pageEdit, &QLineEdit::textChanged,
			this, &CueMetaWidget::handlePageChanged);
	connect(m_descriptionEdit, &QLineEdit::textChanged,
			this, &CueMetaWidget::handleDescriptionChanged);

	setTexts();

	m_layout->addWidget(m_idLbl, 0, 0, 1, 1, Qt::AlignLeft);
	m_layout->addWidget(m_idEdit, 0, 1, 1, 1, Qt::AlignLeft);
	m_layout->addWidget(m_descriptionLbl, 0, 2, 1, 1, Qt::AlignRight);
	m_layout->addWidget(m_descriptionEdit, 0, 3, 1, 1, Qt::AlignRight);
	m_layout->addWidget(m_pageLbl, 1, 0, 1, 1, Qt::AlignLeft);
	m_layout->addWidget(m_pageEdit, 1, 1, 1, 1, Qt::AlignLeft);
}

void CueMetaWidget::SetDataSource(Cue *cue)
{
	if(cue == nullptr)
		return;

	m_cue = cue;

	m_idEdit->setText(m_cue->Id());
	m_pageEdit->setText(m_cue->Page());
	m_descriptionEdit->setText(m_cue->Description());
}

void CueMetaWidget::handleIdChanged(QString newId)
{
	m_cue->SetId(newId);
}

void CueMetaWidget::handlePageChanged(QString newPage)
{
	m_cue->SetPage(newPage);
}

void CueMetaWidget::handleDescriptionChanged(QString newDescription)
{
	m_cue->SetDescription(newDescription);
}

void CueMetaWidget::setTexts()
{
	m_idLbl->setText(tr("Cue"));
	m_pageLbl->setText(tr("Page"));
	m_descriptionLbl->setText(tr("Description"));
}
