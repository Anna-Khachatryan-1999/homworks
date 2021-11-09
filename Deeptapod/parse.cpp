#include <iostream>
#include "parse.h"

//recurring cod. change

Parse::Parse(std::string& searchingWord, std::string& text, std::string& sentence) : m_word{searchingWord}, m_text{text}, m_sentence{sentence}
{
    fillTheMap();
    fillTheEntity();
    if (m_nameEntities.size() == 1) {
        m_entity = m_nameEntities[0];
    } else if (m_nameEntities.size() > 1) {
        //call func analize_text
        textAnalysis();
    } else {
        std::cout << "unknown word" << std::endl;
    }
}

std::string Parse::getEntity() const
{
    return m_entity;
}

std::unordered_map<bool(*)(std::string&), std::string> Parse::m_fullFunc;

void Parse::fillTheMap()
{
    m_fullFunc[isCity] = "city";
    m_fullFunc[isCountry] = "country";
    m_fullFunc[isVillage] = "village";
    m_fullFunc[isStreet] = "street";
    m_fullFunc[isOcean] = "ocean";
    m_fullFunc[isSea] = "sea";
    m_fullFunc[isLake] = "lake";
    m_fullFunc[isWaterfall] = "waterfall";
    m_fullFunc[isRiver] = "river";
    m_fullFunc[isPeninsula] = "peninsula";
    m_fullFunc[isPerson] = "person";
    m_fullFunc[isAnimal] = "animal";
    m_fullFunc[isBrid] = "bird";
    m_fullFunc[isCur] = "cur";
    m_fullFunc[isSubject] = "subject";

}

void Parse::fillTheEntity()
{
    for (const auto& elem : m_fullFunc) {
        if (elem.first(m_word)) {
            m_nameEntities.push_back(elem.second);
        }
    }
}
//es karcum em anpitana u kara aveli shat xangari qan te ogni
void Parse::textAnalysis()
{
    std::size_t firstEntity;
    std::size_t size = 0;
    for (int i = 0; i < m_nameEntities.size();) {
        firstEntity = m_text.find(m_nameEntities[i]);
        if (firstEntity == std::string::npos) {
            m_nameEntities.erase(m_nameEntities.begin() + i);
        } else {
            ++i;
        }
    }
    if (m_nameEntities.size() == 1) {
        m_entity = m_nameEntities[0];
    } else if (m_nameEntities.size() > 1){
        std::cout << "There are many entities" << std::endl;
        m_entity = m_nameEntities[0];
    } else {
        std::cout << "unknown word" << std::endl;
    }
}

// bareri bajanum ankap, parzapes prabelnerov
void Parse::devideSenetenceWord()
{
    std::string tmp;
    for (int i = 0; i < m_sentence.size(); ++i) {
        if (m_sentence[i] = ' ' && tmp.size() > 0) {
            m_words.push_back(tmp);
            tmp.clear();
        } else {
            tmp += m_sentence[i];
        }
    }
    if (tmp.size() > 1) {
        m_words.push_back(tmp);
    }
}

std::string whatThisNumberType()
{
    int indexMyWords = 0;
    for (int i = 0; i < m_sentence.size(); ++i) {
        if (m_sentence[i] == m_word) {
            index  = i;
        }
    }
    if (index == 0) {

    } else if (index == m_sentence.size() - 1) {

    } else {
        
    }
};

void Parse::esim()
{
    if (isTheNumber())
}


bool Parse::isCity(std::string& name)
{
    return false;
}

bool Parse::isCountry(std::string& name)
{
    return false;
}

bool Parse::isVillage(std::string& name)
{
    return false;
}

bool Parse::isStreet(std::string& name)
{
    return false;
}

bool Parse::isOcean(std::string& name)
{
    return false;
}

bool Parse::isSea(std::string& name)
{
    return false;
}

bool Parse::isLake(std::string& name)
{
    return false;
}

bool Parse::isWaterfall(std::string& name)
{
    return true;
}

bool Parse::isRiver(std::string& name)
{
    return false;
}

bool Parse::isPeninsula(std::string& name)
{
    return false;
}

bool Parse::isPerson(std::string& name)
{
    return true;
}

bool Parse::isAnimal(std::string& name)
{
    return false;
}

bool Parse::isBrid(std::string& name)
{
    return false;
}

bool Parse::isCur(std::string& name)
{
    return false;
}

bool Parse::isSubject(std::string& name)
{
    return false;
}

// helper
/*int Parse::helpIsEqualString(std::string& s1, std::string& s2)
{
    int countMatchingCharacters = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            countMatchingCharacters++;
        } else if (s1[i] >= 'A' && s1[i] != 'Z') {
            if ((s1[i] + 32) == s2[i]) {
                countMatchingCharacters++;
            }
        } else if (s1[i] >= 'a' && s1[i] != 'z') {
            if ((s1[i] - 32) == s2[i]) {
                countMatchingCharacters++;
            }
        }
    }
    return countMatchingCharacters;
}*/
