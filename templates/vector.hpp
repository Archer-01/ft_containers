#pragma once

#include "iterator.hpp"
#include "stl_iterators.hpp"
#include "type_traits.hpp"
#include <memory>

namespace ft
{

	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::random_access_iterator<T> iterator;
			typedef ft::random_access_iterator<const T> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			/**
			 * @defgroup Constructors
			 *
			 * 	- Default constructor
			 * 	- Allocator constructor
			 * 	- Fill constructor
			 *	- Range constructor
			 *	- Copy constructor
			 *
			 */

			vector();

			explicit vector(const Allocator& alloc);

			explicit vector(
				size_type count,
				const T& value = T(),
				const Allocator& alloc = Allocator()
			);

			template <typename InputIterator>
			vector(
				InputIterator first,
				typename ft::enable_if<
					not ft::is_integral<InputIterator>::value,
					InputIterator
				>::type last,
				const Allocator& alloc = Allocator()
			);

			vector(const vector& other);

			/**
			 * @def Destructor
			 *
			 */

			~vector();

			/**
			 * @defgroup Assignment operator
			 *
			 */
			vector& operator=(const vector& other);

			/**
			 * @defgroup Assign methods
			 *
			 *	- Fill assign
			 *	- Range assign
			 *
			 */

			void assign(size_type count, const T& value);

			template <typename InputIterator>
			void assign(InputIterator first, InputIterator last);

			/**
			 * @def Get allocator method
			 *
			 */

			allocator_type get_allocator() const;

			/**
			 * @defgroup Elements access methods
			 *
			 *	- At method
			 *	- Subscript operator []
			 *	- Front method
			 *	- Back method
			 *	- Data method
			 *
			 */

			reference at(size_type pos);
			const_reference at(size_type pos) const;

			reference operator[](size_type pos);
			const_reference operator[](size_type pos) const;

			reference front();
			const_reference front() const;

			reference back();
			const_reference back() const;

			pointer data();
			const_pointer data() const;

			/**
			 * @defgroup Iterators methods
			 *
			 *	- Begin method
			 *	- End method
			 *	- Rbegin method
			 *	- Rend method
			 *
			 */

			iterator begin();
			const_iterator begin() const;

			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			reverse_iterator rend();
			const_reverse_iterator rend() const;

			/**
			 * @defgroup Capacity methods
			 *
			 *	- Empty method
			 *	- Size method
			 *	- Max size method
			 *	- Reserve method
			 *	- Capacity method
			 *
			 */

			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void reserve(size_type new_cap);
			size_type capacity() const;

			/**
			 * @defgroup Clear method
			 *
			 */

			void clear()
			{
				#pragma unroll
				for (size_type i = 0; i < m_Size; i++)
				{
					m_Allocator.destroy(&m_Data[i]);
				}
				m_Size = 0;
			}

			/**
			 * @brief push_back method
			 *
			 */

			void push_back(const T& value)
			{
				if (m_Size == m_Capacity)
				{
					if (m_Capacity == 0)
					{
						this->reserve(1);
					}
					else
					{
						this->reserve(m_Capacity * 2);
					}
				}
				m_Allocator.construct(&m_Data[m_Size], value);
				++m_Size;
			}

		private:
			pointer m_Data;
			size_type m_Size;
			size_type m_Capacity;
			allocator_type m_Allocator;
	};

}; // namespace ft

#include "vector_internals/vector_impl.hpp"
