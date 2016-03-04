#include "optionsManager.h"
#include "src/types.h"

#include <iostream>

OptionsManager::OptionsManager(DataMap &dataMap, InstructionList &instructionList) :
    _dataMap(dataMap),
    _instructionList(instructionList),
    _display(false),
    _transform(false),
    _execute(false),
    _analysis(false)
{
}

bool OptionsManager::CheckOption(int argc, char *argv[])
{
    for (int i = 2 ; i < argc; ++i)
    {
        if (string(argv[i]) == "-o")
            _transform = true;
        else if (string(argv[i]) == "-p")
            _display = true;
        else if (string(argv[i]) == "-a")
            _analysis = true;
        else if (string(argv[i]) == "-e")
            _execute = true;
        else
            return false;
    }
    return true;
}

void OptionsManager::Execute()
{
    if (_display)
        print();
    else if (_transform)
        transform();
    else if (_analysis)
        analysis();
    else if (_execute)
        execute();
}

void OptionsManager::analysis()
{

}

void OptionsManager::execute()
{
    list<Instruction>::iterator itIns;
    bool ok;
    double value;
    int i = 0;
    for (itIns = _instructionList.begin() ; itIns != _instructionList.end() ; ++itIns, ++i)
    {
        //Vérification et calcul de l'expression pour SET et PRINT
        if ((*itIns).expr != NULL)
        {
            ok = false;
            value = (*itIns).expr->Eval(_dataMap, ok);
            if (!ok)
            {
                cout << "Erreur d'execution à la ligne " << i << endl;
                return;
            }
        }
        //Vérification de la présence de la variable à modifier pour READ et SET
        if ((*itIns).identifier != "" && !_dataMap.count((*itIns).identifier))
        {
            cout << "Variable inconnu à la ligne " << i << endl;
            return;
        }

        //Execution de la ligne
        if ((*itIns).code == ICODE_PRINT)
            cout << value << endl;
        else if ((*itIns).code == ICODE_READ)
        {
            cin >> _dataMap[(*itIns).identifier].value;
        }
        else
            _dataMap[(*itIns).identifier].value = value;
    }
}

void OptionsManager::print() const
{
    /*_dataMap.stringify();
     * _instructionList.stringify();
     *
    map<string, Data>::iterator itData;
    for (itData = _dataMap.begin() ; itData != _dataMap.end() ; ++itData)
    {
        if ((*itData).second.cst)
            cout << "const " << (*itData).first << "=" << (*itData).second.value;
        else
            cout << "var "<< (*itData).first;
        cout << ";" << endl;
    }
    list<Instruction>::iterator itIns;
    for (itIns = _instructionList.begin() ; itIns != _instructionList.end() ; ++itIns)
    {
        if ((*itIns).code == ICODE_PRINT)
            cout << ;
        else if ((*itIns).code == ICODE_PRINT)
            cout << ;
        else
            cout <<;

        cout << ";" << endl;
    }*/
}

void OptionsManager::transform()
{

}