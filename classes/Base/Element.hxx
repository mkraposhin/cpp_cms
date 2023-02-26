#ifndef Element_H
#define Element_H

#include <iostream>
#include <memory>
//#include <map>
#include <list>

namespace krap
{

//- Forward declaration of Element
class Element;

using ElementPtr = std::shared_ptr<Element>;

class CSSClass;

using CSSClassPtr = std::shared_ptr<CSSClass>;
using CSSClassMapRec = std::pair<std::string,CSSClassPtr>;
//using CSSClassMap = std::map<std::string,CSSClassPtr>;
using CSSClassMap = std::list<CSSClassMapRec>;


class Element
{

private:

    //! Pointer to the child of this Element object
    ElementPtr child_;

    //! Pointer to the css class (if applicable)
    CSSClassPtr css_;

    //! The id attribute of an element
    std::string id_;

    //! Sets the pointer to new child
    void set_child(ElementPtr& new_child);

    //! Sets the CSS Class for this element
    void set_css_class(const CSSClass& css);

    //! this operator adds child element to the Element el
    friend Element& operator ^ (Element& el, const Element& child);

    //! this operator applies CSSClass stored in the reference css
    friend CSSClassPtr& operator % (Element& el, const CSSClass& css);

    //! this operator applies CSSClass stored in the pointer cssptr
    friend CSSClassPtr& operator % (Element& el, CSSClassPtr& cssptr);

public:

    //! Default constructor
    Element();

    //! Copy constructor
    Element(const Element&);

    //! Destructor
    ~Element();

    //!
    virtual std::ostream& print(std::ostream& ostr) const;

    //! creates clone of itself
    virtual ElementPtr clone() const;

    //! const-ref access to the child pointr
    const ElementPtr& child() const;

    //! gives const-ref access to the style class
    const CSSClassPtr& css() const;

    //! Sets the id attribute of an element
    void id (const std::string& id);

    //! Returs the id attribute of an element
    const std::string id() const;
};


//! ostream output operator
std::ostream& operator << (std::ostream& ostr, const Element& elem);

//- set nested element operator
Element& operator ^ (Element& el, const Element& child);

//- apply CSS Class to this element
CSSClassPtr& operator % (Element& el, const CSSClass& css);

//- apply CSS Class to this element
CSSClassPtr& operator % (Element& el, CSSClassPtr& cssptr);

}//namespace krap

#endif

//
//END-OF-FILE
//

