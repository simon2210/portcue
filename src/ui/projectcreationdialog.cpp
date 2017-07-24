#include "projectcreationdialog.h"

ProjectCreationDialog::ProjectCreationDialog(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f) {
	m_layout = new QHBoxLayout(this);
	m_projetNameLbl = new QLabel(this);
	m_projectEdit = new QLineEdit(this);
	m_okBtn = new QPushButton(this);

	m_okBtn->setEnabled(false);
	setTexts();

	connect(m_projectEdit, &QLineEdit::textChanged,
			this, [=](QString text) {
		bool enabled = !text.isNull() && !text.simplified().isEmpty();
		m_okBtn->setEnabled(enabled);
	});

	connect(m_okBtn, &QPushButton::clicked, this, [=](bool) {
		this->accept();
	});

	m_layout->addWidget(m_projetNameLbl);
	m_layout->addWidget(m_projectEdit);
	m_layout->addWidget(m_okBtn);
}

QString ProjectCreationDialog::GetProjectName()
{
	return m_projectEdit->text();
}

void ProjectCreationDialog::setTexts()
{
	m_projetNameLbl->setText(tr("Project name:"));
	m_okBtn->setText(tr("OK"));
}
