#include <iostream>
#include "./magic.h"
#include "myfunction.h"

#ifndef NETLIST_PARSER_H
#define NETLIST_PARSER_H

class Parser
{
public:
	bool parse(std::istream& is, Magic& magic);

private:
	bool match_input(Magic& magic, const std::string& line);
	bool match_output(Magic& magic, const std::string& line);
	bool match_wire(Magic& magic, const std::string& line);
	bool match_node(Magic& magic, const std::string& line);
};


#endif