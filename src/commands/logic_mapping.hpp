/* LV-MAGIC: Logic Synthesis and Verification for MAGIC based In-Memory Computing
 * Copyright (C) 2025 */

/**
 * @file logic_mapping.hpp
 *
 * @brief logicmapping: A integrated logic mapping tool for MAGIC-based in-memory computing.
 *
 * @author Jiaxiang Pan
 * @since  2025/03/25
 */

#ifndef LOGIC_MAPPING_HPP
#define LOGIC_MAPPING_HPP

#include <alice/alice.hpp>
#include "../core/logic_mapping/include/magic.h"
#include "../core/logic_mapping/include/myfunction.h"
#include "../core/logic_mapping/include/mytime.h"
#include "../core/logic_mapping/include/netlist_parser.h"
#include <string>
#include <fstream>
#include <time.h>
#include <map> 

namespace alice
{

  class logicmapping_command : public command
  {
  public:
    explicit logicmapping_command(const environment::ptr &env)
        : command(env, "A logic mapping tool for MAGIC-based in-memory computing\n[i]uagae: logicmapping -f filename -s -r row_size OR logicmapping -f filename -S")
    {
      add_option( "filename, -f", netlist_filename, "Netlist file described in text format" );
      add_option( "rowSize, -r", row_size, "Size of the RRAM crossbar array" );
      add_flag("--verbose, -v", "print the information");
      add_flag( "--simpler, -s",  "Perform logic mapping using the SIMPLER method" );
      add_flag( "--simplest, -S",  "Perform logic mapping using the SIMPLEST method" );
      add_flag( "--dse, -d",  "Perform logic mapping for design space exploration" );
      add_flag( "--greedy, -g",  "Perform logic mapping using the Greedy method" );
    }

  protected:
    void execute()
    {
        if( netlist_filename.size() == 0 )
        {
            std::cout << "Please specify the netlist file" << std::endl;
            return;
        }
        std::string file_path = remove_quotes( netlist_filename );
        std::ifstream ifs(file_path);
        if (!ifs.good())
        {
            std::cout << "[Error] can't open file" << netlist_filename << "!\n";
            return;
        }
        auto Par = 0;
        ElapsedTimer t(true);
        std::string mbenchmark_name = get_benchmark_name(std::string(netlist_filename));
        if(is_set("simpler"))
        {
            if( row_size.size() == 0 )
            {
                std::cout << "Please specify the row size" << std::endl;
                return;
            }
            Magic magic(mbenchmark_name, std::stoi(row_size));
            Parser parser;
            if (!parser.parse(ifs, magic))
            {
                std::cout << "[Error] can't parse file" << netlist_filename << "!\n";
                return;
            }
            Par =  t.get_elapsed_us();
            std::cout << "*******************************************************************************\n";
            std::cout << "  +Benchmark: " << netlist_filename << std::endl;
            std::cout << "  +Time for netlist parser:   " << 1.0 * Par / 1000 << "  ms\n";
            magic.prepare( false );
            magic.run_simpler();
        }
        else if(is_set("simplest"))
        {
            Magic magic(mbenchmark_name);
            Parser parser;
            if (!parser.parse(ifs, magic))
            {
                std::cout << "[Error] can't parse file" << netlist_filename << "!\n";
                return;
            }
            Par =  t.get_elapsed_us();
            std::cout << "*******************************************************************************\n";
            std::cout << "  +Benchmark: " << netlist_filename << std::endl;
            std::cout << "  +Time for netlist parser:   " << 1.0 * Par / 1000 << "  ms\n";
            magic.prepare( true ); //treu - RL_show, false - advance_show_stats()
            magic.run_simplest();
        }
        else if(is_set("dse"))
        {
            Magic magic(mbenchmark_name, std::stoi(row_size));
            Parser parser;
            if (!parser.parse(ifs, magic))
            {
                std::cout << "[Error] can't parse file" << netlist_filename << "!\n";
                return;
            }
            Par =  t.get_elapsed_us();
            std::cout << "*******************************************************************************\n";
            std::cout << "  +Benchmark: " << netlist_filename << std::endl;
            std::cout << "  +Time for netlist parser:   " << 1.0 * Par / 1000 << "  ms\n";
            magic.prepare( true );
            magic.design_space_exploration();
        }
        else if(is_set("greedy"))
        {
            Magic magic(mbenchmark_name, std::stoi(row_size));
            Parser parser;
            if (!parser.parse(ifs, magic))
            {
                std::cout << "[Error] can't parse file" << netlist_filename << "!\n";
                return;
            }
            Par =  t.get_elapsed_us();
            std::cout << "*******************************************************************************\n";
            std::cout << "  +Benchmark: " << netlist_filename << std::endl;
            std::cout << "  +Time for netlist parser:   " << 1.0 * Par / 1000 << "  s\n";
            magic.prepare( false );
            magic.initialize_cells();
            // magic.test_GreedyExecutionSequence( "/home/panjiaxiang/pjx_research/magic/greedy_result.txt" );
            magic.test_result_of_greedy( 5, "/home/panjiaxiang/pjx_research/magic/greedy_result.txt" );  //FILE PATH CAN BE MODIFIED
        }
        else
        {
            std::cout << "[Error] This mapping_model does not exist\n";
		    // std::cout << "[i]uagae: magic filename -simpler row_size OR magic filename -simplest\n";
		    return;
        }

    }

  private:
    std::string netlist_filename{};
    std::string row_size{};
  };

  ALICE_ADD_COMMAND(logicmapping, "MAGIC")

}

#endif