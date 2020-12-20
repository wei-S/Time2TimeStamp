#include "Time2TimeStamp.h"

Time2TimeStamp::Time2TimeStamp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    init();
}

void Time2TimeStamp::init()
{
    m_isRun = true;

    m_pTimer = new QTimer;
    connect(m_pTimer, &QTimer::timeout, this, &Time2TimeStamp::onTimeOut);
    m_pTimer->start(TIME_OUT);

    //widget init
    ui.dateTimeEdit1->setEnabled(false);
    ui.lineEditTimeStamp2->setEnabled(false);

    QDateTime currTime = QDateTime::currentDateTime();
    ui.labelCurrentTime->setText(QString::number(currTime.toSecsSinceEpoch()));
    ui.lineEditTimeStamp1->setText(QString::number(currTime.toSecsSinceEpoch()));
    ui.dateTimeEdit1->setDateTime(currTime);
    ui.dateTimeEdit2->setDateTime(currTime);
}

void Time2TimeStamp::onTimeOut()
{
    ui.labelCurrentTime->setText(QString::number(QDateTime::currentDateTime().toSecsSinceEpoch()));
}