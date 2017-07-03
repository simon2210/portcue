#include "editorcuetablemodel.h"

EditorCueTableModel::EditorCueTableModel(QObject *parent)
	: CueDataTableModel(parent) { }

int EditorCueTableModel::rowCount(const QModelIndex &/*parent*/) const
{
	return IsEmpty() ? 0 : GetCues()->length();
}

int EditorCueTableModel::columnCount(const QModelIndex &/*parent*/) const
{
	return COL_COUNT;
}

QVariant EditorCueTableModel::data(const QModelIndex &index, int role) const
{
	if (role != Qt::DisplayRole && role != Qt::EditRole)
		return {};

	const auto cue = GetCues()->at(index.row());
	switch (index.column()) {
		case 0: return cue->Type();
		case 1: return cue->Id();
		default: return {};
	};
}

QVariant EditorCueTableModel::headerData(
		int section, Qt::Orientation orientation, int role
) const {
	if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
		return {};

	switch (section) {
		case 0: return tr("Type");
		case 1: return tr("Id");
		default: return {};
	}
}
