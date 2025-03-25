#include <iostream>
#include <vector>
#include "logic_mapping/include/myfunction.h"

void write_verilog(std::ifstream &ifs, std::ofstream &ofs)
{
    const std::string flag_inputs = "input";
    const std::string flag_outputs = "output";
    const std::string flag_wires = "wire";
    const std::string  flag_end = ";";
    const std::string flag_node1 = "inv1";
    const std::string flag_node2 = "nor2";

    std::string input_statement;
    std::string output_statement;
    std::string wire_statement;
    std::vector<std::string> top_str;
    std::vector<std::string> input_store;
    std::vector<std::string> output_store;
    std::vector<std::string> wire_store;
    std::vector<std::string> inv_store;
    std::vector<std::string> nor_store;

    for (std::string line; std::getline(ifs, line, '\n');)
    {
        if(line.find(flag_inputs) != std::string::npos)
        {
            
            if(line.find(flag_end) != std::string::npos)
            {
                std::vector<std::string> inputs_str = m_split(line, " ,;"); 
                for(int i = 1;i < inputs_str.size(); i++)
                {
                    // std::cout << input << ",";
                    input_store.push_back(inputs_str[i]);
                    // ofs << "  input " << inputs_str[i] << ";" << std::endl;
                    top_str.push_back(inputs_str[i]);
                }
                // std::cout << std::endl;
            }
            else
            {
                input_statement = line;
                while(getline(ifs, line, '\n'))
                { 
                input_statement += line;
                if(line.find(flag_end) != std::string::npos)
                {
                    std::vector<std::string> inputs_str = m_split(input_statement, " ,;");
                    for(int i = 1;i < inputs_str.size(); i++)
                    {
                        // std::cout << input << ",";
                        input_store.push_back(inputs_str[i]);
                        // ofs << "  input " << inputs_str[i] << ";" << std::endl;
                        top_str.push_back(inputs_str[i]);
                    }
                    // std::cout << std::endl;
                    break;
                }
                }
            }
            continue;
        }
        if(line.find(flag_outputs) != std::string::npos)
        {
            if(line.find(flag_end) != std::string::npos)
            {
                std::vector<std::string> inputs_str = m_split(line, " ,;"); 
                for(int i = 1;i < inputs_str.size(); i++)
                {
                    // std::cout << input << ",";
                    output_store.push_back(inputs_str[i]);
                    // ofs << "  output " << inputs_str[i] << ";" << std::endl;
                    top_str.push_back(inputs_str[i]);
                }
                // std::cout << std::endl;
            }
            else
            {
                input_statement = line;
                while(getline(ifs, line, '\n'))
                { 
                input_statement += line;
                if(line.find(flag_end) != std::string::npos)
                {
                    std::vector<std::string> inputs_str = m_split(input_statement, " ,;");
                    for(int i = 1;i < inputs_str.size(); i++)
                    {
                        // std::cout << input << ",";
                         output_store.push_back(inputs_str[i]);
                        // ofs << "  output " << inputs_str[i] << ";" << std::endl;
                        top_str.push_back(inputs_str[i]);
                    }
                    // std::cout << std::endl;
                    break;
                }
                }
            }
            continue;
        }
        if(line.find(flag_wires) != std::string::npos)
        {
            if(line.find(flag_end) != std::string::npos)
            {
                std::vector<std::string> inputs_str = m_split(line, " ,;"); 
                for(int i = 1;i < inputs_str.size(); i++)
                {
                    // std::cout << input << ",";
                    wire_store.push_back(inputs_str[i]);
                    // ofs << "  wire " << inputs_str[i] << ";" << std::endl;
                }
                // std::cout << std::endl;
            }
            else
            {
                input_statement = line;
                while(getline(ifs, line, '\n'))
                { 
                input_statement += line;
                if(line.find(flag_end) != std::string::npos)
                {
                    std::vector<std::string> inputs_str = m_split(input_statement, " ,;");
                    for(int i = 1;i < inputs_str.size(); i++)
                    {
                        // std::cout << input << ",";
                        wire_store.push_back(inputs_str[i]);
                        // ofs << "  wire " << inputs_str[i] << ";" << std::endl;
                    }
                    // std::cout << std::endl;
                    break;
                }
                }
            }
            continue;
        }
 
        // inv1 g0000(.a(\a[0] ), .O(new_n386_));
        // imp2 g0001(.a(\b[0] ), .b(new_n386_), .O(new_n387_));
        
        // inv1 g01(.a(pb), .O(new_n8_));
        // nor2 g02(.a(new_n8_), .b(new_n7_), .O(new_n9_));
        if(line.find(flag_node1) != std::string::npos)
        {   
            // inv1 g0000 .a \a[0] .O new_n386_
            std::vector<std::string> str_info = m_split(line, " (),;");
            for(int i = 1;i < str_info.size(); i++)
            {
                inv_store.push_back(str_info[i]);
            }
            // ofs << "  assign " << str_info[5] << " = " << "~" << str_info[3] << ";" << std::endl;
        }
        if(line.find(flag_node2) != std::string::npos)
        {
            // imp2 g0001 .a \b[0] .b new_n386_ .O new_n387_
            std::vector<std::string> str_info = m_split(line, " (),;");
            for(int i =1 ; i < str_info.size(); i++)
            {
               nor_store.push_back(str_info[i]);
            }
            // ofs << "  assign " << str_info[7] << " = " << "~" << str_info[3] << " | " << str_info[5] << ";" << std::endl;
        }
    }
    std::string top = "module top(";
    for(int i = 0;i < top_str.size(); i++)
    {   
        if(i < top_str.size() - 1)
        {
           top = top + top_str[i] +", ";
        }
       else
       {
        top = top + top_str[i];
       } 
    }
    top += ");";
    ofs << top << std::endl;
     for(int i=0; i<input_store.size(); i++)
      {
        ofs << "  input " << input_store[i] << ";" << std::endl;
      }
     for(int i = 0; i < output_store.size(); i++)
      {
        ofs << "  output " << output_store[i] << ";" << std::endl;
      }
     for(int i = 0;i < wire_store.size(); i++)
      {
         ofs << "  wire " << wire_store[i] << ";" << std::endl;
      }
      for(int i = 0; i < inv_store.size(); i++)
      {
        i = i + 4;
        int t = i - 2;
        // g0000 .a \a[0] .O new_n386_
         ofs << "  assign " << inv_store[i] << " = " << "~" << inv_store[t] << ";" <<std::endl;
        
      }
      for(int i =0; i < nor_store.size(); i++)
      { 
         i = i + 6;
        int t = i - 4;
        int m = i - 2;
        // g0001 .a \b[0] .b new_n386_ .O new_n387_
         ofs << "  assign " << nor_store[i] << " = " << "~(" << nor_store[t] << " | " << nor_store[m] << ");" <<std::endl;
      }
    std::string bottom = "endmodule";
    ofs << bottom << std::endl;

}