// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#include "medProcessPaintSegm.h"

#include <medMetaDataKeys.h>

#include <dtkCore/dtkAbstractProcessFactory.h>

#include <dtkCore/dtkAbstractData.h>
#include <dtkCore/dtkAbstractDataFactory.h>
#include <dtkLog/dtkLog.h>
#include <dtkCore/dtkSmartPointer.h>

// /////////////////////////////////////////////////////////////////
// medProcessPaintSegmPrivate
// /////////////////////////////////////////////////////////////////

class medProcessPaintSegmPrivate
{
public:
    dtkSmartPointer<dtkAbstractData> imageInput;
    dtkSmartPointer<dtkAbstractData> maskInput;
    dtkSmartPointer<dtkAbstractData> segmentationOutput;
};


// /////////////////////////////////////////////////////////////////
// medProcessPaintSegm
// /////////////////////////////////////////////////////////////////

medProcessPaintSegm::medProcessPaintSegm(void) : dtkAbstractProcess(), d(new medProcessPaintSegmPrivate)
{

}

medProcessPaintSegm::~medProcessPaintSegm(void)
{
    delete d;
    d = NULL;
}

bool medProcessPaintSegm::registered(void)
{
    return dtkAbstractProcessFactory::instance()->registerProcessType(
        medProcessPaintSegm::s_identifier(),
        medProcessPaintSegm::create);
}

QString medProcessPaintSegm::description(void) const
{
    return tr("Paint");
}

QString medProcessPaintSegm::identifier(void) const
{
    return medProcessPaintSegm::s_identifier();
}

QString medProcessPaintSegm::s_identifier( void )
{
     return "medProcessPaintSegm";
}

void medProcessPaintSegm::setInput( dtkAbstractData *data, int channel )
{
    switch( channel ) {
    case ImageChannel : 
        d->imageInput = data;
        break;
    case MaskChannel : 
        d->maskInput = data;
        break;
    default :
        dtkWarn() << "Attempt to set channel out of range";
        break;
    }
}

void * medProcessPaintSegm::data( void )
{

    return NULL;
}

int medProcessPaintSegm::update( void )
{
    if (!d->imageInput || !d->maskInput) {
        return DTK_FAILURE;
    }

    this->setOutputMetadata(d->imageInput, d->maskInput);

    d->segmentationOutput = d->maskInput;

    return DTK_SUCCEED;
}

QString medProcessPaintSegm::MaskImageTypeIdentifier()
{
    return "itkDataImageUChar3";
}

dtkAbstractData * medProcessPaintSegm::output()
{
    return d->segmentationOutput;
}

void medProcessPaintSegm::setOutputMetadata(const dtkAbstractData * inputData, dtkAbstractData * outputData)
{
    Q_ASSERT(outputData && inputData);

    QStringList metaDataToCopy;
    metaDataToCopy 
        << medMetaDataKeys::PatientName.key()
        << medMetaDataKeys::StudyDescription.key();

    foreach( const QString & key, metaDataToCopy ) {
        outputData->setMetaData(key, inputData->metadatas(key));
    }

    QString seriesDesc;
    seriesDesc = tr("Segmented from ") + medMetaDataKeys::SeriesDescription.getFirstValue( inputData );

    medMetaDataKeys::SeriesDescription.set(outputData,seriesDesc);
}

// /////////////////////////////////////////////////////////////////
// Type instantiation
// /////////////////////////////////////////////////////////////////
dtkAbstractProcess * medProcessPaintSegm::create( void )
{
    return new medProcessPaintSegm;
}
