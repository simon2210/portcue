#include "projectwriter.h"
#include "xmlproperties.h"

#include <QXmlStreamWriter>

#include <src/data/audiocue.h>

bool ProjectWriter::WriteProject(QString filePath, Project *project)
{
	QList<Cue *> cues =(* project->Cues());
	QFile file(filePath);

	if(!file.open(QFile::WriteOnly)) {
		qDebug("ProjectWriter: could not write File");
		return false;
	}

	QXmlStreamWriter writer(&file);
	writer.setAutoFormatting(true);

	writer.writeStartDocument();
	writer.writeStartElement(XML_APP_NODE);
	writer.writeStartElement(XML_PROJECT_NODE);
	writer.writeTextElement(XML_PROJECT_NAME, project->Name());
	writer.writeStartElement(XML_CUES_NODE);

	if(!cues.isEmpty()) {
		for(int i = 0; i < cues.length(); i++) {
			writer.writeStartElement(QString(XML_CUE_PREFIX) + QString::number(i));
			Cue * c = cues[i];
			writer.writeTextElement(XML_CUE_TYPE, QString::number(c->Type()));
			writer.writeTextElement(XML_CUE_ID, c->Id());
			writer.writeTextElement(XML_CUE_DESC, c->Description());
			writer.writeTextElement(XML_CUE_PAGE, c->Page());

			if(c->Type() == Cue::audio) {
				writer.writeTextElement(XML_CUE_FILEPATH, ((AudioCue *)c)->FilePath());
			}

			writer.writeEndElement(); //cue x
		}
	}

	writer.writeEndElement(); // cues
	writer.writeEndElement(); // project
	writer.writeEndElement(); // portcue

	writer.writeEndDocument();
	return true;
}
