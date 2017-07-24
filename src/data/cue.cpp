#include "cue.h"

Cue::Cue(QObject *parent) : QObject(parent)
{
}

QString Cue::Id() const
{
	return m_id;
}

void Cue::SetId(const QString &id)
{
	m_id = id;
}

QString Cue::Page() const
{
	return m_page;
}

void Cue::SetPage(const QString &page)
{
	m_page = page;
}

QString Cue::Description() const
{
	return m_description;
}

void Cue::SetDescription(const QString &description)
{
	m_description = description;
}
