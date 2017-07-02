#include "project.h"

Project::Project(QObject *parent) : QObject(parent)
{
    m_cues = new QList<Cue *>();
}

Project::~Project()
{
    if(m_cues != nullptr)
        delete m_cues;
}

QString Project::Name() const
{
    return m_name;
}

void Project::SetName(const QString &name)
{
    m_name = name;
}

QList<Cue *> *Project::Cues() const
{
    return m_cues;
}

void Project::AddCue(Cue * cue, int idx)
{
    m_cues->insert(idx, cue);
}

void Project::RemoveCue(int idx)
{
    if(idx >= 0 && idx < m_cues->length())
        m_cues->removeAt(idx);
}

void Project::RemoveCue(Cue *cue)
{
    int idx = m_cues->indexOf(cue);

    if(idx != -1)
        m_cues->removeAt(idx);
}
