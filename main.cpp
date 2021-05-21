#include <iostream>
#include <string>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
using namespace std;

int getPort()
{
    int port;
    cout << "Enter the port number." << endl;
    cin >> port;
    return port;
}

QString getIP()
{
    cout << "Enter the IP address." << endl;
    string ip;
    cin >> ip;
    return QString::fromStdString(ip);
}

QString readFromSocket(QTcpSocket& socket)
{
    socket.waitForReadyRead(-1);
    QByteArray bytes = socket.read(1000);
    return QString::fromUtf8(bytes);
}

void printConsole(QString message)
{
    cout << message.toStdString() << endl;
}

QString readConsole()
{
    cin >> ws;
    string str;
    getline(cin, str);
    return QString::fromStdString(str);
}

void writeToSocket(QTcpSocket& socket, QString message)
{
    socket.write(message.toUtf8());
    socket.waitForBytesWritten(-1);
}

void Server()
{
    QTcpSocket *socket;
    QTcpServer ser;

    int port = getPort();

    bool listenStatus = ser.listen(QHostAddress::AnyIPv4, port);
    if (listenStatus == 1)
    {
        cout << "The port was listened to successfully." << endl;
    }
    else
    {
        cout << "The port was listened to unsuccessfully." << endl;
        return;
    }

    bool checkingTheConnection =  ser.waitForNewConnection(60000);
    if (checkingTheConnection == 1)
    {
       cout << "Connection successful!" << endl;
    }
    else
    {
        cout << "Connection unsuccessful!" << endl;
    }

    socket = ser.nextPendingConnection();
    while (true)
    {
        QString message = readFromSocket(*socket);
        printConsole(message);
        message = readConsole();
        writeToSocket(*socket, message);
    }
}

void Client()
{
    QTcpSocket socket;
    int port = getPort();
    socket.connectToHost(getIP(), port);
    bool checkingTheConnection = socket.waitForConnected(60000);

    if (checkingTheConnection == 1)
    {
        cout << "Connection successful!" << endl;
    }
    else
    {
        cout << "Connection unsuccessful!" << endl;
        return;
    }

    while (true)
    {
        QString message;
        message = readConsole();
        writeToSocket(socket, message);
        message = readFromSocket(socket);
        printConsole(message);
    }
}

int main()
{
    string s;
    while (true)
    {
        cout << "Server or Client?" << endl;
        getline(cin, s);
        if (s != "Server" && s != "Client")
        {
            continue;
        }
        else
        {
            break;
        }
    }

    if (s == "Server")
    {
        Server();
    }
    else
    if (s == "Client")
    {
        Client();
    }

    return 0;
}
