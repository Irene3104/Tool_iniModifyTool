#include "ModifyIni.h"
#include <QTextCodec>

//QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");

std::tuple <bool, QString> ModifyIni::modify(QString path)
{
	int count = 0;
	int alldata = 0;
	int updatedData = 0;
	bool result = false;
	QString failLog;
	QString resultText = "";

	QString filePath = path;
	QString strDataOrigin = filePath + "/";
	strDataOrigin.replace("/", "\\");

	QStringList strfilter;
	strfilter << "*.ini";
	QDirIterator iterDir(strDataOrigin, strfilter, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
	std::list <QFileInfo> iniFileList;
	while (iterDir.hasNext())
	{
		iterDir.next();
		iniFileList.push_back(QFileInfo(iterDir.filePath()));
	}
	foreach(QFileInfo iniFileInfo, iniFileList)
	{
		alldata = iniFileList.size();

		QString striniFilePath = iniFileInfo.filePath();
		striniFilePath.replace("/", "\\");

		QSettings settings(striniFilePath, QSettings::IniFormat);
		settings.setIniCodec(QTextCodec::codecForName("Shift-JIS"));
		int GetId = settings.value("kanjainfo/kanja_cd").toInt();
		QString strGetName = settings.value("kanjainfo/kana_name").toString();
		
		QString strSetName = settings.value("kanjainfo/knj_name").toString();
		
		if (strGetName.isEmpty())
		{
			QString strEmptyName = "Emergency_" + QString::number(GetId);
			settings.setValue("kanjainfo/kana_name", strEmptyName);
			strGetName = settings.value("kanjainfo/kana_name").toString();
			if (strSetName.isEmpty())
			{
				settings.setValue("kanjainfo/knj_name",strGetName);
				updatedData++;
			}
			else
			{
				settings.setValue("kanjainfo/knj_name", strGetName);
				updatedData++;
			}
		}
		else 
		{
			if (strSetName.isEmpty())
			{
				settings.setValue("kanjainfo/knj_name", strGetName);
				updatedData++;
			}
			else
				updatedData++;
		}
		settings.endGroup();
		count = updatedData / (double)alldata * 100;
		emit UpdateStep("Processing Uapdate...", count);
		
		result = true;
	}
	
	//ini 이름 input된 환자 수
	QString modifiedPat;
	if (updatedData > 0)
	{
		modifiedPat = "Number of modified patient = " + QString::number(updatedData);
		qDebug() << modifiedPat << endl;
	}
	else if(updatedData == 0)
	{
		modifiedPat = "Number of modified patient = 0";
		qDebug() << modifiedPat << endl;
	}
	else
	{
		modifiedPat = "Not exists ini file to modify.";
		qDebug() << modifiedPat << endl;
	}

	return std::make_tuple(result, modifiedPat);
}

bool ModifyIni::run(QString* strlog, QString path)
{
	std::tuple <bool, QString> resultInfo;
	resultInfo = modify(path);
	bool result = false;
	result = std::get<0>(resultInfo);
	QString resultLog = std::get<1>(resultInfo);
	*strlog += ((result == true) ? SucText : FailText) + ObjectText_modify + "\n" + resultLog;
	
	if (result == false)
		return false;

	emit UpdateStep("100%", 100);
	return result;
}
