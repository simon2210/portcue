#ifndef MAINCUETABLEMODEL_H
#define MAINCUETABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>

#include <src/data/cue.h>

#define COL_COUNT 4

class MainCueTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit MainCueTableModel(QObject *parent = nullptr);
	void SetDataSource(QList<Cue *> * cues);

	// QAbstractItemModel interface
	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
	bool isEmpty() const;
	QList<Cue *> * m_cues = nullptr;
};

#endif // MAINCUETABLEMODEL_H
