#pragma once

#include "vector.hpp"

namespace ft
{

	template <typename T, typename Container = ft::vector<T> >
	class stack
	{
		public:
			/**
			 * @def Typedefs
			 *
			 */
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			/**
			 * @def Constructors
			 *
			 */
			explicit stack(const container_type &cont = container_type());
			stack(const stack &other);

			/**
			 * @def Destructor
			 *
			 */
			~stack();

			/**
			 * @def Assignment operator
			 *
			 */
			stack &operator=(const stack &other);

		protected:
			/**
			 * @def Attributes
			 *
			 */
			container_type c;
	};

}; // namespace ft

#include "stack_internals/stack_impl.hpp"
