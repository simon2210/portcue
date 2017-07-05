#ifndef CUEAUDIOWIDGET_H
#define CUEAUDIOWIDGET_H

#include <QWidget>
#include <QLabel>

#include "src/data/audiocue.h"

class CueAudioWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CueAudioWidget(QWidget *parent = nullptr);
	void SetDataSource(AudioCue * audioCue);

private:
	AudioCue * m_cue = nullptr;
	QLabel * m_testLbl = nullptr;
};

#endif // CUEAUDIOWIDGET_H
