#ifndef THREAD_H
#define THREAD_H

class QString;
class QObject;
void runThread(const QString &imageFile, QObject *receiver);

#endif // THREAD_H
