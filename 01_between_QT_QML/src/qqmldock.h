#ifndef QQMLDOCK_H
#define QQMLDOCK_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QQmlProperty>
#include <QVariant>

class QQmlDock : public QObject
{
    Q_OBJECT
public:
    explicit QQmlDock(QObject *parent = nullptr);
    void setRootObject( QObject * pRootObject )
    {
        m_rootObj = pRootObject;
    }
    QObject * findChild(QString qstr){
        if(!m_rootObj) return nullptr;

        QObject * objSub = m_rootObj->findChild<QObject*>(qstr,Qt::FindChildrenRecursively);
        if(objSub)
            qDebug() << "QQmlDock::PName:" << m_rootObj->objectName() << "SName:" << objSub->objectName();
        return objSub;
    }
    bool setProperty(QString objName,const char *name, const QVariant &value)
    {
        if(!m_rootObj) return false;

        QObject * objSub = m_rootObj->findChild<QObject*>(objName,Qt::FindChildrenRecursively);
        if(objSub)
            objSub->setProperty(name,value);
        else
            return false;

        return true;
    }
    QVariant property(QString objName,const char *name)
    {
        if(!m_rootObj) return QVariant("");

        QObject * objSub = m_rootObj->findChild<QObject*>(objName,Qt::FindChildrenRecursively);
        if(objSub)
            return QQmlProperty::read(objSub, name);
        else
            return QVariant("");
    }

signals:

public slots:

protected:
    QObject * m_rootObj;
public:
    static QQmlDock * Instance(){
        static QQmlDock _instance;
        return &_instance;
    }
};

#endif // QQMLDOCK_H
