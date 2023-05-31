#include "CF_grammar.h"
#include <string>

std::set<std::shared_ptr<Symbol>> CF_grammar::START1(const std::shared_ptr<Symbol>& S)
{
    if (dynamic_cast<Terminal*>(S.get()))
    {
       return std::set<std::shared_ptr<Symbol>>();

    std::set<Symbol> seen;

    return START1_REC(S, seen);
}

std::set<std::shared_ptr<Symbol>> CF_grammar::START1_REC(const std::shared_ptr<Symbol>& S, std::set<Symbol>& seen)
{
    std::set<std::shared_ptr<Symbol>> first_syms;

    size_t rules_amount = m_rules.count(*S);
    auto it = m_rules.find(*S);

    for (size_t i = 0; it != m_rules.end() && i < rules_amount; ++i, ++it)
    {
        
        first_syms.insert(it->second.m_right_part[0]);

        if(dynamic_cast<Non_terminal*>(it->second.m_right_part[0].get()))
            if (seen.find(*it->second.m_right_part[0]) == seen.end())
            {
                seen.insert(*it->second.m_right_part[0]);
                first_syms.merge(START1_REC((*it).second.m_right_part[0], seen));
            }
    }

    return first_syms;
}