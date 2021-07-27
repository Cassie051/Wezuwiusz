#ifndef UDPCONECT_HH
#define UDPCONECT_HH

#include <QObject>
#include <QUdpSocket>
#include <QPointer>
#include <QDataStream>

/*!
 * \brief The Udpconect class
 *
 * Klasa odpowiedzialna za stworzenie połączenia UDP i jego obsługę.
 */
class Udpconect : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Udpconect
     *
     * Konstruktor klasy Udpconect.
     * \param[in] parent- wskaźnik rodzica ustawiony na NULL pointer.
     */
    explicit Udpconect(QObject *parent = 0);
    /*!
     * \brief sayHello
     *
     * Metoda odpowiadająca za ustawienie diagramu danych, wpisującach otrzymywane wartości z ustawionego soketu.
     */
    void sayHello();

signals:
    /*!
     * \brief dataRecived
     *
     * Sygnał umożliwiający przesyłanie danych do klasy \link Viewer \endlink przy użyciu sygnału \link viewer::addXYZ \endlink.
     *
     * \param x - wychylenie w osi X z akcelerometru
     * \param y - wychylenie w osi Y z akcelerometru
     * \param z - wychylenie w osi Z z akcelerometru
     */
    void dataRecived(float x, float y, float z);


public slots:
    /*!
     * \brief readyRead
     *
     * Odczytywanie danych z bufora oraz ich odczyt z ramki i interpretacja.
     */
    void readyRead();


private:
    /*!
     * \brief socket
     *
     * Wskaźnik na soket protokołu UDP.
     */
    QUdpSocket *socket;
    /*!
     * \brief calibration
     *
     * Calibracja urządzenia uśredniająca odczyt pierwszych 100 otrzymanych danych.
     * \param cx - odczyt zmiany wychylenia w osi X z akcelerometru
     *
     * \param cy - odczyt zmiany wychylenia w osi Y z akcelerometru
     *
     * \param cz - odczyt zmiany wychylenia w osi Z z akcelerometru
     */
    void calibration(float cx, float cy, float cz);
    /*!
     * \brief calibrated
     *
     * Zmienna logiczna określając stan kalibracji urządzenia.
     */
    bool calibrated = false;
    /*!
     * \brief counter
     *
     * Licznik odczytu odpowiedniej liczby danych w trakcie procesu kalibracji za pomocą metody \link Udpconect::caliration \endlink.
     */
    int counter =0;
    /*!
     * \brief xcorrect
     *
     * Korekta danych wychylenia osi X z akcelerometru.
     */
    float xcorrect =0;
    /*!
     * \brief ycorrect
     *
     * Korekta danych wychylenia osi Y z akcelerometru.
     */
    float ycorrect =0;
    /*!
     * \brief zcorrent
     *
     * Korekta danych wychylenia osi Z z akcelerometru.
     */
    float zcorrent =0;
    /*!
     * \brief x
     *
     * Bierzący odczyt wychylenia w osi X z akcelerometru.
     *
     * \brief y
     *
     * Bierzący odczyt wychylenia w osi Y z akcelerometru.
     *
     * \brief z
     *
     * Bierzący odczyt wychylenia w osi Z z akcelerometru.
     */
    float x, y, z;

};


#endif // UDPCONECT_HH
