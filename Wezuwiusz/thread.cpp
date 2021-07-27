#include "thread.hh"


Thread::Thread(Udpconect *client, QObject *parent) :
    QThread(parent)
{
    ptr_client = client;

}
void Thread::run()
{
   ptr_client->sayHello();
   ptr_client->readyRead();
}
