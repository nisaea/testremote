/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2018. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractInvertFilterProcess.h>

#include <itkProcessObject.h>
#include <itkSmartPointer.h>

#include <medIntParameter.h>

#include <medItkSingleFilterOperationProcessPluginExport.h>

class MEDITKSINGLEFILTEROPERATIONPLUGIN_EXPORTS medItkInvertProcess: public medAbstractInvertFilterProcess
{
    Q_OBJECT
public:
    static void eventCallback(itk::Object *caller, const itk::EventObject& event, void *clientData)
    {
        medItkInvertProcess * source = reinterpret_cast<medItkInvertProcess *>(clientData);
        itk::ProcessObject * processObject = (itk::ProcessObject*) caller;
        source->progression()->setValue(processObject->GetProgress() * 100);
    }

    medItkInvertProcess(QObject* parent = NULL);
    ~medItkInvertProcess();

    virtual medAbstractJob::medJobExitStatus run();
    virtual void cancel();

    virtual QString caption() const;
    virtual QString description() const;

private:
    template<class inputType> medAbstractJob::medJobExitStatus _run();

private:
    itk::SmartPointer<itk::ProcessObject> m_filter;
};

inline medAbstractInvertFilterProcess* medItkInvertProcessCreator()
{
    return new medItkInvertProcess();
}
