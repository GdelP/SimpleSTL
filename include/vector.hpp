#pragma once
#include "allocator.hpp"

//TODO: VisualShitudio understands explicit?
namespace std {
  template< class T, class Allocator = std::allocator<T>> struct vector {
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef std::size_t size_type; //TODO: Define this. Read the standard
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef value_type const& const_reference
    typedef std::allocator_traits<Allocator>::pointer pointer; //TODO: Implement allocator_traits
    typedef std::allocator_traits<Allocator>::const_pointer const_pointer;
    typedef RandomAccessIterator iterator;//TODO: Simple pointer (T*) or something more comples with bounds checking on debug?
    typedef T const* const_iterator; //TODO: Something more complex on debug?
    typedef std::reverse_iterator<iterator> reverse_iterator; //TODO: Implement that
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator; //TODO: Implement that

    explicit vector(const Allocator& alloc = Allocator());
    vector(size_type count, const T& value=T(), const Allocator& alloc=Allocator());
    explicit vector(size_type count, const Allocator& alloc=Allocator());
    template<class InputIt>
    vector(InputIt first, InputIt last, const Allocator& alloc=Allocator());
    vector(vector<T> const& other);
    vector(vector<T> const& other, const Allocator& alloc);
    vector(vector<T> && other);
    vector(vector<T> && other, const Allocator& alloc);
    vector(std::initializer_list<T> init, const Allocator& alloc = Allocator());
  };
}
