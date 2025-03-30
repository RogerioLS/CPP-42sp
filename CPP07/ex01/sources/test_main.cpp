/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:01:17 by codespace         #+#    #+#             */
/*   Updated: 2025/03/30 17:50:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

class Awesome {
    public:
        Awesome(void) : _n(42) { return; }
        int get(void) const { return this->_n; }
    private:
        int _n;
    };
    
    std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
        o << rhs.get();
        return o;
    }
    
    template <typename T>
    void print(T const &x) {
        std::cout << x << std::endl;
        return;
    }
    
int main() 
{
        int tab[] = {0, 1, 2, 3, 4};
        Awesome tab2[5];
    
        iter(tab, 5, print<int>);
        iter(tab2, 5, print<Awesome>);
    
        return 0;
}