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

void CueListWidget::SelectRow(int rowIdx)
{
	QModelIndex nextIdx = m_model->index(rowIdx, 0, {});
	if(nextIdx.isValid()) {
		m_view->setCurrentIndex(nextIdx);
	}
}

int CueListWidget::GetRowIndex()
{
	QModelIndex currentIndex = m_view->currentIndex();
	if(currentIndex.isValid()) {
		return currentIndex.row();
	}
	return 0;
}

void CueListWidget::RefreshLayout()
{
	m_model->RefreshLayout();
}

void CueListWidget::RefreshData()
{
	m_model->RefreshData();
}

void CueListWidget::RefreshData(int from, int to)
{
	m_model->RefreshData(from, to);
}

void CueListWidget::handleCurrentRowChanged(
	const QModelIndex &current, const QModelIndex &/*previous*/
) {
	if(current.isValid()) {
		Cue * selectedCue = static_cast<Cue *>(current.internalPointer());
		emit SelectedCueChanged(selectedCue);
	}
}



