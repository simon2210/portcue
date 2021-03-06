#include "ui/mainwindow/mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
	// Create application
	QApplication app(argc, argv);

	// Set metadata
	app.setApplicationName("portcue");
	app.setApplicationVersion("0.1");
	app.setApplicationDisplayName("Portcue");
	app.setOrganizationDomain("TODO.de");
	app.setOrganizationName("TODO");
	app.setWindowIcon(QIcon(":/res/appicon.png"));

	// Load and apply stylesheet
	QFile file(":/res/stylesheet.css");
	if(file.open(QFile::ReadOnly)) {
		QString styleSheet = QLatin1String(file.readAll());
		app.setStyleSheet(styleSheet);
	}

	// Create and show MainWindow
	MainWindow window;
	window.show();

	// Exec application
	return app.exec();
}

//Known Bugs:
// SelectedCue vom CueListWidget falsch, wenn Cues hinzugefügt oder gelöscht

//ToDo:
// Editor vervollständigen (Add und Remove auch für MainCueList testen)
// IEditable für Datenobjekte?
