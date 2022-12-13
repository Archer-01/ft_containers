#pragma once

#include "type_traits.hpp"

template <typename T>
struct ft::is_integral
{
	static const bool value = false;
};

template <>
struct ft::is_integral<bool>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<char>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<signed char>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<unsigned char>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<wchar_t>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<char16_t>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<short>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<unsigned short>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<int>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<unsigned int>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<long>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<unsigned long>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<long long>
{
	static const bool value = true;
};

template <>
struct ft::is_integral<unsigned long long>
{
	static const bool value = true;
};

template<typename T>
struct ft::is_integral<const T>
{
	static const bool value = ft::is_integral<T>::value;
};

template<typename T>
struct ft::is_integral<volatile T>
{
	static const bool value = ft::is_integral<T>::value;
};

template<typename T>
struct ft::is_integral<const volatile T>
{
	static const bool value = ft::is_integral<T>::value;
};
