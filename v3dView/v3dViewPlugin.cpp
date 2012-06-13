// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#include "v3dView.h"
#include "v3dViewFuseInteractor.h"
#include "v3dViewMeshInteractor.h"
#include "v3dView4DInteractor.h"
#include "v3dViewAnnotationInteractor.h"
#include "v3dViewPlugin.h"
#ifndef DISABLE_TTK_DEPENDENT_CODE
  #include "v3dViewFiberInteractor.h"
  #include "v3dViewTensorInteractor.h"
#endif

#include <dtkLog/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// v3dViewPluginPrivate
// /////////////////////////////////////////////////////////////////

class v3dViewPluginPrivate
{
public:
    // Class variables go here.
};

// /////////////////////////////////////////////////////////////////
// v3dViewPlugin
// /////////////////////////////////////////////////////////////////

v3dViewPlugin::v3dViewPlugin(QObject *parent) : dtkPlugin(parent), d(new v3dViewPluginPrivate)
{

}

v3dViewPlugin::~v3dViewPlugin(void)
{
    delete d;

    d = NULL;
}

bool v3dViewPlugin::initialize(void)
{
    if (!v3dView::registered()) dtkWarn() << "Unable to register v3dView type";

#ifndef DISABLE_TTK_DEPENDENT_CODE
    if (!v3dViewFiberInteractor::registered()) dtkWarn() << "Unable to register v3dViewFiberInteractor type";
#endif

    if (!v3dViewFuseInteractor::registered()) dtkWarn() << "Unable to register v3dViewFuseInteractor type";
    if (!v3dViewMeshInteractor::registered()) dtkWarn() << "Unable to register v3dViewMeshInteractor type";
    if (!v3dView4DInteractor::registered()) dtkWarn() << "Unable to register v3dView4DInteractor type";
    if (!v3dViewAnnotationInteractor::registered()) dtkWarn() << "Unable to register v3dViewAnnotationInteractor type";

#ifndef DISABLE_TTK_DEPENDENT_CODE
    if (!v3dViewTensorInteractor::registered()) dtkWarn() << "Unable to register v3dViewTensorInteractor type";
#endif

    return true;
}

bool v3dViewPlugin::uninitialize(void)
{
    return true;
}

QString v3dViewPlugin::name(void) const
{
    return "v3dViewPlugin";
}

QString v3dViewPlugin::contact(void) const
{
    return "";
}

QStringList v3dViewPlugin::authors(void) const
{
    QStringList list;
    list << QString::fromUtf8("Pierre Fillard");
    return list;
}

QStringList v3dViewPlugin::contributors(void) const
{
    QStringList list;
    list <<  "Nicolas Toussaint"
          << "Stephan Schmitt"
          << "John Stark"
          << QString::fromUtf8("Benoît Bleuzé")
          << "Jaime Garcia"
          << "Fatih Arslan"
          << "Sergio Medina";
    return list;
}

QString v3dViewPlugin::version(void) const
{
    return V3DVIEWPLUGIN_VERSION;
}

QString v3dViewPlugin::description(void) const
{
    return tr("View Plugin\n<br/>"
              "Contains view and interactors based on vtkinria3d");
}

QStringList v3dViewPlugin::tags(void) const
{
    return QStringList() << "v3d" << "view";
}

QStringList v3dViewPlugin::types(void) const
{
    return QStringList() << v3dView::s_identifier() << "v3dViewFiberInteractor"
        << "v3dViewFuseInteractor" << "v3dViewMeshInteractor"
        << "v3dViewTensorInteractor" << "v3dView4DInteractor"
        << v3dViewAnnotationInteractor::s_identifier();
}

Q_EXPORT_PLUGIN2(v3dViewPlugin, v3dViewPlugin)
