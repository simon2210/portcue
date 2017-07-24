#ifndef PROJECTWRITER_H
#define PROJECTWRITER_H

#include <QString>

#include "src/data/project.h"


class ProjectWriter
{
public:
	static bool WriteProject(
		QString filePath, Project * project
	);

private:
	// Static class
	ProjectWriter() {}
};

#endif // PROJECTWRITER_H
