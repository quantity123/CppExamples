#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H
#include <sstream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using ptree = boost::property_tree::ptree;

inline std::string ptreeToJsonString(const ptree& tree)
{
    std::stringstream ss;
    boost::property_tree::write_json(ss, tree, false);
    return ss.str();
}

#endif // JSON_OBJECT_H
