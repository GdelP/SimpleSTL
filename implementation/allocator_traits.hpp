#pragma once

namespace std {
  template<class Alloc> struct allocator_traits {
    typedef Alloc allocator_type;
    typedef Alloc::value_type value_type;
    typedef Alloc::pointer pointer; //TODO: Alloc::pointer may NOT be present!
    typedef Alloc::void_pointer void_pointer; //TODO: It may not exist!
    typedef Alloc::const_void_pointer const_void_pointer; //TODO: It may not exist!
    typedef Alloc::difference_type difference_type; //TODO: It may not exist!
    typedef Alloc::size_type size_type; //TODO: It may not exist!
    typedef Alloc::propagate_on_container_copy_assignment propagate_on_container_copy_assignment; //TODO: It may not exist!
    typedef Alloc::propagate_on_container_move_assignment propagate_on_container_move_assignment; //TODO: It may not exist!
    typedef Alloc::propagate_on_container_swap propagate_on_container_swap;

    //TODO: member alias templates
    static pointer allocate(Alloc& a, size_type n);
    static pointer allocate(Alloc& a, size_type n, const_void_pointer hint);
    static void deallocate(Alloc& a, pointer p, size_type n);
    template<class T, class...Args>
    static void construct(Alloc& a, T* p, Args&&... args);
    template<class T>
    static void destroy(Alloc& a, T* p);
    static size_type max_size(Alloc& a) noexcept;
  };
}
