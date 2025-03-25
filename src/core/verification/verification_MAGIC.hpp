#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include "../logic_mapping/include/myfunction.h"

using namespace std;

bool is_in_range(const vector<int>& elements, const int& row_size)
{
    for (const auto& element : elements)
    {
        if (element > (row_size - 1))
            return false;
    }
    return true;
}

void write_bench(std::ifstream &ifs, std::ofstream &ofs)
{
    const std::string flag_inputs = "Inputs";
    const std::string flag_outputs = "Outputs";
    const std::string flag_cycles = "Cycle";
    const std::string flag_assign = "assign constant";
    for (std::string line; std::getline(ifs, line, '\n');)
    {
        if(line.find(flag_assign) != std::string::npos)
        {
            std::string const_value{};
            if(line.find("one") != std::string::npos) 
                const_value = "vdd";
            if(line.find("zero") != std::string::npos)
                const_value = "gnd";
            std::string port = line.substr(line.find(":") + 2);
            ofs << port << " = " << const_value << std::endl;
        }
        if(line.find(flag_inputs) != std::string::npos)
        {
            std::string port_str = line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1);
            std::vector<std::string> inputs_info = m_split(port_str, ",()");
            std::vector<std::string> input_ports;
            for(int i = 0; i < inputs_info.size(); i+=2)
            {
                input_ports.push_back(inputs_info[i]);
            }
            for(auto & input_port : input_ports)
            {
                // std::cout << input_port << ",";//
                if(input_port.find("\\")!= std::string::npos)//deleate "\"
                {
                    input_port = input_port.substr(1);
                }
                ofs << "INPUT(" << input_port << ")" << std::endl;
            }
            // std::cout << std::endl;
        }
        if(line.find(flag_outputs) != std::string::npos)
        {
            std::string port_str = line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1 );
            std::vector<std::string> outputs_info = m_split(port_str, ",()");
            std::vector<std::string> output_ports;
            for(int i = 0; i < outputs_info.size(); i+=2)
            {
                output_ports.push_back(outputs_info[i]);
            }
            for(auto & output_port : output_ports)
            {
                // std::cout << output_port << ",";//
                if(output_port.find("\\") != std::string::npos)//deleate "\"
                    output_port = output_port.substr(1);
                ofs << "OUTPUT(" << output_port << ")" << std::endl;
            }
            // std::cout << std::endl;
        }
        if(line.find(flag_cycles) != std::string::npos)
        {
            if(line.find("inv1") != std::string::npos)
            {
                std::string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                std::string out_str = left_string.substr(0, left_string.find("("));

                std::string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                std::string in_str = right_string.substr(1, right_string.find("(") - right_string.find("{") - 1);

                if(out_str.find("\\") != std::string::npos)
                    out_str = out_str.substr(1);
                if(in_str.find("\\") != std::string::npos)
                    in_str = in_str.substr(1);
                // m_print("out_str", out_str);
                // m_print("in_str", in_str);

                ofs << out_str << " = LUT 0x1 (" << in_str << ")" << std::endl; 

            }
            else if(line.find("buf") != std::string::npos)
            {
                std::string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                std::string out_str = left_string.substr(0, left_string.find("("));

                std::string right_string = line.substr(line.find("=") + 4, line.find("}") - line.find("{") + 1 );
                std::string in_str = right_string.substr(1, right_string.find("(") - right_string.find("{") - 1);

                if(out_str.find("\\") != std::string::npos)
                    out_str = out_str.substr(1);
                if(in_str.find("\\") != std::string::npos)
                    in_str = in_str.substr(1);
                // m_print("out_str", out_str);
                // m_print("in_str", in_str);

                ofs << out_str << " = LUT 0x2 (" << in_str << ")" << std::endl; 
            }
            else if(line.find("nor2") != std::string::npos)
            {
                std::string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                std::string out_str = left_string.substr(0, left_string.find("("));
                

                std::string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                std::string rl_str = right_string.substr(1, right_string.find(",") - 1);
                std::string rr_str = right_string.substr(right_string.find(",") + 1, right_string.find("}") - right_string.find(",") - 1);
                std::string in_str1 = rl_str.substr(0, rl_str.find("("));
                std::string in_str2 = rr_str.substr(0, rr_str.find("("));
                
                if(out_str.find("\\") != std::string::npos)
                    out_str = out_str.substr(1);
                if(in_str1.find("\\") != std::string::npos)
                    in_str1 = in_str1.substr(1);
                if(in_str2.find("\\") != std::string::npos)
                    in_str2 = in_str2.substr(1);

                // m_print("nor2_out_str", out_str);
                // m_print("in_str1", in_str1);
                // m_print("in_str2", in_str2);                    

                ofs << out_str << " = LUT 0x1 (" << in_str1 << ", " << in_str2 << ")" << std::endl;
            }
            else if(line.find("nor3") != std::string::npos)
            {
                std::string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                std::string out_str = left_string.substr(0, left_string.find("("));
                

                std::string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                std::vector<std::string> result_strs = m_split(right_string, "{}(),");
                assert(result_strs.size() == 6);
                // for(const auto & str : result_strs)
                // {
                //     std::cout << str << ",";
                // }
                // std::cout << std::endl;
                ofs << out_str << " = LUT 0x01 (" << result_strs[0] << ", " << result_strs[2] << ", " << result_strs[4] << ")" << std::endl;
            }
            else if(line.find("nor4") != std::string::npos)
            {
                std::string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                std::string out_str = left_string.substr(0, left_string.find("("));
                
                std::string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                std::vector<std::string> result_strs = m_split(right_string, "{}(),");
                assert(result_strs.size() == 8);
                ofs << out_str << " = LUT 0x0001 (" << result_strs[0] << ", " << result_strs[2] << ", " << result_strs[4] << ", " << result_strs[6] << ")" << std::endl;
            }
            else if(line.find("nor5") != std::string::npos)
            {
                std::string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                std::string out_str = left_string.substr(0, left_string.find("("));
                

                std::string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                std::vector<std::string> result_strs = m_split(right_string, "{}(),");
                assert(result_strs.size() == 10);
                ofs << out_str << " = LUT 0x00000001 (" << result_strs[0] << ", " << result_strs[2] << ", " << result_strs[4] << ", " << result_strs[6] << ", " << result_strs[8] << ")" << std::endl;
            }
            else if(line.find("Initialization") != std::string::npos)
            {
                continue;
            }
            else
            {
                std::cout << line << std::endl;
                std::cerr << "Error: unrecognized Cycle type!" << std::endl;
                exit(1);
            }
        }
    }
}

bool seq_verification(ifstream &ifs, ofstream &ofs)
{
    string flag_rowsize = "Row size";
    const string flag_inputs = "Inputs";
    const string flag_cycles = "Cycle";

    unordered_set<int> available{};
    unordered_set<int> used{};
    vector<vector<int>> cycles_cells{};//store cell_idx in each Cycle(no Cycle0)
    vector<unordered_map<int, string>> indexs_ports;//store all "index_to_port"
    int row_size = 0;
    unordered_map<int, string> ports_record;//验证过程中记录port

    //output memristors need to be initialized to logic 1 before performing computation
    std::vector<int> logic_one_cells{}; //store the cell index of (logic 1 cell)

    for (string line; getline(ifs, line, '\n');)
    {
        if(line.find(flag_rowsize) != string::npos)
        {
            string size = line.substr(line.find(":") + 2);
            row_size = stoi(size);
        }
        if(line.find(flag_inputs) != string::npos)
        {
            string port_str = line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1);
            vector<string> inputs_info = m_split(port_str, ",()");
            vector<string> input_ports;
            for(int i = 0; i < inputs_info.size(); i+=2)
            {
                input_ports.push_back(inputs_info[i]);
            }
            //initial index - port_name
            unordered_map<int, string> indexsports;//
            for(int i = 0; i < inputs_info.size(); i += 2)
            {
                indexsports.insert( make_pair( stoi(inputs_info[i+1]), inputs_info[i] ) );
                ports_record.insert( make_pair( stoi(inputs_info[i+1]), inputs_info[i] ) );
            }
            indexs_ports.push_back(indexsports);
            //initial used(inputs)
            for(int i = 0;i < input_ports.size(); i++)
            {
                used.insert(i);
                //m_print("used: ", i);
            }
            //initial available
            for(int i = 0; i < row_size - input_ports.size(); i++ )
            {
                available.insert(input_ports.size() + i);
                //m_print("available: ", input_ports.size() + i);
            }
        }
        if( line.find("Cycle0") != std::string::npos )
        {
            string init_string = line.substr( line.find("{") + 2, line.find("}") - line.find("{") - 3 );
            // m_print( init_string );
            vector<string> init_string_split = m_split(init_string, "(),");
            // print_vector( init_string_split );
            for(int i = 0; i < init_string_split.size(); i+=2)
            {
                logic_one_cells.push_back( stoi( init_string_split[i+1] ) );
            }
            // print_vector( logic_one_cells );
        }
        if(line.find(flag_cycles) != string::npos && line.find("Cycle0") == string::npos)
        {
            // cout << line << endl;
            if(line.find("inv1") != string::npos)
            {
                unordered_map<int, string> indexsports;//
                vector<int> cells;
                string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                string out_str = left_string.substr(left_string.find("(") + 1, left_string.find(")") - left_string.find("(") - 1);
                // m_print(out_str);
                string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                string in_str = right_string.substr(right_string.find("(") + 1, right_string.find(")") - right_string.find("(") - 1);               
                // m_print(in_str);
                cells.push_back(stoi(out_str));
                cells.push_back(stoi(in_str));
                assert(cells.size() == 2);
                cycles_cells.push_back(cells);

                //new_n5_(4)=inv1{a(0)}
                string assignment = line.substr(line.find(":") + 2, line.find("}") - line.find(":") - 1);
                // cout << assignment << endl;
                vector<string> assignment_splited = m_split(assignment, "=(){}");
                //new_n5_ 4 inv1 a 0
                indexsports.insert(make_pair( stoi(assignment_splited[1]), assignment_splited[0] ));
                indexsports.insert(make_pair( stoi(assignment_splited[4]), assignment_splited[3] ));
                indexs_ports.push_back(indexsports);

            }
            else if(line.find("nor2") != string::npos)
            {

                unordered_map<int, string> indexsports;//
                vector<int> cells;
                string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                string out_str = left_string.substr(left_string.find("(") + 1, left_string.find(")") - left_string.find("(") - 1);
                // m_print(out_str);

                string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1 );
                string rl_str = right_string.substr(1, right_string.find(",") - 1);
                string rr_str = right_string.substr(right_string.find(",") + 1, right_string.find("}") - right_string.find(",") - 1);
                string in_str1 = rl_str.substr(rl_str.find("(") + 1, rl_str.find(")") - rl_str.find("(") - 1);
                string in_str2 = rr_str.substr(rr_str.find("(") + 1, rr_str.find(")") - rr_str.find("(") - 1);
                
                // m_print(in_str1);
                // m_print(in_str2);
                cells.push_back(stoi(out_str));
                cells.push_back(stoi(in_str1));
                cells.push_back(stoi(in_str2));
                assert(cells.size() == 3);
                cycles_cells.push_back(cells);

                //cout(2)=nor2{new_n6_(3),new_n5_(4)}
                string assignment = line.substr(line.find(":") + 2, line.find("}") - line.find(":") - 1);
                // cout << assignment << endl;
                vector<string> assignment_splited = m_split(assignment, ",=(){}");
                //cout 2 nor2 new_n6_ 3  new_n5_ 4
                indexsports.insert(make_pair( stoi(assignment_splited[1]), assignment_splited[0] ));
                indexsports.insert(make_pair( stoi(assignment_splited[4]), assignment_splited[3] ));
                indexsports.insert(make_pair( stoi(assignment_splited[6]), assignment_splited[5] ));
                indexs_ports.push_back(indexsports);
            }
            else if(line.find("nor3") != string::npos)
            {
                unordered_map<int, string> indexsports;//
                vector<int> cells;
                string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                string out_str = left_string.substr(left_string.find("(") + 1, left_string.find(")") - left_string.find("(") - 1);
                cells.push_back(stoi(out_str));

                string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1);
                size_t startPos = 0;
                size_t endPos = 0;

                while (startPos != string::npos && endPos != string::npos) {
                    startPos = right_string.find("(", endPos);
                    endPos = right_string.find(")", startPos);

                    if (startPos != string::npos && endPos != string::npos) {
                        string num = right_string.substr(startPos + 1, endPos - startPos - 1);
                        cells.push_back(stoi(num));
                    }
                }
                assert(cells.size() == 4);
                cycles_cells.push_back(cells);

                string right_string_2 = line.substr(line.find("=") + 6, line.find("}") - line.find("{") - 1);
                //new_n109_(81)=nor3{new_n108_(82),new_n106_(84),new_n103_(87)}
                vector<string> left_string_split = m_split( left_string, "()");//new_n109_ 81
                vector<string> right_string_split = m_split( right_string_2, "()," );//new_n108_ 82 new_n106_ 84 new_n103_ 87
                // print_vector(left_string_split);
                // print_vector(right_string_split);
                indexsports.insert( make_pair( stoi(left_string_split[1]), left_string_split[0] ) );
                indexsports.insert( make_pair( stoi(right_string_split[1]), right_string_split[0] ) );
                indexsports.insert( make_pair( stoi(right_string_split[3]), right_string_split[2] ) );
                indexsports.insert( make_pair( stoi(right_string_split[5]), right_string_split[4] ) );
                indexs_ports.push_back(indexsports);

            }
            else if(line.find("nor4") != string::npos)
            {
                unordered_map<int, string> indexsports;//
                vector<int> cells;
                string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                string out_str = left_string.substr(left_string.find("(") + 1, left_string.find(")") - left_string.find("(") - 1);
                cells.push_back(stoi(out_str));

                string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1);
                size_t startPos = 0;
                size_t endPos = 0;

                while (startPos != string::npos && endPos != string::npos) {
                    startPos = right_string.find("(", endPos);
                    endPos = right_string.find(")", startPos);

                    if (startPos != string::npos && endPos != string::npos) {
                        string num = right_string.substr(startPos + 1, endPos - startPos - 1);
                        cells.push_back(stoi(num));
                    }
                }
                assert(cells.size() == 5);
                cycles_cells.push_back(cells);

                string right_string_2 = line.substr(line.find("=") + 6, line.find("}") - line.find("{") - 1);
                //new_n219_(57)=nor4{new_n125_(65),new_n87_(63),porwd_n(7),new_n90_(64)}
                vector<string> left_string_split = m_split( left_string, "()");//new_n219_ 57 
                vector<string> right_string_split = m_split( right_string_2, "()," );//new_n125_ 65 new_n87_ 63 porwd_n 7 new_n90_ 64 ,
                // print_vector(left_string_split);
                // print_vector(right_string_split);
                indexsports.insert( make_pair( stoi(left_string_split[1]), left_string_split[0] ) );
                indexsports.insert( make_pair( stoi(right_string_split[1]), right_string_split[0] ) );
                indexsports.insert( make_pair( stoi(right_string_split[3]), right_string_split[2] ) );
                indexsports.insert( make_pair( stoi(right_string_split[5]), right_string_split[4] ) );
                indexsports.insert( make_pair( stoi(right_string_split[7]), right_string_split[6] ) );
                indexs_ports.push_back(indexsports);

            }
            else if(line.find("nor5") != string::npos)
            {
                unordered_map<int, string> indexsports;//
                vector<int> cells;
                string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                string out_str = left_string.substr(left_string.find("(") + 1, left_string.find(")") - left_string.find("(") - 1);
                cells.push_back(stoi(out_str));

                string right_string = line.substr(line.find("=") + 5, line.find("}") - line.find("{") + 1);
                size_t startPos = 0;
                size_t endPos = 0;

                while (startPos != string::npos && endPos != string::npos) {
                    startPos = right_string.find("(", endPos);
                    endPos = right_string.find(")", startPos);

                    if (startPos != string::npos && endPos != string::npos) {
                        string num = right_string.substr(startPos + 1, endPos - startPos - 1);
                        cells.push_back(stoi(num));
                    }
                }
                assert(cells.size() == 6);
                cycles_cells.push_back(cells);

                string right_string_2 = line.substr(line.find("=") + 6, line.find("}") - line.find("{") - 1);
                //new_n224_(59)=nor5{new_n223_(60),new_n125_(65),new_n87_(63),porwd_n(7),new_n90_(64)}
                vector<string> left_string_split = m_split( left_string, "()");//new_n224_ 59 
                vector<string> right_string_split = m_split( right_string_2, "()," );//new_n223_ 60 new_n125_ 65 new_n87_ 63 porwd_n 7 ew_n90_ 64 
                // print_vector(left_string_split);
                // print_vector(right_string_split);
                indexsports.insert( make_pair( stoi(left_string_split[1]), left_string_split[0] ) );
                indexsports.insert( make_pair( stoi(right_string_split[1]), right_string_split[0] ) );
                indexsports.insert( make_pair( stoi(right_string_split[3]), right_string_split[2] ) );
                indexsports.insert( make_pair( stoi(right_string_split[5]), right_string_split[4] ) );
                indexsports.insert( make_pair( stoi(right_string_split[7]), right_string_split[6] ) );
                indexsports.insert( make_pair( stoi(right_string_split[9]), right_string_split[8] ) );
                indexs_ports.push_back(indexsports);

            }
            else if(line.find("buf") != string::npos)
            {
                unordered_map<int, string> indexsports;//
                vector<int> cells;
                string left_string = line.substr(line.find(":") + 2, line.find("=") - line.find(":") - 2);
                string out_str = left_string.substr(left_string.find("(") + 1, left_string.find(")") - left_string.find("(") - 1);
                
                string right_string = line.substr(line.find("=") + 4, line.find("}") - line.find("{") + 1 );
                string in_str = right_string.substr(right_string.find("(") + 1, right_string.find(")") - right_string.find("(") - 1);               
                cells.push_back(stoi(out_str));
                cells.push_back(stoi(in_str));
                assert(cells.size() == 2);
                cycles_cells.push_back(cells);

                //psdo(86)=buf{pvst0(19)}
                string assignment = line.substr(line.find(":") + 2, line.find("}") - line.find(":") - 1);
                // cout << assignment << endl;
                vector<string> assignment_splited = m_split(assignment, "=(){}");
                // print_vector(assignment_splited);
                indexsports.insert(make_pair( stoi(assignment_splited[1]), assignment_splited[0] ));
                indexsports.insert(make_pair( stoi(assignment_splited[4]), assignment_splited[3] ));
                indexs_ports.push_back(indexsports);

            }
            else if(line.find("Initialization") != string::npos)
            {

                vector<int> cells;
                string str = line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1);
                vector<string> str1 = m_split(str, ",()");
                cells.push_back(-1);//first element -1 means Initialization
                for(int i = 1; i < str1.size(); i = i + 2)
                {
                    // cout <<  " init " << str1[i] << endl;
                    cells.push_back(stoi(str1[i]));
                }
                cycles_cells.push_back(cells);

                unordered_map<int, string> indexsports;
                //str1: new_n6_ 3 new_n5_ 4
                // for(const auto & ass : str1)
                // {
                //     cout << ass << endl;
                // }
                indexsports.insert(make_pair(  -1, "Initialization" ));//区分别的元素
                for(int i = 0; i < str1.size(); i += 2)
                {
                    indexsports.insert(make_pair(  stoi(str1[i + 1]), str1[i] ));
                }
                indexs_ports.push_back(indexsports);
            }
            else
            {
                std::cout << line << std::endl;
                cerr << "Error: unrecognized Cycle type!" << endl;
                exit(1);
            }
        }
    }
    // std::cout << "Print indexs_ports\n";
    // for (const auto & indexs_port : indexs_ports)
    // {
    //     for(const auto & element : indexs_port)
    //     {
    //         cout << element.first << " , " << element.second << endl;
    //     }
    //     cout << "**********" << endl;
    // } 

    // assert(indexs_ports.size() == (cycles_cells.size() + 1) );

    // std::cout << "Print cycles_cells\n";
    // for(const auto & cycle : cycles_cells)
    // {
    //     for(const auto c : cycle)
    //     {
    //         cout << c << ",";
    //     }
    //     cout << "**********" << endl;
    // }
    
    //verification 
    int flag = 0;
    for (int i = 0; i < cycles_cells.size(); i++) 
    {
        vector<int> cycle = cycles_cells[i];
        //element in each cycle must in range(0, row_size - 1)
        if(!is_in_range(cycle, row_size)) return false;
        //Layout legitimacy checking
        if (cycle[0] == -1) { 
            for (int i = 1; i < cycle.size(); ++i) {
                if (used.find(cycle[i]) == used.end()) {
                    return false;
                }
            }
            for (int i = 1; i < cycle.size(); ++i) {
                used.erase(cycle[i]);
                available.insert(cycle[i]);
                logic_one_cells.push_back( cycle[i] );
            }
            // print_vector( logic_one_cells );

            unordered_map<int, string> ports = indexs_ports[flag + 1];
            for (int i = 1; i < cycle.size(); ++i)
            {
                if( ports.find( cycle[i] ) == ports.end() )
                    return false;
                else
                    ports_record.erase( cycle[i] );
            }
        } 
        else if(cycle.size() == 6)
        {//nor5
            if (available.find(cycle[0]) == available.end() ||
                used.find(cycle[1]) == used.end() ||
                used.find(cycle[2]) == used.end() ||
                used.find(cycle[3]) == used.end() ||
                used.find(cycle[4]) == used.end() ||
                used.find(cycle[5]) == used.end()) {
                return false;
            }
            available.erase(cycle[0]);
            used.insert(cycle[0]);

            auto it = std::find( logic_one_cells.begin(), logic_one_cells.end(), cycle[0] );
            if( it == logic_one_cells.end()) 
            {
                return false;
            }   
            else
            {
                logic_one_cells.erase( it );
            }
            // m_print( "after delete:" );
            // print_vector( logic_one_cells );
            

            unordered_map<int, string> ports = indexs_ports[flag + 1];
            if(ports.find( cycle[1] ) == ports.end() || ports.find( cycle[2] ) == ports.end() || ports.find( cycle[3] ) == ports.end() || ports.find( cycle[4] ) == ports.end() || ports.find( cycle[5] ) == ports.end())
                return false;
            else if( ports[ cycle[1] ] != ports_record[ cycle[1] ] || ports[ cycle[2] ] != ports_record[ cycle[2] ] || ports[ cycle[3] ] != ports_record[ cycle[3] ] || ports[ cycle[4] ] != ports_record[ cycle[4] ] || ports[ cycle[5] ] != ports_record[ cycle[5] ] )
                return false;
            
            if(ports.find( cycle[0] ) != ports.end() )
                ports_record.insert( make_pair(cycle[0], ports[cycle[0]]) );
            else
                return false;
        }
        else if(cycle.size() == 5)
        {
            //nor4
            if (available.find(cycle[0]) == available.end() ||
                used.find(cycle[1]) == used.end() ||
                used.find(cycle[2]) == used.end() ||
                used.find(cycle[3]) == used.end() ||
                used.find(cycle[4]) == used.end()) {
                return false;
            }
            available.erase(cycle[0]);
            used.insert(cycle[0]);

            auto it = std::find( logic_one_cells.begin(), logic_one_cells.end(), cycle[0] );
            if( it == logic_one_cells.end()) 
            {
                return false;
            }   
            else
            {
                logic_one_cells.erase( it );
            }
            // m_print( "after delete:" );
            // print_vector( logic_one_cells );

            unordered_map<int, string> ports = indexs_ports[flag + 1];
            if(ports.find( cycle[1] ) == ports.end() || ports.find( cycle[2] ) == ports.end() || ports.find( cycle[3] ) == ports.end() || ports.find( cycle[4] ) == ports.end())
                return false;
            else if( ports[ cycle[1] ] != ports_record[ cycle[1] ] || ports[ cycle[2] ] != ports_record[ cycle[2] ] || ports[ cycle[3] ] != ports_record[ cycle[3] ] || ports[ cycle[4] ] != ports_record[ cycle[4] ] )
                return false;
            
            if(ports.find( cycle[0] ) != ports.end() )
                ports_record.insert( make_pair(cycle[0], ports[cycle[0]]) );
            else
                return false; 
        }
        else if(cycle.size() == 4)
        {
            //nor3
            if (available.find(cycle[0]) == available.end() ||
                used.find(cycle[1]) == used.end() ||
                used.find(cycle[2]) == used.end() ||
                used.find(cycle[3]) == used.end()) {
                return false;
            }
            available.erase(cycle[0]);
            used.insert(cycle[0]);

            auto it = std::find( logic_one_cells.begin(), logic_one_cells.end(), cycle[0] );
            if( it == logic_one_cells.end()) 
            {
                return false;
            }   
            else
            {
                logic_one_cells.erase( it );
            }
            // m_print( "after delete:" );
            // print_vector( logic_one_cells );

            unordered_map<int, string> ports = indexs_ports[flag + 1];
            if(ports.find( cycle[1] ) == ports.end() || ports.find( cycle[2] ) == ports.end() || ports.find( cycle[3] ) == ports.end())
                return false;
            else if( ports[ cycle[1] ] != ports_record[ cycle[1] ] || ports[ cycle[2] ] != ports_record[ cycle[2] ] || ports[ cycle[3] ] != ports_record[ cycle[3] ] )
                return false;
            
            if(ports.find( cycle[0] ) != ports.end() )
                ports_record.insert( make_pair(cycle[0], ports[cycle[0]]) );
            else
                return false; 
        }
        else if (cycle.size() == 3) 
        {
            //nor2
            if (available.find(cycle[0]) == available.end() ||
                used.find(cycle[1]) == used.end() ||
                used.find(cycle[2]) == used.end()) {
                return false;
            }
            available.erase(cycle[0]);
            used.insert(cycle[0]);

            // for(auto it = ports_record.begin(); it != ports_record.end(); it++)
            // {
            //     cout << it->first << " , " << it->second << endl;
            // }

            auto it = std::find( logic_one_cells.begin(), logic_one_cells.end(), cycle[0] );
            if( it == logic_one_cells.end()) 
            {
                return false;
            }   
            else
            {
                logic_one_cells.erase( it );
            } 
            // m_print( "after delete:" );
            // print_vector( logic_one_cells );

            unordered_map<int, string> ports = indexs_ports[flag + 1];
            if(ports.find( cycle[1] ) == ports.end() || ports.find( cycle[2] ) == ports.end())
                return false;
            else if( ports[ cycle[1] ] != ports_record[ cycle[1] ] )
            {
                ofs << "error port_name: " << ports[ cycle[1] ] << " ( at cycle " << i + 1 << ")" << endl;
                ofs << "correct port_name should be: " << ports_record[ cycle[1] ] << endl;
                return false;
            }
            else if( ports[ cycle[2] ] != ports_record[ cycle[2] ]  )
            {
                ofs << "error port_name: " << ports[ cycle[2] ] << " ( at cycle " << i + 1 << ")" << endl;
                ofs << "correct port_name should be: " << ports_record[ cycle[2] ] << endl;
                return false;
            }


            if(ports.find( cycle[0] ) != ports.end() )
                ports_record.insert( make_pair(cycle[0], ports[cycle[0]]) );
            else
                return false;    

        } 
        else if (cycle.size() == 2) 
        {   //inv1, buf
            if (available.find(cycle[0]) == available.end() ||
                used.find(cycle[1]) == used.end()) {
                return false;
            }
            available.erase(cycle[0]);
            used.insert(cycle[0]);

            auto it = std::find( logic_one_cells.begin(), logic_one_cells.end(), cycle[0] );
            if( it == logic_one_cells.end()) 
            {
                return false;
            }   
            else
            {
                logic_one_cells.erase( it );
            }
            // m_print( "after delete:" );
            // print_vector( logic_one_cells );

            unordered_map<int, string> ports = indexs_ports[flag + 1];
            if( ports.find(cycle[1]) == ports.end() )
                return false;
            else if( ports[ cycle[1] ] != ports_record[ cycle[1] ])
            {
                ofs << "error port_name: " << ports[ cycle[1] ] << " ( at cycle " << i + 1 << ")" << endl;
                ofs << "correct port_name should be: " << ports_record[ cycle[1] ] << endl;
                return false;
            }
                
            
            if(ports.find( cycle[0] ) != ports.end() )
                ports_record.insert( make_pair(cycle[0], ports[cycle[0]]) );
            else
                return false;
            // else
            // {
            //     if( ports[ cycle[1] ] == ports_record[ cycle[1] ] )
            //         return true;
            //     else    
            //         return false;
            // }

        }
        flag++;
    }
    return true;
}
