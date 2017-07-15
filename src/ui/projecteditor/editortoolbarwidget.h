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
	void AddAudioCueClicked();
	void RemoveCueBtnClicked();
	void MoveUpBtnClicked();
	void MoveDownBtnClicked();

private slots:
	void handleSaveProjectBtnClicked(bool);
	void handleAddAudioCueBtnClicked(bool);
	void handleRemoveCueBtnClicked(bool);
	void handleMoveUpBtnClicked(bool);
	void handleMoveDownBtnClicked(bool);

private:
    void setTexts();

	QHBoxLayout * m_layout = nullptr;
	QPushButton * m_saveProjectBtn = nullptr;
	QPushButton * m_addAudioCueBtn = nullptr;
	QPushButton * m_removeCueBtn = nullptr;
	QPushButton * m_moveUpBtn = nullptr;
	QPushButton * m_moveDownBtn = nullptr;
};

#endif // MAINTOOLBARWIDGET_H
