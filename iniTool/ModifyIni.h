#pragma once

#include <QSettings>
#include <QtWidgets/QMainWindow>
#include <QDirIterator>
#include <QVariant>
#include <string>
#include <tuple>
#include <iostream>
#include "QDir"
#include "qdebug.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "Define.h"

class ModifyIni : public QObject
{
	Q_OBJECT

public:
	bool run(QString* strlog, QString path);

private:
	std::tuple <bool, QString> modify(QString path);

signals:
	void	UpdateStep(QString text, int num);
};

