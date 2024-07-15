//
// Created by amardeep on 15/07/24.
//
#ifndef _TPF_TYPE_NAME_H
#define _TPF_TYPE_NAME_H

#include "iostream"

template<typename T>
constexpr bool is_lvalue_helper = std::is_lvalue_reference<T>::value;

template<typename T>
constexpr bool is_xvalue_helper = std::is_rvalue_reference<T>::value;

template<typename T>
constexpr bool is_prvalue_helper = !(is_lvalue_helper<T> || is_xvalue_helper<T>);

template<typename T>
constexpr bool is_rvalue_helper = is_xvalue_helper<T> || is_prvalue_helper<T>;

template<typename T>
constexpr bool is_glvalue_helper = is_xvalue_helper<T> || is_lvalue_helper<T>;

#define is_lvalue(type_instance) is_lvalue_helper<decltype((type_instance))>
#define is_xvalue(type_instance) is_xvalue_helper<decltype((type_instance))>
#define is_prvalue(type_instance)is_prvalue_helper<decltype((type_instance))>
#define is_rvalue(type_instance) is_rvalue_helper<decltype((type_instance))>
#define is_glvalue(type_instance)is_glvalue_helper<decltype((type_instance))>

#endif // end of _TPF_TYPE_NAME_H