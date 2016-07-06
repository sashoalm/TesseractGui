#ifndef THREAD_H
#define THREAD_H

class QString;
class QObject;
void runThread(const QString &imageFile, QObject *receiver, volatile bool *cancelFlag, volatile bool *isRunning);

#endif // THREAD_H
