#pragma once

#include "stack.hpp"
#include <cassert>
#include <stack>

template <
	template <typename T, typename Container = ft::vector<T> > class Stack
>
void test_stack()
{
	{
		Stack<int> stack;

		assert(stack.empty());
		assert(stack.size() == 0);

		{
			Stack<int> stack2 = stack;
			Stack<int> stack3;

			stack3 = stack;
		}
	}
	{
		Stack<int> stack;

		#pragma unroll 10
		for (int i = 0; i < 10; ++i)
		{
			stack.push(i);
		}

		assert(stack.size() == 10);
		assert(stack.top() == 9);

		stack.pop();

		assert(stack.size() == 9);
		assert(stack.top() == 8);

		{
			Stack<int> stack2 = stack;

			assert(stack == stack2);
		}
	}
}
