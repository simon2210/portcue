#ifndef CUEMETAWIDGET_H
#define CUEMETAWIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>

#include "src/data/cue.h"

class CueMetaWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CueMetaWidget(QWidget *parent = nullptr);
	void SetDataSource(Cue * cue);

private slots:
	void handleIdChanged(QString newId);
	void handlePageChanged(QString newPage);
	void handleDescriptionChanged(QString newDescription);

private:
	void setTexts();

	Cue * m_cue = nullptr;
	
	QGridLayout * m_layout = nullptr;
	QLabel * m_idLbl = nullptr;
	QLabel * m_pageLbl = nullptr;
	QLabel * m_descriptionLbl = nullptr;
	QLineEdit * m_idEdit = nullptr;
	QLineEdit * m_pageEdit = nullptr;
	QLineEdit * m_descriptionEdit = nullptr;
};

#endif // CUEMETAWIDGET_H
