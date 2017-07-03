#include "maincuetablemodel.h"

MainCueTableModel::MainCueTableModel(QObject *parent)
	: QAbstractTableModel(parent) { }

void MainCueTableModel::SetDataSource(QList<Cue *> *cues)
{
	m_cues = cues;

	if(!isEmpty())
		emit layoutChanged();
}

bool MainCueTableModel::isEmpty() const
{
	return m_cues == nullptr || m_cues->isEmpty();
}

int MainCueTableModel::rowCount(const QModelIndex &/*parent*/) const
{
	return isEmpty() ? 0 : m_cues->length();
}

int MainCueTableModel::columnCount(const QModelIndex &/*parent*/) const
{
	return COL_COUNT;
}

QVariant MainCueTableModel::data(const QModelIndex &index, int role) const
{
	if (role != Qt::DisplayRole && role != Qt::EditRole)
		return {};

	const auto cue = m_cues->at(index.row());
	switch (index.column()) {
		case 0: return cue->Id();
		case 1: return cue->Description();
		case 2: return cue->Page();
		case 3: return cue->Type();
		default: return {};
	};
}

QVariant MainCueTableModel::headerData(
		int section, Qt::Orientation orientation, int role
) const {
	if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
		return {};

	switch (section) {
		case 0: return tr("Id");
		case 1: return tr("Description");
		case 2: return tr("Page");
		case 3: return tr("Type");
		default: return {};
	}
}
