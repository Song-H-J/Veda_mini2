#include "thread.h"

Thread::Thread(QObject *obj) : m_stopFlag(Play)
{
    m_label = (QLabel*)obj;
}

void Thread::run()
{
    int cnt = 0;
    Q_FOREVER {
        m_mutex.lock();
        if(m_stopFlag == Stop)
            m_waitCondition.wait(&m_mutex);
        m_mutex.unlock();

        //m_label->setText(QString("run %1").arg(cnt++));
        emit setLabeled(QString("run %1").arg(cnt++));
        sleep(1);
    }
}

void Thread::stopThread()
{
    m_stopFlag = Stop;
}

void Thread::resumeThread()
{
    m_mutex.lock();
    m_stopFlag = Play;
    m_waitCondition.wakeAll();
    m_mutex.unlock();
}
