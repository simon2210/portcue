#include "audiocue.h"

AudioCue::AudioCue(QString filePath, QObject *parent)
	: Cue(parent), m_filePath(filePath) { }

QString AudioCue::FilePath() const
{
    return m_filePath;
}

void AudioCue::SetFilePath(const QString &filePath)
{
    m_filePath = filePath;
}

Cue::CueType AudioCue::Type()
{
    return Cue::audio;
}
