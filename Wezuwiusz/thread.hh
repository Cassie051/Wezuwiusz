#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "udpconect.hh"
#include <QDebug>

/*!
 * \brief The Thread class
 * Klasa tworzaca wątek odpowiedzialnu z aobsługę połączenia UDP.
 */
class Thread : public QThread
{
        Q_OBJECT
    public:
    /*!
         * \brief Thread
         *
         * Konstruktor klasy \link Volcano \endlink wywołuję funkcję \link Volcano::init \endlink co pozwala rozpoczecie połączenia.
         *
         * \param client
         *
         * Parametr przekazujący wskaźnik na obiekt klasy \link Udpconect \endlink.
         *
         * \param[in] parent- wskaźnik rodzica ustawiony na NULL pointer.
         */
        explicit Thread(Udpconect *client, QObject *parent = 0);

     /*!
         * \brief run
         *
         * Metoda tworzaca połączenie protokołu z obiektem klasy \link Udpconect \endlink.
         */
        void run();
    private:
        /*!
         * \brief ptr_client
         *
         * Wskaźnik na na obiekt klasy \link Udpconect \endlink przekazany w trakcie inicjalizacji klasy.
         */
        Udpconect *ptr_client;
};

#endif // THREAD_H
