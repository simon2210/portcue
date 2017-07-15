#ifndef MAINCUETABLEMODEL_H
#define MAINCUETABLEMODEL_H

#include "src/data/cue.h"
#include "src/ui/cuedatatablemodel.h"

#define COL_COUNT 4

class MainCueTableModel : public CueDataTableModel
{

public:
	explicit MainCueTableModel(QObject *parent = nullptr);

	// QAbstractItemModel interface
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(
		int section, Qt::Orientation orientation, int role
	) const override;
};

#endif // MAINCUETABLEMODEL_H
