#include "cueaudiowidget.h"

CueAudioWidget::CueAudioWidget(QWidget *parent) : QWidget(parent)
{
	m_testLbl = new QLabel(this);
}

void CueAudioWidget::SetDataSource(AudioCue *audioCue)
{
	m_cue = audioCue;
	m_testLbl->setText("Audiofile: " + m_cue->FilePath());
}
