#ifndef FINLEXREADER_H
#define FINLEXREADER_H

#include <QString>

#include "finerrorcode.h"
#include "finlexnode.h"

class finLexReader
{
private:
    QString _inputStr;
    unsigned long _posIdx;
    unsigned int _curRow, _curCol;

    finLexNodeType _lastNodeType;

public:
    finLexReader();
    finLexReader(const QString &inputstr);

    QString getString() const;
    unsigned long getCurrentPosition() const;
    finErrorCode setString(const QString &instr);
    finErrorCode resetPosition();

    finErrorCode getNextLextNode(finLexNode *retnode);

private:

    finErrorCode moveReadPos();
    finErrorCode moveToNextNonblank();

    enum finLexReaderOrder {
        FIN_LR_ORD_NUMBER_FIRST,
        FIN_LR_ORD_OPERATOR_FIRST
    };

    finLexReaderOrder _nextReadOrder;

    finErrorCode getLexTypeOrder(const finLexNodeType **typeorder, int *typenum);
    finErrorCode getLexTypeOrder(finLexReader::finLexReaderOrder order,
                                 const finLexNodeType **typeorder, int *typenum);
    finErrorCode tryGetTypedNode(finLexNode *retnode, finLexNodeType lextype);
    finErrorCode tryGetNote(finLexNode *retnode);
    finErrorCode tryGetVariable(finLexNode *retnode);
    finErrorCode tryRecogKeyword(finLexNode *retnode);
    finErrorCode tryGetNumber(finLexNode *retnode);
    finErrorCode tryGetString(finLexNode *retnode);
    finErrorCode tryGetOperator(finLexNode *retnode);

};

#endif // FINLEXREADER_H
