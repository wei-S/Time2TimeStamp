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

    //connect
    connect(ui.pushButtonCurrentContorl,&QPushButton::clicked,this,&Time2TimeStamp::onButtonCurrentContorlClick);
    connect(ui.pushButtonConvert1, &QPushButton::clicked, this, &Time2TimeStamp::onButtonTimeStamp2Time);
    connect(ui.pushButtonConvert2, &QPushButton::clicked, this, &Time2TimeStamp::onButtonTime2TimeStamp);

    //Timer
    m_pTimer = new QTimer;
    connect(m_pTimer, &QTimer::timeout, this, &Time2TimeStamp::onTimeOut);
    m_pTimer->start(TIME_OUT);

    //widget init
    //ui.dateTimeEdit1->setEnabled(false);
    //ui.lineEditTimeStamp2->setEnabled(false);
    ui.pushButtonCurrentContorl->setText("Stop");
    ui.labelCurrentTime->setStyleSheet("color:green;");

    //TimeStamp Range
    ui.lineEditTimeStamp1->setValidator(new QIntValidator(1, 10000000000, this));
    ui.lineEditTimeStamp2->setValidator(new QIntValidator(1, 10000000000, this));

    QDateTime currTime = QDateTime::currentDateTime();
    ui.labelCurrentTime->setText(QString::number(currTime.toSecsSinceEpoch()));
    ui.lineEditTimeStamp1->setText(QString::number(currTime.toSecsSinceEpoch()));
    ui.dateTimeEdit1->setDateTime(currTime);
    ui.dateTimeEdit2->setDateTime(currTime);

    //label click  event filer
    ui.labelCurrentTime->installEventFilter(this);
}

bool Time2TimeStamp::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == ui.labelCurrentTime)
    {//labelCurrentTime LeftButton Event
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent*>(event);
            if (pMouseEvent->button() == Qt::LeftButton)
            {
                ui.lineEditTimeStamp1->setText(ui.labelCurrentTime->text()); //copy
                ui.dateTimeEdit2->setDateTime(QDateTime::fromSecsSinceEpoch(ui.labelCurrentTime->text().toULongLong()));
                return true;
            }
        }
    }
    return false;
}


void Time2TimeStamp::onTimeOut()
{
	ui.labelCurrentTime->setText(QString::number(QDateTime::currentDateTime().toSecsSinceEpoch()));
}

void Time2TimeStamp::onButtonCurrentContorlClick()
{
    m_isRun = !m_isRun;
    if (m_isRun)
    {
        m_pTimer->start(TIME_OUT);
        ui.pushButtonCurrentContorl->setText("Stop");
        ui.labelCurrentTime->setStyleSheet("color:green;");
    }
    else
    {
        if (m_pTimer->isActive())
        {
            m_pTimer->stop();
            ui.pushButtonCurrentContorl->setText("Start");
            ui.labelCurrentTime->setStyleSheet("color:red;");
        }
    }
}

void Time2TimeStamp::onButtonTimeStamp2Time()
{
    qint64 timeStamp = ui.lineEditTimeStamp1->text().toULongLong();

    if (timeStamp > 0)
    {
        ui.dateTimeEdit1->setDateTime(QDateTime::fromSecsSinceEpoch(timeStamp));
    }
}

void Time2TimeStamp::onButtonTime2TimeStamp()
{
    QDateTime dt = ui.dateTimeEdit2->dateTime();
    if (!dt.isNull())
    {
        ui.lineEditTimeStamp2->setText(QString::number(dt.toSecsSinceEpoch()));
    }
}
