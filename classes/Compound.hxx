#ifndef Compound_H
#define Compound_H

#include "Element.hxx"
#include <vector>
#include <memory>

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Compound Declaration
\*---------------------------------------------------------------------------*/

class Compound
:
    public Element
{
private:


protected:

    //- Ordered list of elements in this compound
    std::vector<ElementPtr> elements_;


public:
     
    //- Default constructor (creates empty compound)
    Compound();

    //- Copy constructor for the Compound
    Compound(const Compound&);

    //- Destructor
    ~Compound();

    //- Add new element
    virtual ElementPtr& add (const Element&);

    //- Add element stored by ordinary pointer
    virtual ElementPtr& add (Element* ept);

    //- Add element stored by shared_ptr pointer
    virtual ElementPtr& add (ElementPtr& eptr);

    //- Print elements in compound
    virtual std::ostream& print(std::ostream& ostr) const override;

    //- Assign operator
    const Compound& operator = (const Compound& right);
};


//- addition of two Elements is the new Compound with two elements
std::shared_ptr<Compound> operator + 
(
    const Element& elem1, 
    const Element& elem2
);

//- addition of one Compound and one Element is equal to adding element
//  to this compound (const version)
std::shared_ptr<Compound> operator +
(
    const std::shared_ptr<Compound>& comp1,
    const Element& elem
);

//- addition of one Compound and one Element is equal to adding element
//  to this compound (const version)
std::shared_ptr<Compound> operator +
(
    const Element& elem,
    const std::shared_ptr<Compound>& comp1
);

}

#endif

//
//END-OF-FILE
//

