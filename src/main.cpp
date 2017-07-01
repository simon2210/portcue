#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("portcue");
    app.setApplicationVersion("0.1");
    app.setApplicationDisplayName("Portcue");
    app.setOrganizationDomain("TODO.de");
    app.setOrganizationName("TODO");
    app.setWindowIcon(QIcon(":/res/appicon.png"));

    MainWindow window;
    window.show();

    return app.exec();
}
