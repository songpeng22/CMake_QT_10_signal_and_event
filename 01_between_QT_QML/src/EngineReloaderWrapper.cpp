#include "EngineReloaderWrapper.h"
//API
#include <QQmlContext>
#include <QGuiApplication>
#include "cdata.h"
#include "qqmldock.h"
#include <QQuickWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QQmlProperty>
EngineReloaderWrapper::EngineReloaderWrapper()
{

}

EngineReloaderWrapper::~EngineReloaderWrapper()
{

}

void EngineReloaderWrapper::setContextProperies(QQmlContext * pQmlContext)
{
    qDebug() << "EngineReloaderWrapper::setContextProperies()";

    //Engine
    pQmlContext->setContextProperty("engine", this);
    //
    pQmlContext->setContextProperty("data1",CData::Instance());
}

void EngineReloaderWrapper::registerToQml()
{
    qDebug() << "EngineReloaderWrapper::registerToQml()";

}

void EngineReloaderWrapper::beforeLoad()
{
    qDebug() << "EngineReloaderWrapper::beforeLoad()";

    setContextProperies(m_qmlContext);
    registerToQml();
}

//Find Child
QObject * FindChild(QObject * objParent,QString qstr){
    QObject * objSub = objParent->findChild<QObject*>(qstr,Qt::FindChildrenRecursively);
    if(objSub)
        qDebug() << "PName:" << objParent->objectName() << "SName:" << objSub->objectName();
    return objSub;
}

//Find all Children
QList<QObject *> FindChildren(QObject * objParent,QString qstr){
    QList<QObject *> objSub = objParent->findChildren<QObject*>(qstr,Qt::FindChildrenRecursively);

    return objSub;
}


void EngineReloaderWrapper::afterLoad()
{
    qDebug() << "EngineReloaderWrapper::afterLoad()";
    if( m_instance->rootObjects().isEmpty() ) return;
    //get requried control into control list , and make it easy for next search
    QObject * qmlObjectParent = Q_NULLPTR;
    QObject * qmlObjectSub = Q_NULLPTR;
#if 1
    QQmlDock::Instance()->setRootObject(m_instance->rootObjects().first());
    qmlObjectSub = QQmlDock::Instance()->findChild( "objRect1" );
    qDebug() << "qmlObjectSub" << qmlObjectSub;
    //
    qmlObjectSub = QQmlDock::Instance()->findChild( "objButton1" );
    QPushButton * pButton = (QPushButton*) qmlObjectSub;
    qDebug() << "pButton" << pButton;
    qDebug() << qmlObjectSub->setProperty( "text","btn" );
	//
    QQmlDock::Instance()->setProperty( "objButton1","text","btn2" );

    qmlObjectSub = QQmlDock::Instance()->findChild( "objTextEdit1" );
    QTextEdit * pTextEdit = ( QTextEdit * ) qmlObjectSub;
    qDebug() << "pTextEdit" << pTextEdit;
    qDebug() << QQmlProperty::read(qmlObjectSub, "text").toString() ;
	//
    qDebug() << QQmlDock::Instance()->property("objTextEdit1","text").toString();¡¢
	//
    qmlObjectSub->setProperty( "text","EditText" );

#else
    //get root obj
    QQuickWindow * rootObject = (QQuickWindow *)m_instance->rootObjects().first();


/*
    if (rootObject) {
        rootObject->setProperty("width", 600);
        rootObject->setProperty("height", 400);
    }
*/
    //Find Sub1
    qmlObjectSub = FindChild(rootObject, "objRect1");
    qDebug() << "qmlObjectSub" << qmlObjectSub;
    //
    qmlObjectSub = FindChild(rootObject, "objButton1");
    QPushButton * pButton = (QPushButton*) qmlObjectSub;
    qDebug() << "pButton" << pButton;
    //
#endif
}
