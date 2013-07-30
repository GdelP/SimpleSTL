#pragma once
#include "vector.hpp"

namespace std {
  template<class T, class Allocator>
  vector<T,Allocator>::vector(const Allocator& alloc)
    : mBuffer(nullptr), mElements(0), mAllocated(0), mAllocator(alloc) {}
  vector(size_type count, const T& value=T(), const Allocator& alloc) 
    : mBuffer(alloc.allocate(count)), mElements(count), mAllocated(count), mAllocator(alloc) {
    `for(size_type i=0; i<mElements; ++i)
      mBuffer[i]=value;
  }

  template<class T, class Allocator>
  vector<T,Allocator>::vector(size_type count, const Allocator& alloc)
    : mBuffer(alloc.allocate(count)), mElements(count), mAllocated(count), mAllocator(alloc) {
    for(size_type i=0; i<mElements; ++i)
      mBuffer[i]=T();}
  template<class T, class Allocator>
  template<class InputIt>
  vector<T,Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc)    
    : mAllocator(alloc) {
    mElements = first-last;
    mBuffer = mAllocator.allocate(mElements);
    mAllocated = mElements;
    int i=0;
    for(InputIt it = first; it!=last; ++it, ++i) {
      mBuffer[i]=*it; }
  }

  template<class T, class Allocator>
  vector<T,Allocator>::vector(vector<T> const& other)
    : mAllocator(other.mAllocator), mElements(other.mElements), mBuffer(mAllocator.allocate(mElements)), mAllocated(mElements) {
    for(size_type i=0; i<mElements; ++i)
      mBuffer[i]=other.mBuffer[i];}//TODO: select_on_copy_construction
  }
    
  template<class T, class Allocator>
  vector<T,Allocator>::vector(vector<T> const& other, const Allocator& alloc)
    : mAllocator(alloc), mBuffer(mAllocator.allocate(other.mElements)), mElements(other.mElements), mAllocated(mElements) {
    for(size_type i=0; i<mElements; ++i)
      mBuffer[i]=other.mBuffer[i];}    
  }
    
  template<class T, class Allocator>
  vector<T,Allocator>::vector(vector<T> && other)
    : mAllocator(std::move(other.mAllocator)), mBuffer(other.mBuffer), mElements(other.mElements), mAllocated(other.mAllocated) {
    other.mBuffer = nullptr;//TODO: move semantics invalidates pointers?
    other.mElerments = other.mAllocated = 0;//TODO: move semantics invalidates pointers?
  }
    
  template<class T, class Allocator>
  vector<T,Allocator>::vector(vector<T> && other, const Allocator& alloc)
    : mAllocator(alloc), mBuffer(other.mBuffer), mElements(other.mElements), mAllocated(other.mAllocated) {
    other.mBuffer = nullptr;//TODO: move semantics invalidates pointers?
    other.mElerments = other.mAllocated = 0;//TODO: move semantics invalidates pointers?
  }
    
//  template<class T, class Allocator>
//  vector<T,Allocator>::vector(std::initializer_list<T> init, const Allocator& alloc = Allocator());

  template<class T, class Allocator>
  vector<T,Allocator>::~vector() {
    for(size_type i=0; i<mElements; ++i)
      mAllocator.destroy(mBuffer[i]);
    mAllocator.deallocate(mBuffer, mAllocated);
  }

  template<class T, class Allocator>
  vector<T,Allocator>& vector<T,Allocator>::operator=(vector const& other);

  template<class T, class Allocator>
  vector<T,Allocator>& vector<T,Allocator>::operator=(vector && other);

  template<class T, class Allocator>
  vector<T,Allocator>& vector<T,Allocator>::operator=(std::initializer_list<T> ilist);

  template<class T, class Allocator>
  void vector<T,Allocator>::assign( size_type count, const T& value );
  template<class T, class Allocator>
  template<class InputIT>
  void vector<T,Allocator>::assign(InputIt first, InputIt last);

  template<class T, class Allocator>
  void vector<T,Allocator>::assign(std::initializer_list<T> ilist);

  template<class T, class Allocator>
  allocator_type vector<T,Allocator>::get_allocator() const;
}
