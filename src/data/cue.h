#ifndef CUE_H
#define CUE_H

#include <QObject>

// Abstract basic class
class Cue : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString Id READ Id WRITE SetId)
	Q_PROPERTY(QString Description READ Description WRITE SetDescription)
	Q_PROPERTY(QString Page READ Page WRITE SetPage)
	Q_PROPERTY(CueType Type READ Type)

public:
	enum CueType : int{
		undefined = 0,
		audio = 1,
		video = 2,
		simulated = 4
	};

	explicit Cue(QObject *parent = nullptr);
	virtual ~Cue() {}

	QString Id() const;
	void SetId(const QString &id);

	QString Page() const;
	void SetPage(const QString &page);

	virtual CueType Type() = 0;

	QString Description() const;
	void SetDescription(const QString &description);

private:
	QString m_id = nullptr;
	QString m_description = nullptr;
	QString m_page = nullptr;
};

#endif // CUE_H
