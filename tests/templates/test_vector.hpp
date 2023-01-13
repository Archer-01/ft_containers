#pragma once

#include "vector.hpp"
#include <cassert>
#include <memory>

template <
	template <typename T, typename Allocator = std::allocator<T> > class Vector
>
void test_vector()
{
	{
		int arr[] = {1, 2, 3, 4, 5};

		Vector<int> vec(42, 42);
		Vector<int> vec2(vec);
		Vector<int> vec3(&arr[0], &arr[5]);

		assert(vec == vec2);
		assert(vec.capacity() == 42);
		assert(vec3[3] == 4);
		assert(vec3.size() == 5);
	}
	{
		Vector<int> vec;

		vec.reserve(42);
		assert(vec.empty() == true);
		assert(vec.size() == 0);
		assert(vec.capacity() == 42);

		for (int i = 0; i < 21; ++i)
		{
			vec.push_back(i);
		}

		assert(vec.size() == 21);
		assert(vec.capacity() == 42);
	}
	{
		Vector<int> vec;

		vec.reserve(42);
		assert(vec.empty() == true);
		assert(vec.size() == 0);
		assert(vec.capacity() == 42);

		for (int i = 0; i < 21; ++i)
		{
			vec.push_back(i);
		}

		assert(vec.size() == 21);
		assert(vec.capacity() == 42);

		vec.resize(42);
		assert(vec.size() == 42);
		assert(vec.capacity() == 42);

		vec.resize(21);
		assert(vec.size() == 21);
		assert(vec.capacity() == 42);

		vec.resize(0);
		assert(vec.size() == 0);
		assert(vec.capacity() == 42);
	}
	{
		Vector<int> vec;

		vec.reserve(42);

		for (int i = 0; i < 21; ++i)
		{
			vec.push_back(i);
		}

		assert(vec.size() == 21);
		assert(vec.capacity() == 42);

		vec.resize(42, 42);
		assert(vec.size() == 42);
		assert(vec.capacity() == 42);

		vec.resize(21, 42);
		assert(vec.size() == 21);
		assert(vec.capacity() == 42);

		vec.resize(0, 42);
		assert(vec.size() == 0);
		assert(vec.capacity() == 42);
	}
	{
		Vector<int> vec;

		vec.reserve(42);

		for (int i = 0; i < 21; ++i)
		{
			vec.push_back(i);
		}

		assert(vec.size() == 21);
		assert(vec.capacity() == 42);

		vec.resize(42, 42);
		assert(vec.size() == 42);
		assert(vec.capacity() == 42);

		vec.resize(21, 42);
		assert(vec.size() == 21);
		assert(vec.capacity() == 42);

		vec.resize(0, 42);
		assert(vec.size() == 0);
		assert(vec.capacity() == 42);
	}
	{
		int arr[] = {42, 38, 65, 97, 76, 13, 27};
		Vector<int> vec(&arr[0], &arr[7]);
		int i;

		typename Vector<int>::const_iterator iter;

		i = 0;
		for (iter = vec.begin(); iter != vec.end(); ++iter)
		{
			assert(*iter == arr[i]);
			++i;
		}

		typename Vector<int>::const_reverse_iterator rev_iter;

		i = 6;
		for (rev_iter = vec.rbegin(); rev_iter != vec.rend(); ++rev_iter)
		{
			assert(*rev_iter == arr[i]);
			--i;
		}

		assert(vec.front() == 42);
		assert(vec.back() == 27);
	}
}
