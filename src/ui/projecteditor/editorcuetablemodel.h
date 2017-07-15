#ifndef EDITORCUETABLEMODEL_H
#define EDITORCUETABLEMODEL_H

#include <src/ui/cuedatatablemodel.h>

#define COL_COUNT 2

class EditorCueTableModel : public CueDataTableModel
{
public:
	explicit EditorCueTableModel(QObject *parent = nullptr);

	// QAbstractItemModel interface
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(
		int section, Qt::Orientation orientation, int role
	) const override;
};

#endif // EDITORCUETABLEMODEL_H
