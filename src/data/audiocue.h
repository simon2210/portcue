#ifndef AUDIOCUE_H
#define AUDIOCUE_H

#include "src/data/cue.h"

class AudioCue : public Cue
{
    Q_PROPERTY(QString FilePath READ FilePath WRITE SetFilePath)

public:
    explicit AudioCue(QObject *parent = nullptr);

    QString FilePath() const;
    void SetFilePath(const QString &filePath);

private:
    QString m_filePath = nullptr;

    // Cue interface
public:
    CueType Type();
};

#endif // AUDIOCUE_H
