#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>
#include <pwd.h>
#include <unistd.h>

static std::vector<std::string> m_split(const std::string& input, const std::string& pred)
{
  std::vector<std::string> result;
  std::string temp{""};
  unsigned count1 = input.size();
  unsigned count2 = pred.size();
  unsigned j;
  for (size_t i = 0; i < count1; i++)
  {
    for(j = 0; j < count2; j++)
    {
      if(input[i] == pred[j])
      {
        break;
      }
    }
    //if input[i] != pred中的任何一个 该字符加到temp上
    if(j == count2)
      temp += input[i];
    else
    {
      if(!temp.empty())
      {
        result.push_back(temp);
        temp.clear();
      }
    }
  }
  if(!temp.empty())
  {
    result.push_back(temp);
    temp.clear();
  }
  return result;
}

static void delete_space(std::string& str)
{
  for(int i = str.size(); i > -1; i--)
  {
    if(str[i] == ' ' || str[i] == '\t')
    {
      str.erase(str.begin() + i);
    }
  }
}

static void seg_fault(const std::string& name, int size, int idx)
{
  std::cout << name << "  " << size << " : " << idx << std::endl; 
}

static void delete_vector_space(std::vector<std::string> &vec)
{
  vec.erase(std ::remove(vec.begin(), vec.end(), ""), vec.end());
}

template<typename T>
void print_function(const std::vector<T> &vec)//print vector<T>
{
  for(const auto &v: vec)
  {
    std::cout << v << ", ";
  }
  std::cout << std::endl;
}

template<typename T>
void print_function_2(const std::vector<std::vector<T>> &vec)//print vector<vector<T>>
{
  for(const auto &vs: vec)
  {
    for(const auto & v : vs)
    {
      std::cout << v << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

template<typename T>
void m_print(T t) {
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void m_print(T t, Args... args) {
    std::cout << t << " ";
    m_print(args...);
}

template<typename T>
void m_Print(T t) {
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void m_Print(T t, Args... args) {
    std::cout << t;
    m_Print(args...);
}

static std::string get_benchmark_name(const std::string &name)
{
    std::vector<std::string> benchmark_name = m_split(name, "/.");
    std::string mbenchmark_name = benchmark_name[benchmark_name.size() - 2];
    return mbenchmark_name;
}

static std::string get_home_dir()
{
  const char *home_dir;
  if( (home_dir = getenv("HOME")) == NULL )
  {
    home_dir = getpwuid( getuid() ) -> pw_dir;
  }
  return std::string( home_dir );
}

static void show_tool_info( bool is_show = false )
{
    std::cout<<"/-------------------------------------------------------------------------------\\"<<std::endl;
    std::cout<<"|   Logic Synthesis and Verification Tool for MAGIC based In-memory Computing   |"<<std::endl;
    std::cout<<"|                                                                               |"<<std::endl;
    std::cout<<"|   Copyright (c) 2022-2025 Ningbo University, China.                           |"<<std::endl;
    std::cout<<"|                                                                               |"<<std::endl;
    std::cout<<"|   You can find it at: https://gitee.com/panjiaxiang7/magic.git                |"<<std::endl;
    std::cout<<"|   Contact us at panjiaxiang7@163.com                                          |"<<std::endl;
    std::cout<<"\\-------------------------------------------------------------------------------/"<<std::endl;
    std::cout<<std::endl;
}

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

static void printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\rmapping %3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

static bool compare_input_line_index(const int &index1, const int &index2)
{ 
  return index1 < index2;
}

static std::string remove_quotes(std::string s) {
    s.erase(std::remove(s.begin(), s.end(), '\"' ), s.end());
    return s;
}

static bool is_executable_available(const std::string& cmd) {
  std::string command = "which " + cmd + " > /dev/null 2>&1";
  int result = std::system(command.c_str());
  return (result == 0);
}

#endif