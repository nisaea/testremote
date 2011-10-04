/* medAbstractDataTypedImage4D.h --- 
 * 
 * Author: Theo Papadopoulo
 * Copyright (C) 2008 - Theo Papadopoulo, Inria.
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifndef MEDABSTRACTDATATYPEDIMAGE4D_H
#define MEDABSTRACTDATATYPEDIMAGE4D_H

#include "medCoreExport.h"
#include <medAbstractDataImage4D.h>

template <typename T>
class MEDCORE_EXPORT medAbstractDataTypedImage4D : public medAbstractDataImage4D {
public:

    medAbstractDataTypedImage4D(void);
   ~medAbstractDataTypedImage4D(void);

    const medAbstractDataImage::PixId& PixelType() const { return typeid(T); }
};

#endif
