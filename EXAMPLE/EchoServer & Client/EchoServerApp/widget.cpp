#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>
#include "widget.h"

#define BLOCK_SIZE      1024

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // 서버 상태 알려줄 라벨
    infoLabel = new QLabel(this);

    // 종료 버튼과 클릭 시그널과 quit 슬롯 연결
    QPushButton* quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked( )), qApp, SLOT(quit( )));
    
    // 종료 버튼 1개짜리 Hbox
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    // 정보 라벨과 버튼 라벨을 세로로 쌓는다.
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    // tcpServer
    // SIGNAL : newConnection | SLOT  : clientConnect
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection( )), SLOT(clientConnect( )));

    // tcpServer->listen : 서버 시작
    // 시작 못 하면 서버 GUI 창에 에러 출력
    if (!tcpServer ->listen( )) {
        QMessageBox::critical(this, tr("Echo Server"), \
                              tr("Unable to start the server: %1.") \
                              .arg(tcpServer->errorString( )));
        close( );
        return;
    }

    // 정보 라벨에 서버 포트 번호 출력(정상 연결 시)
    infoLabel->setText(tr("The server is running on port %1.")
                                    .arg(tcpServer->serverPort( )));
    setWindowTitle(tr("Echo Server"));
}

// clientConnect Slot :
// 클라이언트가 연결되었다면, 
void Widget::clientConnect( )
{
    // 새 클라이언트와 연결 처리
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection( );

    // 연결 끊기면 deleteLater Slot
    connect(clientConnection, SIGNAL(disconnected( )), \
                 clientConnection, SLOT(deleteLater( )));

    // 읽을 준비가 됐다면, echoData Slot
    connect(clientConnection, SIGNAL(readyRead( )), SLOT(echoData( )));
    infoLabel->setText("new connection is established...");
}

// echoData Slot :
// client한테서 데이터를 수신하면,
void Widget::echoData( )
{
    // 데이터를 보낸 놈의 소켓을 얻고,
    QTcpSocket *clientConnection = (QTcpSocket *)sender( );
    if (clientConnection->bytesAvailable( ) > BLOCK_SIZE) return;

    // 읽는 데이터를 bytearray에 저장하고, clinet에게 에코를 날린다.
    QByteArray bytearray = clientConnection->read(BLOCK_SIZE);
    clientConnection->write(bytearray);
    infoLabel->setText(QString(bytearray));
}

