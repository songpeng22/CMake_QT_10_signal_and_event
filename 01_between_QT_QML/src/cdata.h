#ifndef CDATA_H
#define CDATA_H

#include <QObject>
#include <QDebug>

class CData : public QObject
{
    Q_OBJECT
public:
    explicit CData(QObject *parent = nullptr);
    ~CData(){ qDebug() << "~CData"; }

    Q_INVOKABLE void setData( int data ){ m_data = data; emit dataChanged(); }
signals:
    void dataChanged();
public slots:
    int data(){
        qDebug() << "data:" << m_data;
        return m_data;
    }
protected:
    int m_data;
public:
    static CData * Instance(){
        static CData _instance;
        return &_instance;
    }
};

#endif // CDATA_H
