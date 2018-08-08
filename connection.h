#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
            "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");
//        db.setHostName("192.168.2.82");   						//127.0.0.1也是一样的,属于本地地址
//        db.setUserName("root");       							//登陆MYSQL的用户名
//        db.setPassword("123456");    							//你自己登陆的密码
//        db.setPort(3306);
//        db.setDatabaseName("school");  						//登陆数据库的名称
//            qDebug()<<QSqlDatabase::drivers()<<endl;
//                    								//打开数据库连接
//            if (!db.open()) {
//                QMessageBox::critical(0, "Cannot open database1",
//                    "Unable to establish a database connection.", QMessageBox::Cancel);
////                qDebug() <<db.lastError();
//                return false;
//            }

    QSqlQuery query;

    query.exec(QString("create table goods (id varchar primary key, name varchar ,kind varchar,remark varchar)"));
    query.exec(QString("insert into goods values('123456789012', '天地玄黄','小瓶','')"));
    query.exec(QString("insert into goods values('23456789012',  '宇宙洪荒','大瓶','')"));
    query.exec(QString("insert into goods values('323456789012', '日月盈昃','250g','')"));
    query.exec(QString("insert into goods values(1, '星宿列张','100ml','')"));
    query.exec(QString("insert into goods values(2, '寒来暑往' ,'仿制','')"));
    query.exec(QString("insert into goods values(3, '秋收冬藏' ,'红色包装','')"));
    query.exec(QString("insert into goods values('4', '闰余成岁' ,'红色包装','')"));

    query.exec(QString("create table supplier (id int primary key, name varchar ,address varchar,person varchar,phone varchar,remark varchar)"));
    query.exec(QString("create table customer (id int primary key, name varchar ,address varchar,person varchar,phone varchar,remark varchar)"));
    query.exec(QString("create table shop     (id int primary key, name varchar ,address varchar,person varchar,phone varchar,remark varchar)"));


    query.exec(QString("create table import (importId varchar , Id varchar, name varchar,kind varchar, number int,unit varchar,importTime datetime primary key)"));

    query.exec(QString("create table export (exportId varchar , Id varchar, name varchar, kind varchar,number int,unit varchar,exportTime datetime primary key)"));

    query.exec(QString("create table stock (stockId varchar ,Id varchar, name varchar,kind varchar, number int,unit varchar,stockTime datetime primary key)"));

    query.exec(QString("create table number (id varchar primary key,minNumber int,maxNumber int)"));
    query.exec(QString("insert into number values(1,9,99)"));

    query.exec(QString("create table stockSheet (stockSheetId  varchar primary key)"));
    query.exec(QString("create table importSheet(importSheetId varchar primary key)"));
    query.exec(QString("create table exportSheet(exportSheetId varchar primary key)"));

    return true;
}

#endif // CONNECTION_H
