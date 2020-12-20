#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Time2TimeStamp.h"
#include <QTimer>
#include <QDateTime>
#include <QEvent>
#include <QMouseEvent>

#define TIME_OUT 1000

class Time2TimeStamp : public QMainWindow
{
	Q_OBJECT

public:
	Time2TimeStamp(QWidget* parent = Q_NULLPTR);

protected:
	bool eventFilter(QObject* obj, QEvent* event);
private:
	void init();

private slots:
	void onTimeOut();
	void onButtonCurrentContorlClick();
	void onButtonTimeStamp2Time();
	void onButtonTime2TimeStamp();

private:
	Ui::Time2TimeStampClass ui;

	QTimer* m_pTimer;
	bool m_isRun;
};
