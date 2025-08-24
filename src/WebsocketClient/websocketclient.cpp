#include "websocketclient.h"

WebsocketClient::WebsocketClient(QObject *parent)
    :QObject(parent)
{
    m_webSocket = new QWebSocket();
    connect(m_webSocket, &QWebSocket::connected, this, &WebsocketClient::onSocketConnected);
    connect(m_webSocket, &QWebSocket::disconnected, this, &WebsocketClient::onSocketDisconnected);
    connect(m_webSocket, &QWebSocket::textMessageReceived, this, &WebsocketClient::onTextMessageReceived);
    connect(m_webSocket, &QWebSocket::errorOccurred, this, &WebsocketClient::onError);

    connect(this, &WebsocketClient::signalDisconnected, []()
    {
        qInfo() << "signalDisconnected slot doing";
    });
}

WebsocketClient::~WebsocketClient()
{

}

int WebsocketClient::connectToServer(const QUrl &url)
{
    if (m_webSocket)
    {
        m_webSocket->open(url);
    }
    return 0;
}

void WebsocketClient::disconnectFromServer()
{
    if (m_webSocket)
    {
        // 断开连接使用close而不是disconnected
        m_webSocket->close();
    }

}

bool WebsocketClient::isConnected()
{
    return bConnected;
}

void WebsocketClient::sendTextMessage(const QString &message)
{

}

void WebsocketClient::sendBinaryMessage(const QByteArray &data)
{

}

void WebsocketClient::onSocketConnected()
{
    qInfo() << "Websocket connected";
    bConnected = true;
    emit this->connected();

}

void WebsocketClient::onSocketDisconnected()
{
    qInfo() << "Websocket disconnect";
    bConnected = false;
    emit this->signalDisconnected();
    qInfo() << "signal disconnectd emited";
}

void WebsocketClient::onTextMessageReceived(const QString &message)
{
    qInfo() << "Websocket message Received: " << message;
    emit this->textMessageReceived(message);
}

void WebsocketClient::onBinaryMessageReceived(const QByteArray &data)
{

}

void WebsocketClient::onError(QAbstractSocket::SocketError error)
{
    qInfo() << "Websocket onError: " <<  error;
    emit errorOccurred(m_webSocket->errorString());
}


