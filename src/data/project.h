#ifndef PROJECT_H
#define PROJECT_H

#include "cue.h"

#include <QObject>
#include <QList>

class Project : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ Name WRITE SetName)
    Q_PROPERTY(QList<Cue *> Cues READ Cues)

public:
    explicit Project(QObject *parent = nullptr);
    ~Project();

    QString Name() const;
    void SetName(const QString &name);

    QList<Cue *> * Cues() const;
    void AddCue(Cue * cue, int idx);
    void RemoveCue(int idx);
    void RemoveCue(Cue * cue);


private:
    QString m_name = nullptr;
    QList<Cue *> * m_cues = nullptr;

};

#endif // PROJECT_H
