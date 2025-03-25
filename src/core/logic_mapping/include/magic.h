#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <fstream>
#include <iostream>
#include "./myfunction.h"
#include <variant>
#include <map>
#include <unordered_set>
#include <iomanip>
#include <functional>

#include "mytime.h"

#ifndef MAGIC_H
#define MAGIC_H

#pragma once

extern std::string base_path; 

#define NULL_INDEX -1
#define NO_LEVEL	-1
#define NULL_DEGREE 0

using gate_idx = int;
using line_idx = int;
using node_level = int; 
using node_degree = int;

class Gate;
class CellInfo;
class CellsInfo;
class Magic;

struct Line
{
	void connect_as_input(gate_idx gate)
	{
		destination_gates.insert(gate);
	}
	gate_idx source = NULL_INDEX; 
	std::set<gate_idx> destination_gates; 

	bool is_input = false;
	bool is_output = false;
	bool is_wire = false;

	int id_line = NULL_INDEX;
	std::string name;
};

class Gate
{
public:
	Gate(line_idx output, std::vector<line_idx> &&inputs);                
//API
	const std::vector<line_idx> &get_inputs() const { return m_inputs; }
	std::vector<line_idx> &inputs() { return m_inputs; }

	const line_idx &get_output() const { return m_output; }
	line_idx &output() { return m_output; }

	const bool &get_inv1() const { return is_inv1; }
	bool &inv1() { return is_inv1; }

	const bool &get_nor2() const { return is_nor2; }
	bool &nor2() { return is_nor2; }

	const bool &get_buf() const { return is_buf; }
	bool &buf() { return is_buf; }

	const bool &get_zero() const { return is_zero; }
	bool &zero() { return is_zero; }

    const bool &get_one() const { return is_one; }
	bool &one() { return is_one; }

    const bool &get_nor3() const { return is_nor3; }
	bool &nor3() { return is_nor3; }

    const bool &get_nor4() const { return is_nor4; }
	bool &nor4() { return is_nor4; }

    const bool &get_nor5() const { return is_nor5; }
	bool &nor5() { return is_nor5; }

	const std::string &get_name() const { return m_name; }
	std::string  &name() { return m_name; }

	const int &get_id() const { return m_id; }
	int &id() { return m_id; }

	const node_level &get_level() const { return m_level; }
	node_level &level() { return m_level; }

	const node_degree &get_indegree() const { return m_in_degree; }
	node_degree &indegree() { return m_in_degree; }

    const node_degree &get_indegree_2() const { return m_in_degree_2; }
	node_degree &indegree_2() { return m_in_degree_2; }

	const node_degree &get_outdegree() const { return m_out_degree; }
	node_degree &outdegree() { return m_out_degree; }

    const node_degree &get_outdegree_SA() const { return m_out_degree_SA; }
	node_degree &outdegree_SA() { return m_out_degree_SA; }

    const node_degree &get_outdegree_2() const { return m_out_degree_2; }
	node_degree &outdegree_2() { return m_out_degree_2; }

    const node_degree &get_outdegree_3() const { return m_out_degree_3; }
	node_degree &outdegree_3() { return m_out_degree_3; }

    const node_degree &get_fanout() const { return m_fanout; }
	node_degree &fanout() { return m_fanout; }

    const node_degree &get_fanin() const { return m_fanin; }
	node_degree &fanin() { return m_fanin; }

	void set_out_degree(node_degree degree){ m_out_degree = degree; }
    void set_out_degree_SA(node_degree degree){ m_out_degree_SA = degree; }
    void set_fanout(node_degree degree){ m_fanout = degree; }
    void set_fanin(node_degree degree){ m_fanin = degree; }
    void set_out_degree_2(node_degree degree){ m_out_degree_2 = degree; }
    void set_out_degree_3(node_degree degree){ m_out_degree_3 = degree; }

	void set_in_degree(node_degree degree){ m_in_degree = degree; }
    void set_in_degree_2(node_degree degree){ m_in_degree_2 = degree; }

	const unsigned int &get_cell_usage() const { return m_cell_usage; }
	unsigned int &cell_usage() { return m_cell_usage; }
	void set_cell_usage(unsigned int cellusage) { m_cell_usage = cellusage; }

    const unsigned int &get_intermediate_storage() const { return m_intermediate_storage; }
	unsigned int &intermediate_storage() { return m_intermediate_storage; }
	void set_intermediate_storage(unsigned int intermediatestorage) { m_intermediate_storage = intermediatestorage; }

	const unsigned int &get_map() const { return m_map; }
	unsigned int &map() { return m_map; }
	void set_map(unsigned int map) { m_map = map; }

    const unsigned int &get_map_SA() const { return m_map_SA; }
	unsigned int &map_SA() { return m_map_SA; }
	void set_map_SA(unsigned int map) { m_map_SA = map; }

	const unsigned int &get_time() const { return m_time; }
	unsigned int &time() { return m_time; }
	void set_time(unsigned int  time) { m_time = time; }

    const unsigned int &get_time_SA() const { return m_time_SA; }
	unsigned int &time_SA() { return m_time_SA; }
	void set_time_SA(unsigned int  time) { m_time_SA = time; }

    const unsigned int &get_tree_size() const { return m_tree_size; }
    unsigned int &tree_size() { return m_tree_size; }
    void set_tree_size(unsigned int size) { m_tree_size = size; }

public:
    bool is_visited = false;
    int max_fanout_level = 0;
    int mini_fanout_level = 0;
    int m_reference_value = 1;//for collect_gates function
private:
	bool is_inv1 = false; 
	bool is_nor2 = false; 
	bool is_buf = false;
	bool is_zero = false;
    bool is_one = false;
    bool is_nor3 = false;
    bool is_nor4 = false;
    bool is_nor5 = false;
  	int m_id = NULL_INDEX;
  	std::string m_name;
	std::vector<line_idx> m_inputs;
	line_idx m_output = NULL_INDEX;
	node_level m_level = NO_LEVEL;
    //这里需要多个关于degree的成员变量是因为，很多函数调用并且修改了成员变量
    //为了防止出错，写了好几个
    //TODO 在处理之前保存初始值，处理之后恢复初始值
	node_degree m_in_degree = NULL_DEGREE;//for topo_sort ,修改后被复原
    node_degree m_in_degree_2 = NULL_DEGREE;//for cost_function，不被修改；     GreedyExecutionSequence()中，for循环中会被修改，目前在函数中已经被复原
	
    node_degree m_out_degree_2 = NULL_DEGREE;//for cost_function,修改后被复原
    node_degree m_out_degree_3 = NULL_DEGREE;//for EIC()

    node_degree m_out_degree = NULL_DEGREE;//for allocate，被修改
    node_degree m_out_degree_SA = NULL_DEGREE;
    node_degree m_fanout = NULL_DEGREE;// allocate过程中不改变
    node_degree m_fanin = NULL_DEGREE;// allocate过程中不改变
	//new add
	unsigned int m_cell_usage = 0;
	unsigned int m_map = 0;//cell_idx(gate mapped to)
    unsigned int m_map_SA = 0;//cell_idx(gate mapped to) for SA
	unsigned int m_time = 0;//time when allocate_cell
    unsigned int m_time_SA = 0;
    unsigned int m_tree_size = 0;

    unsigned int m_intermediate_storage = 0;//Number of RRAMs required for subtrees containing this vertex

};

class CellInfo {
public:
    // States declarations
    static const int Available = 1; // The cell was allocated and available again
    static const int Used = 2; // The cell is in use
    static const int Init = 3; // The cell is not in use, but need to initialized

    int state;
    CellInfo* next;
    CellInfo* prev;
    int cell_idx;
    gate_idx current_gate_num;

    CellInfo(int idx) 
    {
        state = Available;
        next = nullptr;
        prev = nullptr;
        cell_idx = idx;
        current_gate_num = NULL_INDEX;
    }

    int cell_index() { return cell_idx; }
    const int &get_cell_index() const { return cell_idx; };

    void set_next(CellInfo* node) { next = node; }
    void set_prev(CellInfo* node) { prev = node; }

    CellInfo* get_next() { return next; }
    CellInfo* get_prev() { return prev; }

    void set_cur_gate_num(gate_idx gate_num) { current_gate_num = gate_num; }
    gate_idx get_cur_gate_num() { return current_gate_num; }
};

class CellsInfo {
public:
    CellInfo* used_head = nullptr;
    CellInfo* used_tail = nullptr;
    CellInfo* init_head = nullptr;
    CellInfo* init_tail = nullptr;
    CellInfo* available_head = nullptr;
    CellInfo* available_tail = nullptr;
    std::vector<CellInfo> cells;
    std::vector<std::pair<gate_idx, int>> init_list;//gate_idx cell_idx

    CellsInfo(int num)
    {
        for(int i = 0; i < num; i++)
        {
            cells.push_back(CellInfo(i));//construct N cells
        }
    }

    void traversal_list(CellInfo * pointer)//traversal list
    {
        CellInfo * current = pointer;
        while(current != nullptr)
        {
            std::cout << "cell index: " << current->cell_idx << std::endl;
            std::cout << "gate index: " << current->current_gate_num << std::endl;
            current = current->get_next();
        }
    }

    int get_used_cells_count(CellInfo * pointer)//number of used cells
    {
        int count = 0;
        CellInfo * current = pointer;
        while(current != nullptr)
        {
            count ++;
            current = current ->get_next();
        }
        return count;
    }

    // Available list functions
    int get_first_available() 
    {
        if (available_head == nullptr) 
        {
            return -1; // -1 means no available cell
        } 
        else 
        {
            return available_head->cell_index();
			//return cells[available_head->cell_index()].cell_idx;
        }
    }

    void insert_available(int cell_idx) 
    {
        if (available_head == nullptr) 
        {
            available_head = &cells[cell_idx];
            available_tail = &cells[cell_idx];
        } 
        else 
        {
            cells[available_head->cell_idx].set_prev(&cells[cell_idx]);
            cells[cell_idx].set_next(available_head);
            available_head = &cells[cell_idx];
        }
    }

    void insert_available_positive_order(int cell_idx)
    {
        if (available_head == nullptr) 
        {
            available_head = &cells[cell_idx];
            available_tail = &cells[cell_idx];
        }
        else
        {
            cells[available_tail->cell_idx].set_next(&cells[cell_idx]);
            cells[cell_idx].set_prev(available_tail);
            available_tail = &cells[cell_idx];
        }
    }

    void delete_first_available() 
    {
        if (available_head == available_tail) 
        {
            cells[available_head->cell_idx].set_next(nullptr);
            cells[available_head->cell_idx].set_prev(nullptr);
            available_head = available_tail = nullptr;
        } 
        else 
        {
            CellInfo* next_available_cell = cells[available_head->cell_idx].get_next();
            cells[available_head->cell_idx].set_next(nullptr);
            available_head = next_available_cell;
            next_available_cell->set_prev(nullptr);
        }
    }

    void concatenate_init_to_available_list() 
    {
        available_head = init_head;
        available_tail = init_tail;
        cells[available_tail->cell_idx].set_next(nullptr);
        cells[available_head->cell_idx].set_prev(nullptr);
        init_head = nullptr;
		init_tail = nullptr;
    }

    // Init list functions
    bool init_is_not_empty() { return init_head != nullptr; }

    void clean_init_list() 
    {
        init_tail = nullptr;
        init_head = nullptr;
        init_list.clear();
    }

    void insert_init(int cell_idx) 
    {
        if (init_head == nullptr) 
        {
            init_head = &cells[cell_idx];
            init_tail = &cells[cell_idx];
        } 
        else 
        {
            cells[init_head->cell_idx].set_prev(&cells[cell_idx]);
            cells[cell_idx].set_next(init_head);
            init_head = &cells[cell_idx];
        }
        int cur_gate = cells[cell_idx].get_cur_gate_num();
        init_list.push_back(std::make_pair(cur_gate, cell_idx));
    }

    void insert_init_positive_order(int cell_idx) 
    {
        if (init_head == nullptr) 
        {
            init_head = &cells[cell_idx];
            init_tail = &cells[cell_idx];
        }
        else
        {
            cells[init_tail->cell_idx].set_next(&cells[cell_idx]);
            cells[cell_idx].set_prev( init_tail );
            init_tail = &cells[cell_idx];
        }
        int cur_gate = cells[cell_idx].get_cur_gate_num();
        init_list.push_back(std::make_pair(cur_gate, cell_idx));
    }

    // Used list functions
    void insert_used(int cell_idx, gate_idx gate_num) 
    {//新插入元素放置在前
        if (used_head == nullptr) {
            used_head = &cells[cell_idx];
            used_tail = &cells[cell_idx];
        } 
        else 
        {
            cells[used_head->cell_idx].set_prev(&cells[cell_idx]);
            cells[cell_idx].set_next(used_head);
            used_head = &cells[cell_idx];
        }
        cells[cell_idx].set_cur_gate_num(gate_num);
    }

    //The new inserted element is placed at the back
    void insert_used_positive_order(int cell_idx, gate_idx gate_num)
    {
        if (used_head == nullptr) {
            used_head = &cells[cell_idx];
            used_tail = &cells[cell_idx];
        } 
        else 
        {
            cells[used_tail->cell_idx].set_next(&cells[cell_idx]);
            cells[cell_idx].set_prev(used_tail);
            used_tail = &cells[cell_idx];
        }
        cells[cell_idx].set_cur_gate_num(gate_num);
    }

    void delete_used(int cell_idx) 
    {
        CellInfo* next_cell = cells[cell_idx].get_next();
        CellInfo* prev_cell = cells[cell_idx].get_prev();

        if (used_head == used_tail && used_tail == &cells[cell_idx]) 
        {
            cells[cell_idx].set_next(nullptr);
            cells[cell_idx].set_prev(nullptr);
            used_tail = used_head = nullptr;
        } 
        else if (&cells[cell_idx] == used_head) {
            CellInfo* next_head = cells[cell_idx].get_next();
            cells[cell_idx].set_next(nullptr);
            next_head->set_prev(nullptr);
            used_head = next_head;
        } 
        else if (&cells[cell_idx] == used_tail) {
            CellInfo* next_tail = cells[cell_idx].get_prev();
            cells[cell_idx].set_prev(nullptr);
            next_tail->set_next(nullptr);
            used_tail = next_tail;
        } 
        else {
            next_cell = cells[cell_idx].get_next();
            prev_cell = cells[cell_idx].get_prev();
            cells[cell_idx].set_next(nullptr);
            cells[cell_idx].set_prev(nullptr);
            next_cell->set_prev(prev_cell);
            prev_cell->set_next(next_cell);
        }
    }
};

class Magic
{
public:
	Magic()
	{
		//TO DO:max_gates_num
		//TO DO:generate_json, print_mapping, print_warnings, end_of_line_output
	}

    Magic(std::string benchmark_name):m_benchmark_name(benchmark_name), cellsinfoSA(nullptr) {}

    Magic(std::string benchmark_name, int row_size):m_benchmark_name(benchmark_name), m_row_size(row_size), cellsinfoSA(nullptr) {}//Parameterized constructor

    ~Magic()
    {
        delete cellsinfoSA;
    }

    void RL_API();//与run_SA()不可以同时使用，因为都调用了mapping_for_SA函数，重复调用会多次修改变同一变量
    void show_simplest_mapping_info( const std::pair<int, std::vector<gate_idx>> &cost_roots_pair, bool old_version = false);
    void run_simplest();
    void run_simpler();
    void design_space_exploration();
    void prepare( bool show_stats_type );

    void tt();//Test the correctness of the cost function of the semi-adder (correct)
    void test_topo_sort();//test cost_function for topo_sort
    void test_enum_exec_seq();//test cost_function for all_topo_sort
    void test_GreedyExecutionSequence( const std::string &file_path );//贪心选择执行顺序 并输出到文本
    void test_result_of_greedy(const int &index, const std::string &file_path);//解析生成的顺序文本，并做映射

    void show_stats( bool for_RL = false );
    void advance_show_stats();
    void eda_competition_show( const std::map<int, std::variant<gate_idx, std::vector<gate_idx>>> &m_micro_operation, const int &row_size, const std::string &file_path, std::function<int(const Gate&)> get_map_idx_strategy, bool generate_png = false );
    void generate_html_table( const std::vector<std::string> &operations_matrix, const int &Time, std::ofstream &ofs, int index = -1 );
    
	line_idx add_input(const std::string &name);
	line_idx add_output(const std::string &name);
	line_idx add_wire(const std::string &name);
	gate_idx add_gate(const std::string& gate_name, const std::vector<std::string> &input_names, const std::string &output_name, bool is_inv1, bool in_nor2, bool is_buf, bool is_zero, bool is_one, int is_multi_nor);

	const line_idx get_line(const std::string &name) const;
	line_idx line(const std::string &name);

	const Gate& get_gate(const gate_idx& idx) const { return m_gates[idx]; }
	Gate& gate(const gate_idx& idx) { return m_gates[idx]; }

	const Line& get_line(const line_idx &idx) const { return m_lines[idx]; }
	Line& line(const line_idx &idx) { return m_lines[idx]; }

	const std::vector<Line> &get_lines() const { return m_lines; }
	std::vector<Line> &lines() { return m_lines; }

	const std::vector<Gate> &get_gates() const { return m_gates; }
	std::vector<Gate> &gates() { return m_gates; }

	const std::vector<line_idx> &get_inputs() const { return m_inputs; }
	std::vector<line_idx> &inputs() { return m_inputs; }
	
	const std::vector<line_idx> &get_outputs() const { return m_outputs; }
	std::vector<line_idx> &outputs() { return m_outputs; }

	const std::vector<gate_idx> &get_wires() const { return m_wires; };
	std::vector<gate_idx> &wires() { return m_wires; }

	const std::vector<gate_idx> &get_inv1s() const { return m_inv1s; };
	std::vector<gate_idx> &inv1s() { return m_inv1s; }

	const std::vector<gate_idx> &get_nor2s() const { return m_nor2s; };
	std::vector<gate_idx> &nor2s() { return m_nor2s; }

	const std::vector<gate_idx> &get_bufs() const { return m_bufs; };
	std::vector<gate_idx> &bufs() { return m_bufs; }

	const std::vector<gate_idx> &get_zeros() const { return m_zeros; };
	std::vector<gate_idx> &zeros() { return m_zeros; }

    const std::vector<gate_idx> &get_ones() const { return m_ones; };
	std::vector<gate_idx> &ones() { return m_ones; }

    const std::vector<gate_idx> &get_nor3s() const { return m_nor3s; };
	std::vector<gate_idx> &nor3s() { return m_nor3s; }

    const std::vector<gate_idx> &get_nor4s() const { return m_nor4s; };
	std::vector<gate_idx> &nor4s() { return m_nor4s; }

    const std::vector<gate_idx> &get_nor5s() const { return m_nor5s; };
	std::vector<gate_idx> &nor5s() { return m_nor5s; }

	const std::vector<std::vector<gate_idx>> &get_m_node_level() const { return m_node_level; }
	std::vector<std::vector<gate_idx>> &node_level() { return m_node_level; }

	const int &get_mld() const { return max_logic_depth; }

    const float &get_fo_lev_ave() const { return fanout_level_ave; }
    const float &get_fo_node_num_ave() const { return fanout_node_num_ave; }
    const int &get_fo_node_num_max() const { return max_fanout_node_num; }
    const float &get_fanin_node_num_ave() const { return fanin_node_num_ave; }

    void set_fo_lev_ave( const float &lev_ave) { fanout_level_ave = lev_ave; }
    void set_fo_node_num_ave( const float &node_num_ave) { fanout_node_num_ave = node_num_ave; }
    void set_fo_node_num_max( const int &node_num_max) { max_fanout_node_num = node_num_max; }
    void set_fanin_node_num_ave( const float &node_num_ave) { fanin_node_num_ave = node_num_ave; }

    const int &get_time() const { return m_time; }
	int &time() { return m_time; }

	void match_logic_depth();

	std::vector<gate_idx> topo_sort();//topo_sort the DAG
    std::vector<std::vector<gate_idx>> enum_topo_sort();
    void enum_topo_sort_helper(std::vector<std::vector<gate_idx>> &all_orders, std::vector<gate_idx> &cur_order, std::unordered_set<gate_idx> &visited);
    
    std::pair<int, int> cost_function(const std::vector<gate_idx> &topo);//compute intermidiate storage,恢复m_outdegree_2
    int cost_function_RL(const std::vector<gate_idx> &topo);//return cost  RL-training
    int compute_EIC(const gate_idx& gate);//compute EIC
    std::vector<gate_idx> GreedyExecutionSequence();
    std::vector<gate_idx> parse_from_result(std::istream &is, int index);//从result文件解析得到std::vector<gate_idx> index： benchmark的索引 从1开始
    bool VecGateAPI(const std::vector<gate_idx> &gates);//接受gate_idx，做mapping
    void getFanoutLevelforGates();
    void getFanoutNodeNumforGates();

    std::vector<gate_idx> RootsToGates(const std::vector<gate_idx> &roots);
    void ToGates(const gate_idx &gate_index, std::vector<gate_idx> &gates, std::unordered_set<gate_idx> &visited);
    void RandomExchange(std::vector<gate_idx> & roots);
    std::pair<int, std::vector<gate_idx>> SimulatedAnnealing( bool show_progress = false );
    void mapping_for_SA( const std::vector<gate_idx> &roots_order );
    void allocate_row_for_SA( const gate_idx &gate_index );
    int allocate_cell_for_SA(const gate_idx &gate_index);

    void compute_gate_outdegree();//compute outdegree
	void compute_gate_indegree();//compute indegree
	void match_cell_usage();//compute_cell_uasge(stranhler number)
	bool perform_allocate_row();//allocate row
	void initialize_cells();//allocate cells to used(PI) and available
    void initialize_cells_for_SA( const int &cost );//cost means number of RRAM needed by a given sequence by cost_function*
    void compute_roots();//initial std::vector<gate_idx> m_roots
    void set_root_tree_size();//set the tree size of the root tree
    void print_cellsinfo();
    void print_cellsinfo_SA();
    void generate_micro_operation();
    void save_generated_micro_operation( const std::string &file_path = "" );
    void save_generated_micro_operation_SA( const std::string &file_path = "" );
    void save_generated_micro_operation_SA_veriSIMPLER( const std::string &file_path = "" );
    void generate_stats( bool old_version = false );//without micro_operation
    std::map<int, std::variant<gate_idx, std::vector<gate_idx>>> m_micro_operation;// data to generate micro_operation
    //store m_time -> gate_index or std::vector<gate_idx>(Initialization)
    std::map<int, std::variant<gate_idx, std::vector<gate_idx>>> m_micro_operation_SA;
    void write_dot( const std::string &node_lable, const std::string &file_path = "", bool generate_png = false, bool show_graph = false );
    void write_dot_for_extracted_tree(const std::vector<std::vector<gate_idx>> &extract_tree);
    std::vector<std::vector<gate_idx>> extract_tree(const std::vector<gate_idx> &roots);//store gate_index of extracted trees
    void dfs(const gate_idx &gate, std::vector<gate_idx> &res);//DFS the root to get the tree
    void dfs_2(const gate_idx &gate, std::vector<gate_idx> &res, std::unordered_set<gate_idx> &visited);//DFS the root to get the tree without visited flag(for get_trees_for_every_roots)
    std::vector<gate_idx> depth_first_search(const gate_idx &gate, std::vector<gate_idx> &result, std::unordered_set<gate_idx> &visited);
    std::vector<std::vector<gate_idx>> get_trees_for_every_roots(const std::vector<gate_idx> &roots);
    std::vector<gate_idx> m_roots;//store the gate index of the roots(gates connected to PO)
    std::vector<gate_idx> m_traversal_roots;//store the order of roots when perform_allocate_row()
    std::vector<gate_idx> m_traversal_gates;//store the gate index  during the mapping "new add"
    void compute_intermediate_storage( bool show_sequence_and_cost = false );
    
public:
    int PI_size_without_zero_one = 0;//解析之后的DAG中不包含zero one的PI的数量
    void count_real_PI_num(){
        assert(m_inputs.size() != 0);
        int size = m_inputs.size();
        if( m_zeros.size() != 0){
		size --;}
	    if( m_ones.size() != 0){
		size --;}
        PI_size_without_zero_one = size;
    }
    std::vector<gate_idx> mapping_gates;//存储mapping的gates的序列
    std::vector<gate_idx> mapping_gates_SA;
	void print_graph();
	void print_container(bool lines, bool gates, bool inputs, bool outputs, bool wires, bool inv1s, bool nor2s);
	void save_print_container(bool lines, bool gates, bool inputs, bool outputs, bool wires, bool inv1s, bool nor2s, std::string file_path );
	
    void get_nodes_for_fanout_count();//nodes corresponding to fanout count
    std::vector<std::vector<gate_idx>> m_node_fanout;
    int max_fanout_number = -1;

    std::string m_sort_roots = "NO";//need API value:"NO" "DESCEND" "ASCEND" "RANDOM" "Tree_Size"
    int m_row_size;//row size,need API to set the value
    std::string m_benchmark_name{};
    std::pair<int, std::vector<gate_idx>> costRootsPair;
    CellsInfo cellsinfo{m_row_size};//Initialize n cell object
    CellsInfo* cellsinfoSA;//for SA
    int allocate_cell(const gate_idx &gate_index);//暂时放在public 用于测试
private:
	line_idx ensure_line(const std::string &name);
  	int compute_node_depth(const gate_idx g_id);//
	unsigned int compute_cell_usage(const gate_idx &g_id);//
	bool allocate_row(const gate_idx &gate_index);//
   std::vector<gate_idx> collect_gates(const gate_idx &gate_index, std::unordered_set<gate_idx> &visited);//Obtain the subtree with the current gate as its root
    bool allocate_row_by_intermediate_storage(const gate_idx &gate_index);
	// unsigned int allocate_cell(const gate_idx &gate_index);//new to realize the func
 

private:
	std::vector<Line> m_lines;
	std::vector<line_idx> m_inputs;
	std::vector<line_idx> m_outputs;
	std::vector<line_idx> m_wires;
	//size: lines = inputs + outputs + wires,index 递增
	
	std::vector<Gate> m_gates;
	std::vector<gate_idx> m_inv1s;
	std::vector<gate_idx> m_nor2s;
	std::vector<gate_idx> m_bufs;
	std::vector<gate_idx> m_zeros;
    std::vector<gate_idx> m_ones;
    std::vector<gate_idx> m_nor3s;
    std::vector<gate_idx> m_nor4s;
    std::vector<gate_idx> m_nor5s;
	//size: gates = inv1s + nor2s index和netlist中的顺序相同

	std::vector<std::vector<gate_idx>> m_node_level;
  	int max_logic_depth = -1; 

    //for func: extract_netlist_features in RL
    float fanout_node_num_ave = -1;
    float fanout_level_ave = -1;
    int max_fanout_node_num = -1;
    float fanin_node_num_ave = -1;

	std::unordered_map<std::string, line_idx> m_name_to_line_idx;

	int m_time =  0;//record cycle
    int m_reuse_cycles = 0;//record reuse cycle
    int m_time_SA =  0;
    int m_reuse_cycles_SA = 0;
};

#endif