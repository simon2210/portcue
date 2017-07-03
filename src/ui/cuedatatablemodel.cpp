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
		emit layoutChanged();
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
