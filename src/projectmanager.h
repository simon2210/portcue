#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>

#include <src/data/project.h>

class ProjectManager : public QObject
{
    Q_OBJECT

public:
//    ProjectManager(ProjectManager const&) = delete;
//    void operator=(ProjectManager const&) = delete;

    static ProjectManager * Instance();

    Project * GetProject() const;
    bool SaveProject();
    bool SaveProject(QString filePath);
    bool OpenProject(QString filePath);
    void CreateProject(QString projectName);
    void CloseProject();

    void AddCue(Cue * cue, int index);
    void RemoveCue(int index);
    void RemoveCue(Cue * cue);

    QString ProjectPath() const;

signals:
    void ProjectOpened();
    void ProjectLoaded();
    void ProjectSaving();
    void ProjectSaved();
    void ProjectClosing();

    void CueAdded(Cue * cue, int index);
    void CueRemoved();

private:
    explicit ProjectManager(QObject *parent = nullptr) : QObject(parent) {}
    Project * m_project = nullptr;
    QString m_projectPath = nullptr;
};

#endif // PROJECTMANAGER_H
