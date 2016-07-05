#ifndef THREAD_H
#define THREAD_H

class QString;
class QObject;
void runThread(const QString &imageFile, QObject *receiver, volatile bool *cancelFlag);

#endif // THREAD_H
