// wejsciowkaszablony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <cassert>

#include <string>

#include <vector>

template<typename T, unsigned N>

struct Repeat 
{
    typedef T ValueType;
    T operator()(const T &val)
    {
        T accumulator = val;
        for (unsigned int i = 1; i < N; i++)
        {
            accumulator += val;
        }
        return accumulator;
    }
};


template <class Funct >

struct Mapper 
{
    std::vector<typename Funct::ValueType>& operator()(std::vector<typename Funct::ValueType> &val)
    {
        Funct funct;
        for (unsigned int i = 0; i < val.size(); i++)
        {
            typename Funct::ValueType temp = funct(val[i]);
            val[i] = temp;
        }
        return val;
    }
};


int main()

{


    Mapper< Repeat<int, 3> > map_int;

    Mapper< Repeat<std::string, 2> > map_str;


    std::vector<int> vec_int;

    for (int i = 1; i <= 5; ++i) { vec_int.push_back(i); };


    map_int(vec_int);


    // test dla int

    {

        static const int res[] = { 3,6,9,12,15 };

        std::vector<int> test(res, res + 5);
        //std::cout << "wynik:\n";
        //for (int i = 0; i < vec_int.size(); i++)
        //{
        //    std::cout << vec_int[i]<< std::endl;
        //}
        assert(test == vec_int);

    }



    std::vector<std::string> vec_str;

    vec_str.push_back("foo"); vec_str.push_back("bar");


    map_str(vec_str);


    // test dla str

    {

        static const char* res[] = { "foofoo", "barbar" };

        std::vector<std::string> test(res, res + 2);
        //for (int i = 0; i < vec_str.size(); i++)
        //{
        //    std::cout << vec_str[i] << std::endl;
        //}
        assert(test == vec_str);

    }



    return 0;

}