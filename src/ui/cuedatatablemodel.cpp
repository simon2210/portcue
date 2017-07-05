#include "cuedatatablemodel.h"

CueDataTableModel::CueDataTableModel(QObject *parent)
	: QAbstractTableModel(parent) { }

QList<Cue *> *CueDataTableModel::GetCues() const
{
	return m_cues;
}

void CueDataTableModel::SetDataSource(QList<Cue *> *cues)
{
	m_cues = cues;

	if(!IsEmpty())
		RefreshLayout();
}

void CueDataTableModel::RefreshLayout()
{
	emit layoutChanged();
}

void CueDataTableModel::RefreshData()
{
	if(!IsEmpty())
		RefreshData(0, m_cues->length() -1);
}

void CueDataTableModel::RefreshData(int from, int to)
{
	QModelIndex topleft = index(from, 0, {});
	QModelIndex bottomright = index(to, columnCount({}) -1, {});
	emit dataChanged(topleft, bottomright);
}

QModelIndex CueDataTableModel::index(
	int row, int column, const QModelIndex &parent
) const {
	return hasIndex(row, column, parent)
		? createIndex(row, column, (void*)m_cues->at(row))
		: QModelIndex();
}

bool CueDataTableModel::IsEmpty() const
{
	return m_cues == nullptr || m_cues->isEmpty();
}
