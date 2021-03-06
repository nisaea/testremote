#pragma once
/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2018. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <QtGui>
#include <QUuid>
#include <QtWidgets>

#include <medCoreLegacyExport.h>

class medAbstractData;
class medAbstractView;
class medDataIndex;
class medViewContainer;
class medViewContainerSplitter;
class medAbstractWorkspaceLegacy;
class medTabbedViewContainersPrivate;

/**
 * @brief A QTabWidget that contains medViewContainers.
 * There is one such stack per medViewWorkspace.
*/
class MEDCORELEGACY_EXPORT medTabbedViewContainers : public QTabWidget
{
    Q_OBJECT

public:
     medTabbedViewContainers(medAbstractWorkspaceLegacy* owningWorkspace, QWidget *parent = 0);
    ~medTabbedViewContainers();

    void lockTabs();
    void unlockTabs();
    void hideTabBar();
    void adjustContainersSize();
    QList<QUuid> containersSelected();
    QList<medAbstractView*> viewsInTab(int index = 0);
    QList<medViewContainer*> containersInTab(int index = 0);
    void setKeepLeastOne(bool pi_bVal);
    // TODO mutualize all of this
    void setSplitter(int index, medViewContainerSplitter* splitter);

public slots:
    medViewContainer* addContainerInTabUnNamed();
    medViewContainer* addContainerInTabNamed(const QString &name);
    medViewContainer* insertNewTab(int index, const QString &name);
    void closeCurrentTab();
    void closeTab(int index);

protected:

private slots :
    void tabBarDoubleClickedHandler(int  index);

    void addContainerToSelection(QUuid container);
    void removeContainerFromSelection(QUuid container);
    void buildTemporaryPool();

    void disconnectTabFromSplitter(int index);
    void connectContainer(QUuid container);
    void connectContainerSelectedForCurrentTab();
    void minimizeOtherContainers(QUuid containerMaximized, bool maximized);

private:
    void minimizeSplitterContainers(QUuid containerMaximized, bool maximized, medViewContainerSplitter *splitter);

signals:
    void containersSelectedChanged();

private:
    medTabbedViewContainersPrivate *d;
};
