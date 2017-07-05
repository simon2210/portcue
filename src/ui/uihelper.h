#ifndef UIHELPER_H
#define UIHELPER_H

#include <QString>
#include <QWidget>


namespace Ui {
	class UiHelper;
}

class UiHelper : public QObject
{
	 Q_OBJECT

public:
	static bool ShowSaveProjectDlg(QString * projectPath, QWidget * parent = nullptr);
	static void ShowSaveErrorMsgBox(QWidget * parent = nullptr);

	static bool ShowOpenProjectDlg(QString * projectPath, QWidget * parent = nullptr);
	static void ShowOpenErorMsgBox(QWidget * parent = nullptr);

	static bool ShowOpenAudioDlg(QStringList * files, QWidget * parent = nullptr);

private:
	//Static class
	UiHelper() : QObject(nullptr) { }
};

#endif // UIHELPER_H
