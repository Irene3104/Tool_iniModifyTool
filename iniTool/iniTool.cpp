#include "iniTool.h"
#include "Modifyini.h"

iniTool::iniTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

	m_ModifyIni = new ModifyIni;


	QCoreApplication::setApplicationName("iniTool 1.0.0.0");
	setWindowTitle(QCoreApplication::applicationName());

	ui.progressBar->setTextVisible(true);
	ui.progressBar->setFormat("Ready");
	ui.progressBar->setAlignment(Qt::AlignCenter);
	ui.progressBar->setValue(0);
	ui.progressBar->setMaximum(100);

	this->ConnectionSignalSlot();
}

iniTool::~iniTool()
{}

void iniTool::ConnectionSignalSlot()
{
	connect(ui.btn_path, &QPushButton::clicked, this, &iniTool::BtnClicked_DirPath);
	connect(ui.btn_click, &QPushButton::clicked, this, &iniTool::BtnClicked_InputName);
	connect(this->m_ModifyIni, static_cast<void(ModifyIni::*)(QString, int)>(&ModifyIni::UpdateStep), this, &iniTool::ViewProgress);
}

void iniTool::BtnClicked_InputName()
{
	ui.btn_path->setEnabled(false);
	ui.btn_click->setEnabled(false);
	ui.textBrowser->setText("");
	bool isSuccess = false;
	QString resultText;
	QString strMsgBox;
	QString filePath = ui.lineEdit->text();

	if (filePath.isEmpty())
	{
		QMessageBox msgBox(QMessageBox::Warning, "Warning", "Please input the path", QMessageBox::Ok);
		msgBox.exec();
	}
	else
	{
		isSuccess = this->m_ModifyIni->run(&resultText, filePath);
		strMsgBox = (isSuccess == true) ? SucText : FailText;
		ui.textBrowser->setText(resultText);
		QMessageBox msgBox(QMessageBox::Information, "Information", strMsgBox, QMessageBox::Ok);
		msgBox.exec();
	}

	ui.btn_path->setEnabled(true);
	ui.btn_click->setEnabled(true);
}

void iniTool::BtnClicked_DirPath()
{
	QLineEdit* pEdit = nullptr;
	pEdit = ui.lineEdit;
	if (pEdit != nullptr)
		pEdit->setText(GetPaths(pEdit->text()));
}

QString iniTool::GetPaths(QString pathLine)
{
	QString inputPath = "";
	QDir selectedDir(pathLine);

	if (pathLine.isEmpty())
	{
		inputPath = QFileDialog::getExistingDirectory(this, ("Select File"), QApplication::applicationDirPath());
		return inputPath;
	}
	else
	{
		if (selectedDir.exists())
		{
			inputPath = QFileDialog::getExistingDirectory(this, ("Select File"), pathLine);
			if (inputPath == false)
				return pathLine;
			else
				return inputPath;
		}
		else
		{
			inputPath = QFileDialog::getExistingDirectory(this, ("Select File"), QApplication::applicationDirPath());
			return inputPath;
		}
	}
}

void iniTool::ViewProgress(QString text, int num)
{
	ui.progressBar->setFormat(text);
	ui.progressBar->setValue(num);
}
