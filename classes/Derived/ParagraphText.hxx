#ifndef ParagraphText_H
#define ParagraphText_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{
/*---------------------------------------------------------------------------*\
                            Class ParagraphText Declaration
\*---------------------------------------------------------------------------*/

struct ParagraphTextValue : public ValueBase<krap::TagId::P,true,std::string>
{
    //!
    ParagraphTextValue() = default;

    //!
    ParagraphTextValue(const ParagraphTextValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        ostr << value_;
    }
};

using ParagrahTextBase = HtmlTagBase<ParagraphTextValue>;
using ParagraphText = HtmlTagImpl<ParagrahTextBase>;

using ParagraphPtr = std::shared_ptr<ParagraphText>;

}

#endif

//
//END-OF-FILE
//
