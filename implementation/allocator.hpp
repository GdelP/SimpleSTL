#pragma once
#define noexcept //Visual Shitudio do not understand it
namespace std {
  template<class _Stored> struct allocator {
    typedef _Stored Stored;
    typedef Stored value_type;
    typedef Stored* pointer;
    typedef Stored const* const_pointer;
    typedef Stored& reference;
    typedef Stored const& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    //    typedef std::true_type propagate_on_container_move_assignment; //I don't understand that one
    //    typedef rebind  //I don't understand that one

    allocator();
    allocator(const allocator<T>& other);
    template<class U>
    allocator(const allocator<U>& other);
    ~allocator();
    pointer address(reference x) const noexcept;
    const_pointer address(const_reference x) const noexcept;
    /// We will ignore hint
    pointer allocate(size_type n, std::allocator<void>::const_pointer hint=0);
    void deallocate(pointer p, size_type n);
    size_type max_size() const noexcept;
    void construct(pointer p, const_reference val);
    template<class U, clas... Args>
    void construct(U* p, Args&&... args);

    void destroy(pointer p);
    template<class U>
    void destroy(U* p);
  };
  template<class T1, class T2>
  bool operator==(allocator<T1> const& other, allocator<T2> const& other) noexcept { return true; }
  bool operator!=(allocator<T1> const& other, allocator<T2> const& other) noexcept { return false; }
}
