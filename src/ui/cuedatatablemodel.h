#ifndef CUEDATATABLEMODEL_H
#define CUEDATATABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>

#include "src/data/cue.h"

class CueDataTableModel : public QAbstractTableModel
{
public:
	explicit CueDataTableModel(QObject *parent = nullptr);
	void SetDataSource(QList<Cue *> *cues);
	void RefreshLayout();
	void RefreshData();
	void RefreshData(int from, int to);

	// QAbstractItemModel interface
	QModelIndex index(int row, int column, const QModelIndex &parent) const;
	int rowCount(const QModelIndex &parent) const = 0;
	int columnCount(const QModelIndex &parent) const = 0;
	QVariant data(const QModelIndex &index, int role) const = 0;
	QVariant headerData(
		int section, Qt::Orientation orientation, int role
	) const = 0;

protected:
	bool IsEmpty() const;
	QList<Cue *> * GetCues() const;

private:
	QList<Cue *> * m_cues = nullptr;
};

#endif // CUEDATATABLEMODEL_H
