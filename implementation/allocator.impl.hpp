#include "allocator.hpp"

namespace std {
  //Standard allocator has no state, so constructors/destructors are trivial
  template<class _Stored> 
  allocator<_Stored>::allocator() {}
  template<class _Stored> 
  allocator<_Stored>::allocator(const allocator<T>& other) {}

  template<class _Stored> 
  template<class U>
  allocator<_Stored>::allocator(const allocator<U>& other) {}

  namespace {
    struct DummyStruct { int NonEmpty; };
    //    template<typename value_type>
    //    struct InheritsFrom : value_type {
    //      value_type operator&() const {
    //	return this; }
    //    }
  }
  template<class _Stored> 
  allocator<_Stored>::~allocator() {}
  template<class _Stored> 
  pointer allocator<_Stored>::address(reference x) const noexcept {
    return reinterpret_cast<pointer>(&reinterpret_cast<::DummyStruct const &>(x));//Another option would be to inherit from reference
  }
  template<class _Stored> 
  const_pointer allocator<_Stored>::address(const_reference x) const noexcept{
    return reinterpret_cast<pointer>(&reinterpret_cast<::DummyStruct const &>(x));//Another option would be to inherit from reference
    }
  template<class _Stored>
  pointer allocator<_Stored>::allocate(size_type n, std::allocator<void>::const_pointer hint=0) {
    pointer ret = ::operator new(n*sizeof(value_type));
    if(ret==nullptr)
      throw std::bad_alloc();
    return ret;
  }
  template<class _Stored>
  void allocator<_Stored>::deallocate(pointer p, size_type n) {
    if(n>1)
      ::operator delete[](p);
    else
      ::operator delete(p);
  }

  template<class _Stored>
  size_type allocator<_Stored>::max_size() const noexcept {
    //TODO: Document myself about lower level memory acquisition
    return std::numerics_limits<size_type>::max();
  }

  template<class _Stored>
  void allocator<_Stored>::construct(pointer p, const_reference val) {
    new((void*)p) T(val); //Warning, may use copy constructor!
  }n
  template<class _Stored>
  template<class U, clas... Args>
  void allocator<_Stored>::construct(U* p, Args&&... args) {
    new ((void*)p) U(std::forward<Args>(args)...);
  }

  template<class _Stored>
  void allocator<_Stored>::destroy(pointer p) {
    p->~_Stored();
  }
  template<class _Stored>
  template<class U>
  void allocator<_Stored>::destroy(U* p) {
    p->~U();
  }
  };
}
