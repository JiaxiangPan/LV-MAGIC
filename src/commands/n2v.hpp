/* LV-MAGIC: Logic Synthesis and Verification for MAGIC based In-Memory Computing
 * Copyright (C) 2025 */

/**
 * @file n2v.hpp
 *
 * @brief n2v: Convert netlist(nor2 inv1) to verilog format.
 *
 * @author Jiaxiang Pan
 * @since  2025/03/25
 */

 #ifndef N2V_HPP
 #define N2V_HPP
 
 #include <alice/alice.hpp>
 #include <fstream>
 #include "../core/netlist_to_verilog.hpp"
 
 namespace alice
 {
 
   class n2v_command : public command
   {
   public:
     explicit n2v_command(const environment::ptr &env)
         : command(env, "Convert netlist(nor2 inv1) to verilog format")
     {
       add_option( "filename, -f", netlist_filename, "Netlist file described in verilog format" );
       add_option( "Filename, -F", verilog_filename, "Output verilog file" );
       add_flag("--verbose, -v", "print the information");
     }
 
   protected:
     void execute()
     {
        if( netlist_filename.empty() || verilog_filename.empty() )
        {
          std::cout << "Please specify the netlist file and the output verilog file" << std::endl;
          return;
        }
        std::ifstream ifs(netlist_filename);
        std::ofstream ofs(verilog_filename);
        if(!ifs.good())
        {
            std::cout << "can't open file " << netlist_filename << "!\n";
            return;
        }
        write_verilog(ifs, ofs);
     }
 
   private:
     std::string netlist_filename{};
     std::string verilog_filename{};
   };
 
   ALICE_ADD_COMMAND(n2v, "MAGIC")
 
 }
 
 #endif