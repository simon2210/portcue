#ifndef MAINCUELISTWIDGET_H
#define MAINCUELISTWIDGET_H

#include "maincuetablemodel.h"

#include <QBoxLayout>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QWidget>

class MainCueListWidget : public QWidget
{
	Q_OBJECT
public:
	explicit MainCueListWidget(QWidget *parent = nullptr);
	void SetDataSource(QList<Cue *> * cues);

private:
	QVBoxLayout * m_layout = nullptr;
	QTableView * m_view = nullptr;
	MainCueTableModel * m_model = nullptr;
};

#endif // MAINCUELISTWIDGET_H
