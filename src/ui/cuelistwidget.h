#ifndef CUELISTWIDGET_H
#define CUELISTWIDGET_H

#include <QBoxLayout>
#include <QTableView>
#include <QWidget>

#include "src/data/cue.h"

#include "cuedatatablemodel.h"

namespace Ui {
	class CueListWidget;
}

class CueListWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CueListWidget(
		CueDataTableModel * model, QWidget *parent = nullptr
	);
	void SetDataSource(QList<Cue *> * cues);
	Cue * GetSelectedCue();
	void SelectRow(int rowIdx);
	int GetRowIndex();
	void RefreshLayout();
	void RefreshData();
	void RefreshData(int from, int to);

signals:
	void SelectedCueChanged(Cue * selectedCue);

private slots:
	void handleCurrentRowChanged(
		const QModelIndex &current, const QModelIndex &previous
	);

private:
	QVBoxLayout * m_layout = nullptr;
	QTableView * m_view = nullptr;
	CueDataTableModel * m_model = nullptr;
};

#endif // CUELISTWIDGET_H
