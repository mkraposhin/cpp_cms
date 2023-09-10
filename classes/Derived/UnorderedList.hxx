#ifndef UnorderedList_H
#define UnorderedList_H

#include "Compound.hxx"
#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

//!
struct UnorderedListValue : public ValueBase<krap::TagId::UNORDERED_LIST,true,void*>, public Compound
{
    //!
    UnorderedListValue() = default;
    
    //!
    UnorderedListValue(const UnorderedListValue& divval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        Compound::print(ostr);
    }
};

using UnorderedListBase = HtmlTagBase<UnorderedListValue,IdAttribute>;
using UnorderedList = HtmlTagImpl<UnorderedListBase>;

}

#endif

//
//END-OF-FILE
//
