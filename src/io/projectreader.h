#ifndef PROJECTREADER_H
#define PROJECTREADER_H

#include "src/data/project.h"

class ProjectReader
{
public:
	static Project * ReadProject(QString filePath);

private:
	//Static class
	ProjectReader() { }
};

#endif // PROJECTREADER_H
