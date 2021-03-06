#include "finlexnode.h"

#include <stdlib.h>

finLexNode::finLexNode() :
    _string(), _stringValue()
{
    this->_type = FIN_LN_TYPE_DUMMY;
    memset(this->_u._rawData, 0, sizeof (this->_u));
    this->_row = 0;
    this->_column = 0;
}

finLexNodeType finLexNode::getType() const
{
    return this->_type;
}

QString finLexNode::getString() const
{
    return this->_string;
}

double finLexNode::getFloatValue() const
{
    if ( this->_type != FIN_LN_TYPE_DECIMAL )
        return 0.0f;

    return this->_u._floatValue;
}

finLexOperatorType finLexNode::getOperator() const
{
    if ( this->_type != FIN_LN_TYPE_OPERATOR )
        return finLexNode::FIN_LN_OPTYPE_DUMMY;

    return this->_u._operator;
}

QString finLexNode::getStringValue() const
{
    if ( this->_type != FIN_LN_TYPE_STRING )
        return QString();

    return this->_stringValue;
}

unsigned int finLexNode::getRow() const
{
    return this->_row;
}

unsigned int finLexNode::getColumn() const
{
    return this->_column;
}

finErrorCode finLexNode::setType(finLexNodeType type)
{
    this->_type = type;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}

finErrorCode finLexNode::setString(const QString &str)
{
    this->_string = str;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}

finErrorCode finLexNode::setFloatValue(double val)
{
    if ( this->_type != FIN_LN_TYPE_DECIMAL )
        return finErrorCodeKits::FIN_EC_STATE_ERROR;

    this->_u._floatValue = val;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}

finErrorCode finLexNode::setOperator(finLexNodeOperatorType optype)
{
    if ( this->_type != FIN_LN_TYPE_OPERATOR )
        return finErrorCodeKits::FIN_EC_STATE_ERROR;

    this->_u._operator = optype;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}

finErrorCode finLexNode::setStringValue(const QString &strval)
{
    if ( this->_type != FIN_LN_TYPE_STRING )
        return finErrorCodeKits::FIN_EC_STATE_ERROR;

    this->_stringValue = strval;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}

finErrorCode finLexNode::setRow(unsigned int row)
{
    this->_row = row;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}

finErrorCode finLexNode::setColumn(unsigned int column)
{
    this->_column = column;
    return finErrorCodeKits::FIN_EC_SUCCESS;
}
