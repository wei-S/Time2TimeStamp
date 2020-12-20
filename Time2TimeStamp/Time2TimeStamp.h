#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Time2TimeStamp.h"
#include <QTimer>
#include <QDateTime>

#define TIME_OUT 1000

class Time2TimeStamp : public QMainWindow
{
	Q_OBJECT

public:
	Time2TimeStamp(QWidget* parent = Q_NULLPTR);

private:
	void init();

private slots:
	void onTimeOut();

private:
	Ui::Time2TimeStampClass ui;

	QTimer* m_pTimer;
	bool m_isRun;
};
