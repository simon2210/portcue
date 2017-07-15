#ifndef CUEEDITWIDGET_H
#define CUEEDITWIDGET_H

#include <QBoxLayout>
#include <QWidget>
#include <QPaintEvent>

#include "src/data/cue.h"
#include "cueaudiowidget.h"
#include "cuemetawidget.h"

class CueEditWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CueEditWidget(QWidget *parent = nullptr);
	void SetDataSource(Cue * cue);

protected:
	void paintEvent(QPaintEvent *event);

private:
	Cue * m_cue = nullptr;

	QVBoxLayout * m_layout = nullptr;
	CueMetaWidget * m_metaWidget = nullptr;
	CueAudioWidget * m_audioWidget = nullptr;
	QWidget * m_currentTypeWidget = nullptr;
};

#endif // CUEEDITWIDGET_H
