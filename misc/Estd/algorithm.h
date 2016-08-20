#ifndef ESTD_ALGORITHM
#define ESTD_ALGORITHM

#include <algorithm>

namespace Estd {

    template<class C>
    void sort(C &c) {
        std::sort(c.begin(), c.end());
    }

    template<class C, class Pred>
    void sort(C &c, Pred p) {
        std::sort(c.begin(), c.end(), p);
    }

    template<class C, class Pred>
    typename C::iterator find_if(C &c, Pred p) {
        return std::find_if(c.begin(), c.end(), p);
    }

    template<class C, class Pred>
    bool any_of(C &c, Pred p) {
        return std::any_of(c.begin(), c.end(), p);
    }

    template<class C, class Pred>
    bool all_of(C &c, Pred p) {
        return std::all_of(c.begin(), c.end(), p);
    }

    template<class C, class Pred>
    typename C::size_type count_if(C& c, Pred& p) {
        return std::count_if(c.begin(),c.end(),p);
    }

    template<class C, class D>
    void copy_iterators(C& c, D& d) { // c is source, d is target //TODO: c should be const
        auto d_iter = d.begin();
        for(typename C::iterator c_iter = c.begin(); c_iter != c.end(); ++c_iter) {
            *d_iter = c_iter;
            ++d_iter;
        }
    }

    template<class C, class D, class Pred>
    void copy_iterators(C& c, D& d, Pred& p) {
        auto d_iter = d.begin();
        for(typename C::iterator c_iter = c.begin(); c_iter != c.end(); ++c_iter) {
            if ( p(*c_iter) ) {
                *d_iter = c_iter;
                ++d_iter;
            }
        }
    }
}

#endif
