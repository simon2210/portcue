#include "cuelistwidget.h"
#include <QHeaderView>

CueListWidget::CueListWidget(CueDataTableModel * model, QWidget *parent)
	: QWidget(parent), m_model(model)
{
	m_layout = new QVBoxLayout(this);
	m_view = new QTableView(this);
	m_view->setModel(m_model);

	connect(m_view->selectionModel(), &QItemSelectionModel::currentRowChanged,
			this, &CueListWidget::handleCurrentRowChanged);

	m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_view->verticalHeader()->hide();
	m_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	m_layout->addWidget(m_view);
}

void CueListWidget::SetDataSource(QList<Cue *> *cues)
{
	m_model->SetDataSource(cues);
	if(cues != nullptr && !cues->isEmpty()) {
		QModelIndex index = m_model->index(0, 0, {});
		m_view->setCurrentIndex(index);
	}
}

Cue *CueListWidget::GetSelectedCue()
{
	QModelIndex currentIndex = m_view->currentIndex();
	if(currentIndex.isValid()) {
		Cue * selectedCue = static_cast<Cue *>(currentIndex.internalPointer());
		return selectedCue;
	}
	return nullptr;
}

void CueListWidget::handleCurrentRowChanged(
	const QModelIndex &current, const QModelIndex &/*previous*/
) {
	if(current.isValid()) {
		Cue * selectedCue = static_cast<Cue *>(current.internalPointer());
		emit SelectedCueChanged(selectedCue);
	}
}



