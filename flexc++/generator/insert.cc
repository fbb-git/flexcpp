#include "generator.ih"

void Generator::insert(ostream &out) const
{
    istringstream istr(d_line);
    size_t indent;

    istr >> d_key >> indent;

    if (istr)
        Indent::setWidth(indent);
    else
    {
        Indent::clear();
        istr.clear();
    }

    istr >> d_key;     // extract the insertion target

    size_t pos = d_key.find('.');   // find the field
    if (pos == string::npos)        // no field
        d_field.clear();
    else
    {
        d_field = d_key.substr(pos + 1);    // set the field
        d_key.resize(pos);                  // erase the field
    }

    getline(istr, d_line);      // and store the remainder of the line

    MapConstIter iter = s_insert.find(d_key);

    if (iter != s_insert.end())
        (this->*iter->second)(out);
    else
        wmsg << "Ignoring unsupported `$insert " << d_key << 
                " ...' in skeleton file" << endl;
}



