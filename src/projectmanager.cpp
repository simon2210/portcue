#include "projectmanager.h"

#include "src/io/projectreader.h"
#include "src/io/projectwriter.h"

#include <QObject>

ProjectManager *ProjectManager::Instance()
{
    static ProjectManager instance;
    return &instance;
}

Project *ProjectManager::GetProject() const
{
    return m_project;
}

bool ProjectManager::SaveProject()
{
    return this->SaveProject(m_projectPath);
}

bool ProjectManager::SaveProject(QString filePath)
{
    emit ProjectSaving();

    if(m_project == nullptr)
        return false;

    if(filePath.isNull() || filePath.isEmpty())
        return false;

    m_projectPath = filePath;
    bool success = ProjectWriter::WriteProject(filePath, m_project);
    emit ProjectSaved();

    return success;
}

bool ProjectManager::OpenProject(QString filePath)
{
    if(m_project != nullptr)
        this->CloseProject();

    Project * newProject = ProjectReader::ReadProject(filePath);

    if(newProject == nullptr)
        return false;

    m_projectPath = filePath;
    m_project = newProject;

    emit ProjectOpened();
    emit ProjectLoaded();

    return true;
}

void ProjectManager::CreateProject(QString projectName)
{
    if(m_project != nullptr)
        this->CloseProject();

    Project * newProject = new Project();
    newProject->SetName(projectName);

    m_project = newProject;
    m_projectPath = nullptr;

    emit ProjectLoaded();
}

void ProjectManager::CloseProject()
{
    emit ProjectClosing();
    if(m_project != nullptr) {
        delete m_project;
        m_project = nullptr;
    }
    m_projectPath = nullptr;
}

void ProjectManager::AddCue(Cue *cue, int index)
{
    if(m_project == nullptr || index < 0)
        return;

    m_project->AddCue(cue, index);
    emit CueAdded(cue, index);
}

void ProjectManager::RemoveCue(int index)
{
    m_project->RemoveCue(index);
    emit CueRemoved();
}

void ProjectManager::RemoveCue(Cue *cue)
{
    m_project->RemoveCue(cue);
	emit CueRemoved();
}

void ProjectManager::MoveCue(Cue * cue, int newIndex)
{
	QList<Cue *> *cues = m_project->Cues();
	if(newIndex < 0  || newIndex >= cues->length())
		return;

	int currentIdx = cues->indexOf(cue);

	if(currentIdx >= 0) {
		m_project->Cues()->move(currentIdx, newIndex);
		emit CueMoved(currentIdx, newIndex);
	}
}

QString ProjectManager::ProjectPath() const
{
    return m_projectPath;
}
