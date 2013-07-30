#pragma once
#include "allocator_traits.hpp"

namespace std {
  
  template<class Alloc> 
  pointer allocator_traits<Alloc>::allocate(Alloc& a, size_type n) {
    return a.allocate(n);
  }
  template<class Alloc> 
  pointer allocator_traits<Alloc>::allocate(Alloc& a, size_type n, const_void_pointer hint) {
    return a.allocate(n,hint); //TODO: it may not be implemented!
  }

  template<class Alloc> 
  void allocator_traits<Alloc>::deallocate(Alloc& a, pointer p, size_type n) {
    return a.deallocate(p,n);
  }
  template<class Alloc> 
  template<class T, class...Args>
  void allocator_traits<Alloc>::construct(Alloc& a, T* p, Args&&... args) {
    a.construct(p, std::forward<Args>(args)...); //TODO: It may not be implemented!
  }
  template<class Alloc> 
  template<class T>
  void allocator_traits<Alloc>::destroy(Alloc& a, T* p) {
    a.destroy(p); //TODO: It may not be implemented
  }
  template<class Alloc> 
  size_type allocator_traits<Alloc>::max_size(Alloc& a) noexcept {
    return a.max_size(); //TODO: It may not be implemented!
  }




}
