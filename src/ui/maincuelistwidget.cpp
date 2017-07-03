#include "maincuelistwidget.h"
#include <QHeaderView>

MainCueListWidget::MainCueListWidget(QWidget *parent) : QWidget(parent)
{
	m_layout = new QVBoxLayout(this);
	m_view = new QTableView(this);
	m_model = new MainCueTableModel(this);

	m_view->setModel(m_model);
	m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_view->verticalHeader()->hide();
	m_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	m_layout->addWidget(m_view);
}

void MainCueListWidget::SetDataSource(QList<Cue *> *cues)
{
	m_model->SetDataSource(cues);
}
