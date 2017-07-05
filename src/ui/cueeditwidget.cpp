#include "cueeditwidget.h"

#include <QPainter>
#include <QStyleOption>

CueEditWidget::CueEditWidget(QWidget *parent) : QWidget(parent)
{
	m_layout = new QVBoxLayout(this);
	m_metaWidget = new CueMetaWidget(this);

	m_layout->addWidget(m_metaWidget);
}

void CueEditWidget::SetDataSource(Cue *cue)
{
	if(cue == nullptr)
		return;

	m_cue = cue;

	if(m_currentTypeWidget != nullptr)
		m_layout->removeWidget(m_currentTypeWidget);

	m_metaWidget->SetDataSource(m_cue);

	if(m_cue->Type() == Cue::audio) {
		if(m_audioWidget == nullptr)
			m_audioWidget = new CueAudioWidget(this);

		m_audioWidget->SetDataSource((AudioCue *)m_cue);
		m_currentTypeWidget = m_audioWidget;
	}

	m_layout->addWidget(m_currentTypeWidget);
}

void CueEditWidget::paintEvent(QPaintEvent */*event*/)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
