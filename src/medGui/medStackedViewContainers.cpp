/* medStackedViewContainers.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Thu May 13 12:39:09 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Jun 15 22:12:57 2010 (+0200)
 *           By: Julien Wintz
 *     Update #: 8
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include <QtCore>

#include "medStackedViewContainers.h"

#include "medViewContainer.h"
#include "medViewContainerCustom.h"
#include "medViewContainerMulti.h"
#include "medViewContainerSingle.h"

class medStackedViewContainersPrivate
{
public:
   QHash<QString, medViewContainer*> containers;
   QString currentName;
};

medStackedViewContainers::medStackedViewContainers(QWidget *parent) : QStackedWidget(parent), d(new medStackedViewContainersPrivate)
{
    
}

medStackedViewContainers::~medStackedViewContainers(void)
{
    delete d;

    d = NULL;
}

void medStackedViewContainers::addContainer(const QString &name, medViewContainer *container)
{
    if (!container)
        return;
    
    d->containers[name] = container;
    
    connect( container, SIGNAL( focused( dtkAbstractView * ) ),
             this,      SIGNAL( focused( dtkAbstractView * ) ) );
    connect( container, SIGNAL( dropped( const medDataIndex & ) ),
             this,      SIGNAL( dropped( const medDataIndex & ) ) );
    connect( container, SIGNAL( viewAdded( dtkAbstractView * ) ),
             this,      SIGNAL( viewAdded( dtkAbstractView * ) ) );
    connect( container, SIGNAL( viewRemoved( dtkAbstractView * ) ),
             this,      SIGNAL( viewRemoved( dtkAbstractView * ) ) );
    
    if (!this->count()) 
        d->currentName = name;
    this->addWidget( container );
}

medViewContainer* medStackedViewContainers::container(const QString &name) const
{
    if (!d->containers.contains(name))
        return NULL;
    
    return d->containers[name];
}

void medStackedViewContainers::setContainer(const QString &name)
{
    if (!d->containers.contains(name))
    {
        qWarning()<<"container does not contain any container of name:" << name;
        return;
    }
    
    d->currentName = name;
    this->setCurrentWidget(d->containers[name]);
}

medViewContainer *medStackedViewContainers::current(void) const
{
    return dynamic_cast<medViewContainer*> (currentWidget());
}

QString medStackedViewContainers::currentName(void) const
{
    return d->currentName;
}

QList<QString> medStackedViewContainers::keys()
{
    return d->containers.keys();
}

void medStackedViewContainers::removeContainer(const QString& name)
{
    if (d->containers.contains(name))
    {
        medViewContainer* container = d->containers[name];
        removeWidget(container);
        delete container;
        d->containers.remove(name);
    }
}
