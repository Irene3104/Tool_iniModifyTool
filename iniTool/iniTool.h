#pragma once

#include <QSettings>
#include <QtWidgets/QMainWindow>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QDebug>

#include "QDir"
#include "qdebug.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "ui_iniTool.h"
#include "Define.h"

class ModifyIni;

class iniTool : public QMainWindow
{
    Q_OBJECT

public:
    iniTool(QWidget *parent = nullptr);
    ~iniTool();


private:
	void ConnectionSignalSlot();
	void BtnClicked_DirPath();
	void BtnClicked_InputName();
	void ViewProgress(QString text, int num);

	QString GetPaths(QString pathLine);


private:
    Ui::iniToolClass ui;
	ModifyIni* m_ModifyIni = nullptr;
};
