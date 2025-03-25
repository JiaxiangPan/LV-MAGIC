#include "../include/netlist_parser.h"

bool Parser::parse(std::istream &is, Magic &magic)
{
  const std::string flag_input = "input";
  const std::string flag_output = "output";
  const std::string flag_wire = "wire";
  const std::string flag_node1 = "inv1";
  const std::string flag_node2 = "nor2";
  const std::string flag_node3 = "zero";
  const std::string flag_node4 = "buf";
  const std::string flag_node5 = "one";
  const std::string flag_node6 = "nor3";
  const std::string flag_node7 = "nor4";
  const std::string flag_node8 = "nor5";
  const std::string flag_end = ";";

  std::string input_statement;
  std::string output_statement;
  std::string wire_statement;

  for (std::string line; std::getline(is, line, '\n');)
  {
    if (line.find(flag_input) != std::string::npos)
    {
      if(line.find(flag_end) != std::string::npos)
      {
        match_input(magic, line);
      }
      else
      {
        input_statement = line;
        while(getline(is, line, '\n'))
        { 
          input_statement += line;
          if(line.find(flag_end) != std::string::npos)
          {
            match_input(magic, input_statement);
            break;
          }
        }
      }
      continue;
    }

    if (line.find(flag_output) != std::string::npos)
    {
      if(line.find(flag_end) != std::string::npos)
      {
        match_output(magic, line);
      }
      else
      {
        output_statement = line;
        while(getline(is, line, '\n'))
        {
          output_statement += line;
          if(line.find(flag_end) != std::string::npos)
          {
            match_output(magic, output_statement);
            break;
          }
        }
      }
      continue;
    }

    if (line.find(flag_wire) != std::string::npos)
    {
      if(line.find(flag_end) != std::string::npos)
      {
        match_wire(magic, line);
      }
      else
      {
        wire_statement = line;
        while (getline(is, line, '\n'))
        {
          wire_statement += line;
          if (line.find(flag_end) != std::string::npos)
          {
            match_wire(magic, wire_statement);
            break;
          }
        }
      }
      continue;
    }

    if (line.find(flag_node1) != std::string::npos 
        || line.find(flag_node2) != std::string::npos 
        || line.find(flag_node3) != std::string::npos 
        || line.find(flag_node4) != std::string::npos
        || line.find(flag_node5) != std::string::npos
        || line.find(flag_node6) != std::string::npos
        || line.find(flag_node7) != std::string::npos
        || line.find(flag_node8) != std::string::npos)
    {
      match_node(magic, line);
      continue;
    }
  }
  return true;
}

bool Parser::match_input(Magic &magic, const std::string &line)
{
  if (line.find("input") == std::string::npos || line.find(";") == std::string::npos)
  {
    std::cout << "the input statement format is wrong!" << std::endl;
    return false;
  }
  // input a, b;
  std::vector<std::string> inputs_info = m_split(line, " ,;");
  for (int i = 1; i < inputs_info.size(); i++)
  {
    // std::cout << inputs_info[i] <<std::endl;
    magic.add_input(inputs_info[i]);
  }
  return true;
}

bool Parser::match_output(Magic &magic, const std::string &line)
{
  if (line.find("output") == std::string::npos || line.find(";") == std::string::npos)
  {
    std::cout << "the output statement format is wrong!" << std::endl;
    return false;
  }
  // output cout, sum;
  std::vector<std::string> outputs_info = m_split(line, " ,;");

  for (int i = 1; i < outputs_info.size(); i++)
  {
    magic.add_output(outputs_info[i]);
  }
  return true;
}

bool Parser::match_wire(Magic &magic, const std::string &line)
{
  if (line.find("wire") == std::string::npos || line.find(";") == std::string::npos)
  {
    std::cout << "the wire statement format is wrong!" << std::endl;
    return false;
  }
  // wire new_n5_, new_n6_, new_n8_;
  std::vector<std::string> wires_info = m_split(line, " ,;");
  // std::cout << wires_info.size() << std::endl;
  for (int i = 1; i < wires_info.size(); i++)
  { 
    magic.add_wire(wires_info[i]);
  }
  return true;
}

bool Parser::match_node(Magic &magic, const std::string &line)
{
  if ((line.find("inv1") == std::string::npos 
       && line.find("nor2") == std::string::npos
       && line.find("nor3") == std::string::npos
       && line.find("nor4") == std::string::npos
       && line.find("nor5") == std::string::npos 
       && line.find("buf") == std::string::npos 
       && line.find("zero") == std::string::npos
       && line.find("one") == std::string::npos) 
       || line.find(";") == std::string::npos)
  {
    std::cout << "the assign statement format is wrong!" << std::endl;
    // std::cout << line << std::endl;
    return false;
  }

  //   buf  g24606(.a(\a[0] ), .O(\asquared[0] ));
  //"  inv1 g0(.a(a), .O(new_n5_));"
  //"  nor2 g3(.a(b), .b(a), .O(new_n8_));"
  //   zero g24605(.O(\asquared[1] ));
  //   one  g134(.O(sign));
  // nor3 g2322(.a(new_n4072_), .b(new_n4071_), .c(new_n2351_), .O(new_n4073_));
  // nor4 g3142(.a(new_n4892_), .b(new_n4862_), .c(new_n4859_), .d(pi559), .O(new_n4893_));
  // nor5 g6005(.a(new_n7755_), .b(new_n7752_), .c(new_n7748_), .d(new_n7744_), .e(new_n2419_), .O(new_n7756_));

  std::vector<std::string> gates_info = m_split(line, " (),;");
  std::string name;
  std::string gate_type = gates_info[0];
  std::vector<std::string> inputs;
  std::string outputs;
  bool is_inv1 = false;
  bool is_nor2 = false;
  bool is_buf = false;
  bool is_zero = false;
  bool is_one = false;
  int is_multi_nor = -1;//3 4 5 means inputs_num of NOR  
  if (gates_info.size() == 6)
  {
    name = gates_info[1];
    if(gate_type == "inv1")
    {
      inputs.push_back(gates_info[3]);
      outputs = (gates_info[5]);
      is_inv1 = true;
      is_nor2 = false;
      is_buf = false;
      is_zero = false;
      is_one = false;
      magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
      return true;
    }
    if(gate_type == "buf")
    {
      inputs.push_back(gates_info[3]);
      outputs = (gates_info[5]);
      is_inv1 = false;
      is_nor2 = false;
      is_buf = true;
      is_zero = false;
      is_one = false;
      magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
      return true;
    }
    return false;
  }
  else if (gates_info.size() == 8)
  {
    name = gates_info[1];
    inputs.push_back(gates_info[3]);
    inputs.push_back(gates_info[5]);
    outputs = (gates_info[7]);
    is_inv1 = false;
    is_nor2 = true;
    is_buf = false;
    is_zero = false;
    is_one = false;
    magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
    return true;
  }
  else if(gates_info.size() == 4)
  {
    name = gates_info[1];
    if(gate_type == "zero")
    {
      inputs.push_back(gates_info[0]);
      outputs = gates_info[3];
      is_inv1 = false;
      is_nor2 = false;
      is_buf = false;
      is_zero = true;
      is_one = false;
      magic.add_input(gates_info[0]);//bug fixed here (create input line "zero")
      magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);//
      return true;
    }
    if(gate_type == "one")//
    {
      inputs.push_back(gates_info[0]);
      outputs = gates_info[3];
      is_inv1 = false;
      is_nor2 = false;
      is_buf = false;
      is_zero = false;
      is_one = true;
      magic.add_input(gates_info[0]);
      magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
      return true;
    }
    return false;
  }
  else if(gates_info.size() == 10)//nor3
  {
    name = gates_info[1];
    for(int i = 1; i < 4; i++)
    {
      inputs.push_back( gates_info[ 2*i + 1] );
    }
    outputs = gates_info[9];
    is_inv1 = false;
    is_nor2 = false;
    is_buf = false;
    is_zero = false;
    is_one = false;
    is_multi_nor = 3;//
    magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
    return true;
  }
  else if(gates_info.size() == 12)//nor4
  {
    name = gates_info[1];
    for(int i = 1; i < 5; i++)
    {
      inputs.push_back( gates_info[ 2*i + 1] );
    }
    outputs = gates_info[11];
    is_inv1 = false;
    is_nor2 = false;
    is_buf = false;
    is_zero = false;
    is_one = false;
    is_multi_nor = 4;//
    magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
    return true;
  }
  else if(gates_info.size() == 14)//nor5
  {
    name = gates_info[1];
    for(int i = 1; i < 6; i++)
    {
      inputs.push_back( gates_info[ 2*i + 1] );
    }
    outputs = gates_info[13];
    is_inv1 = false;
    is_nor2 = false;
    is_buf = false;
    is_zero = false;
    is_one = false;
    is_multi_nor = 5;//
    magic.add_gate(name, inputs, outputs, is_inv1, is_nor2, is_buf, is_zero, is_one, is_multi_nor);
    return true;
  }
  else
  {
    return false;
  }
}
