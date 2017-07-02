#include "audiocue.h"

AudioCue::AudioCue(QObject *parent) : Cue(parent)
{

}

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
