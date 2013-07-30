#pragma once
namespace std {
  //SFINAE! iMPEMENT TYPE_TRAITS FIRST
  template<class T>
  struct HasMethod {
    typedef char Yes;
    struct  No { char c[2];};
    template<typename U, U>
    struct Check;
    template<typename C>
    static Yes Test(Check<void (C::*)(), &C::method>);
    template<typename C>
    static No Test(...);

    static const bool value = (sizeof(Test<T>(0))==sizeof(Yes));
  };
  template<bool Cond, class value_type>
  struct enable_if {};
  template<class value_type>
  struct enable_if<true> {
    typedef value_type type; };
}
