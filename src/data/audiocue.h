#ifndef AUDIOCUE_H
#define AUDIOCUE_H

#include "cue.h"
#include "irealcue.h"

class AudioCue : public Cue, IRealCue
{
	Q_PROPERTY(QString FilePath READ FilePath WRITE SetFilePath)

public:
	explicit AudioCue(QString filePath, QObject *parent = nullptr);

	QString FilePath() const override;
	void SetFilePath(const QString &filePath) override;

private:
	QString m_filePath = nullptr;

	// Cue interface
public:
	CueType Type();
};

#endif // AUDIOCUE_H
