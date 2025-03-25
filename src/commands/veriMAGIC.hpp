/* LV-MAGIC: Logic Synthesis and Verification for MAGIC based In-Memory Computing
 * Copyright (C) 2025 */

/**
 * @file veriMAGIC.hpp
 *
 * @brief veriMAGIC: A automated verification methodology for MAGIC-based in-memory computing.
 *
 * @author Jiaxiang Pan
 * @since  2025/03/24
 */

#ifndef VERIMAGIC_HPP
#define VERIMAGIC_HPP

#include <alice/alice.hpp>
#include "../core/verification/verification_MAGIC.hpp"
#include "../core/logic_mapping/include/myfunction.h"

namespace alice
{

  class veriMAGIC_command : public command
  {
  public:
    explicit veriMAGIC_command(const environment::ptr &env)
        : command(env, "A automated verification methodology for MAGIC-based in-memory computing")
    {
      add_option( "filename, -f", mo_filename, "Micro-operation file described in text format" );
      add_option( "Filename, -F", spec_filename, "Design specification file described in BLIF or Verilog format" );
      add_flag("--verbose, -v", "print the information");
    }

  protected:
    void execute()
    {
      if( mo_filename.empty() || spec_filename.empty() )
      {
        std::cout << "Please specify the micro-operation file and the design specification file" << std::endl;
        return;
      }
      if (!is_executable_available("abc")) {
        std::cerr << "Error: The executable '" << "abc" << "' is not found in your system.\n";
        std::cerr << "Please install the '" << "abc" << "' software and try again.\n";
        return;
      }
      std::cout << "The executable '" << "abc" << "' is available. Proceeding...\n";

      std::string file_path = remove_quotes( mo_filename );
      std::ifstream ifs(file_path);
      std::ofstream ofs(temp_file1);
      if(!ifs.good())
      {
          std::cout << "can't open file " << mo_filename << "!" << std::endl;
          return;
      }
      write_bench(ifs, ofs);
      //spec.* to spec.bench
      std::string command = "abc -c \"read " + std::string(spec_filename) + " ;" + "write_bench " + temp_file2 + "\"";
      FILE* pipe = popen(command.c_str(), "r");
      if (!pipe) {
          std::cout << "failed to execute write command!" << std::endl;
          return;
      }
      pclose(pipe);

      clock_t startTime_1, endTime_1, startTime_2, endTime_2;
      auto start_time_1 = std::chrono::high_resolution_clock::now();
       //use ABC for verification
      std::string command2 = "abc -c \"cec -n " + temp_file1 + " " + temp_file2 + "\"" ;

      std::string output;
      char buffer[128];
      FILE* pipe2 = popen(command2.c_str(), "r");
      if (!pipe2) {
          std::cout << "failed to execute cec command!" << std::endl;
          return;
      }
      while(fgets(buffer, 128, pipe2) != NULL){
          output += buffer;
      }
      pclose(pipe2);

      auto end_time_1 = std::chrono::high_resolution_clock::now();
      double runtime_1 = std::chrono::duration<double>(end_time_1 - start_time_1).count();
      printf("[LEC time]   %.4f s\n", runtime_1);
      // std::cout << output << std::endl;
      std::cout << "[Info] The verification result of the micro-operations: " << file_path << std::endl;
      if (output.find("equivalent") != std::string::npos) {
          std::cout << "[Info] Logical equivalence verification of micro-operations pass" << std::endl;
          std::cout << "                      ^   ^\n";
          std::cout << "                        v  \n";
      } else {
          std::cout << "[Info] Logical equivalence verification of micro-operations failed" << std::endl;
          std::cout << "                      v   v\n";
          std::cout << "                        ^  \n";
      }
      std::remove( temp_file1.c_str() );
      std::remove( temp_file2.c_str() );
      std::remove( temp_file3.c_str() );

      //layout verification
      std::string file_path_2 = remove_quotes( mo_filename );
      std::ifstream ifs_2( file_path_2 );
      std::ofstream ofs_2( temp_file3);
      if(!ifs_2.good())
      {
          cout << "can't open file " << mo_filename << "!\n";
          return;
      }
      auto start_time_2 = std::chrono::high_resolution_clock::now();
      bool seq_verification_result = seq_verification(ifs_2, ofs_2);
      auto end_time_2 = std::chrono::high_resolution_clock::now();
      double runtime_2 = std::chrono::duration<double>(end_time_2 - start_time_2).count();
      printf("[DRC time]   %.4f s\n", runtime_2);
      if(seq_verification_result){
          cout << "[Info] Layout legitimacy of the micro-operations pass\n";
          cout << "                      ^   ^\n";
          cout << "                        v  \n";
      }else{
          cout << "[Info] Layout legitimacy of the micro-operations failed\n";
          cout << "                     v   v\n";
          cout << "                       ^  \n";
      }
      printf("[CPU time]   %.4f s\n", runtime_1 + runtime_2);
    }

  private:
    std::string temp_file1 = "/tmp/mc2ben.bench";
    std::string temp_file2 = "/tmp/spec.bench";
    std::string temp_file3 = "/tmp/log.txt";
    std::string mo_filename{};
    std::string spec_filename{};
  };

  ALICE_ADD_COMMAND(veriMAGIC, "Verification")

}

#endif