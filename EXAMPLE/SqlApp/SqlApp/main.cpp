#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

static bool createConnection( )
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    // db.setDatabaseName(":memory:"); // 메모리에 db 저장
    if (!db.open( )) return false; // database 연결

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person(id INTEGER Primary Key, "
                     "firstname VARCHAR(20) NOT NULL, lastname VARCHAR(20));");
    // 세번째는 NULL도 된다.
    // 101 <-- ID가 Auto Increment
    query.exec("INSERT INTO person VALUES(101, 'Yongsu', 'Kang');");
    query.exec("INSERT INTO person(firstname, lastname) VALUES('Soomi', 'Kim')");
    query.exec("INSERT INTO person(firstname, lastname) VALUES "
                     "('Hanmi', 'Lee'), ('YoungJin', 'Suh'), ('YoungHwa', 'Ryu');");
    return true;
}

int main(int argc, char *argv[])
{
    // 이 밑의 기능들이 매우 보편적인 SQL Lite의 기능들이다.
    QApplication app(argc, argv);

    if (!createConnection( )) return 1;
#if 0
    QSqlQueryModel queryModel;
    queryModel.setQuery("select * from person");
#else
    QSqlTableModel queryModel;
    queryModel.setTable("person");
//    queryModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
    queryModel.select( );
#endif
    queryModel.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    queryModel.setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    queryModel.setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));

    QTableView *tableview = new QTableView;
    tableview->setModel(&queryModel);
    tableview->setWindowTitle(QObject::tr("Query Model"));
    tableview->show( );

    return app.exec( );
}
