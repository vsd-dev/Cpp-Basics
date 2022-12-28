// #include <boost/python/numpy.hpp>
#include <iostream>
#include <vector>
// using namespace std;
// namespace bpy = boost::python;
// namespace np = boost::python::numpy;
// int main()
// {
//     // Py_Initialize();
//     // np::initialize();
//     cout << "Hello" << endl;

//     bpy::tuple shape = bpy::make_tuple(3, 3);
//     np::dtype dtype = np::dtype::get_builtin<float>();
//     np::ndarray a = np::zeros(shape, dtype);
//     vector<int> my_arr = {1, 4, 5, 9};
//     // np::
//     return 0;
// }


// #include <vector>
// #include <iostream>

// template <typename T, typename A>
// int arg_max(std::vector<T, A> const& vec) {
//   return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
// }

// template <typename T, typename A>
// int arg_min(std::vector<T, A> const& vec) {
//   return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
// }


// C++ program to demonstrate the use of std::max_element
#include <iostream>
#include <algorithm>
using namespace std;
 
// Defining the BinaryFunction
// bool comp(int a, int b)
// {
//  return (a < b);
// }
 
// int main()
// {
//  int v[2][5] = { {9, 4, 7, 2, 5}, {10, 11, 12, 1, 3} };
 
 // Finding the maximum value between the third and the
 // ninth element
 
//  int* i1;
//  i1 = std::max_element(v + 2, v + 9, comp);
 
//  cout << *i1 << "\n";
//  return 0;
// }

// std::vector<int>::iterator max = max_element(v.begin() + 2, v.begin() + 4); // [2, 4)
// int argmaxVal = distance(v.begin(), max); // absolute index of max


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// template<typename Container, typename Fn>
// auto max(Container const & c, Fn && key) -> decltype(*std::begin(c))
// {  
//     if ( std::begin(c) == std::end(c) ) 
//        throw std::invalid_argument("empty container is not allowed.");

//     typedef decltype(*std::begin(c)) V;
//     auto cmp = [&](V a, V b){ return key(a) < key(b); };
//     return *std::max_element(std::begin(c), std::end(c), cmp);
// }


// int main(){

//     std::vector<int> l = {1,43,10,17};
//     auto a = max(l, [](int x) { return -1 * std::abs(42-x); });
//     printf("%d",a);

//     // int l[] = {1,43,10,17}; //works with array also!
//     // auto a = max(l, [](int x) { return -1 * std::abs(42-x); });


//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename Container, typename F>
auto max(Container const & c, F && pred) -> decltype(*std::begin(c))
{  
    if ( std::begin(c) == std::end(c) ) 
        throw std::invalid_argument("empty container is not allowed.");

    typedef decltype(*std::begin(c)) V;
    auto cmp = [&](V a, V b){ return pred(a) < pred(b); };
    return *std::max_element(std::begin(c), std::end(c), cmp);
}
 
 namespace test
 {
     template<size_t N>
     struct intcollection
     {
         int _data[N];
         int const * begin() const { return _data; }
         int const * end() const { return _data + N; }
     };
 }
 
int main()
{
    std::vector<int> v = {1,43,52,17};
    auto m = max(v, [](int x) { return -1 * std::abs(10000-x); });
    std::cout << m << std::endl;
    
    int l[] = {1,43,10,17}; //works with array also!
    auto a = max(l, [](int x) { return -1 * std::abs(42-x); });
    std::cout << a << std::endl;
    
    test::intcollection<4> c{{1,43,10,17}}; //works with user-defined container also!
    auto r = max(c, [](int x) { return -1 * std::abs(42-x); });
    std::cout << r << std::endl;
}
