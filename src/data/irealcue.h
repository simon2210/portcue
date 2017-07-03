#ifndef IREALCUE_H
#define IREALCUE_H

#include <QString>


class IRealCue {
public:
	//pure virtual function
	virtual ~IRealCue() {}
	virtual QString FilePath() const = 0;
	virtual void SetFilePath(const QString &filePath) = 0;
};

#endif // IREALCUE_H
