#include "udpconect.hh"
#define DATACALIB 100

Udpconect::Udpconect(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind( QHostAddress("192.168.1.24"), 1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Udpconect :: sayHello()
{
    QByteArray Data;
    socket->writeDatagram(Data,  QHostAddress("192.168.1.24"), 1234);
}

void Udpconect::calibration(float cx, float cy, float cz)
{

    if(counter < DATACALIB)
    {
        xcorrect += cx;
        ycorrect += cy;
        zcorrent += cz;
        counter ++;
    }
    else
    {
       xcorrect += cx;
       ycorrect += cy;
       zcorrent += cz;
       xcorrect /= DATACALIB;
       ycorrect /= DATACALIB;
       zcorrent /= DATACALIB;
       calibrated = true;
       qDebug() << "Device is calibrated";
    }
}

void Udpconect::readyRead()
{
    QByteArray Buffer;
    Buffer.resize((socket->pendingDatagramSize()));

    if(socket->hasPendingDatagrams())
    {

    }

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(), &sender, &senderPort);

    QDataStream *ds = new QDataStream(Buffer);
    ds->setFloatingPointPrecision(QDataStream::SinglePrecision);
    float tmptab[17];
    for(int i =0 ;i<17; i++)
    {
        (*ds)>>tmptab[i];
    }

    delete ds;

    if(!calibrated)
    {
        calibration(tmptab[0], tmptab[1], tmptab[2]);
    }
    else
    {
        x = tmptab[0] - xcorrect;
        y = tmptab[1] - ycorrect;
        z = tmptab[2] - zcorrent;
        emit dataRecived(x, y, z);
    }
}

