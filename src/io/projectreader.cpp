#include "projectreader.h"
#include "xmlproperties.h"

#include <QXmlStreamWriter>

#include <src/data/audiocue.h>


Project *ProjectReader::ReadProject(QString filePath)
{
    QFile file(filePath);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug("ProjectReader: Could not read file!");
        return nullptr;
    }

    Project * project = new Project();
    QXmlStreamReader reader(&file);

    reader.readNextStartElement();
    if (reader.name() != XML_APP_NODE)
          return nullptr;

    reader.readNextStartElement();
    if(reader.name() != XML_PROJECT_NODE)
        return nullptr;

    reader.readNextStartElement();
    if(reader.name() == XML_PROJECT_NAME) {
        QString projectName = reader.readElementText();
        project->SetName(projectName);
    }

    reader.readNextStartElement();
    if(reader.name() != XML_CUES_NODE)
        return project;

    int cueCounter = 0;
    while(reader.readNextStartElement()){
          if(reader.name().startsWith(XML_CUE_PREFIX)){
              reader.readNextStartElement();

              if(reader.name() != XML_CUE_TYPE)
                  return project;

              int readType = reader.readElementText().toInt();
              Cue::CueType cueType = (Cue::CueType)readType;

              Cue * cue = nullptr;
              if(cueType == Cue::audio) {
                cue = new AudioCue(project);
              }
              project->AddCue(cue, cueCounter);

              reader.readNextStartElement();
              QString xmlName = reader.name().toString();
              while(
                    xmlName == XML_CUE_ID || xmlName == XML_CUE_FILEPATH
                    || xmlName == XML_CUE_PAGE || xmlName == XML_CUE_DESC
                ) {
                  if(reader.name() == XML_CUE_ID) {
                    QString cueId = reader.readElementText();
                    cue->SetId(cueId);
                  } else if(reader.name() == XML_CUE_DESC) {
                      QString desc = reader.readElementText();
                      cue->SetDescription(desc);
                  } else if (reader.name() == XML_CUE_PAGE) {
                      QString cuePage = reader.readElementText();
                      cue->SetPage(cuePage);
                  } else if (reader.name() == XML_CUE_FILEPATH) {
                      QString cuePath = reader.readElementText();
                      if(cueType == Cue::audio)
                        ((AudioCue *)cue)->SetFilePath(cuePath);
                  }
                  reader.readNextStartElement();
                  xmlName = reader.name().toString();
              }
              cueCounter++;
          }
          else {
              reader.skipCurrentElement();
          }
    }

    return project;
}
