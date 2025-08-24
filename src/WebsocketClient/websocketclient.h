#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H
#include <QWebSocket>

class WebsocketClient: public QObject
{
    Q_OBJECT
public:
    WebsocketClient(QObject *parent = nullptr);

    ~WebsocketClient();

    int connectToServer(const QUrl &url);
    void disconnectFromServer();
    bool isConnected();
    void sendTextMessage(const QString &message);
    void sendBinaryMessage(const QByteArray &data);

signals:
    void textMessageReceived(const QString &message);
    void binaryMessageReceived(const QByteArray &data);
    void connected();
    void signalDisconnected();
    void errorOccurred(const QString &errorString);
    void stateChanged(QAbstractSocket::SocketState state);

private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onTextMessageReceived(const QString &message);
    void onBinaryMessageReceived(const QByteArray &data);
    void onError(QAbstractSocket::SocketError error);

private:
    QWebSocket *m_webSocket;

    bool bConnected = false;
};

#endif // WEBSOCKETCLIENT_H
