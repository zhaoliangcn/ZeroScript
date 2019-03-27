#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "zstring.h"

class ObjectBase
{
    public:
        /** Default constructor */
        ObjectBase();
        /** Default destructor */
        virtual ~ObjectBase();
        virtual unsigned int GetType()=0;
        virtual ZString ToString()=0;


    protected:

    private:
};

#endif // OBJECTBASE_H
