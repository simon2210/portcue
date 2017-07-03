#ifndef MAINTOOLBARWIDGET_H
#define MAINTOOLBARWIDGET_H

#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>

class EditorToolbarWidget : public QWidget
{
    Q_OBJECT
public:
	explicit EditorToolbarWidget(QWidget *parent = nullptr);

signals:
	void SaveProjectClicked();

private slots:
	void handleSaveProjectBtnClicked(bool);

private:
    void setTexts();

	QHBoxLayout * m_layout = nullptr;
	QPushButton * m_saveProjectBtn = nullptr;
};

#endif // MAINTOOLBARWIDGET_H
