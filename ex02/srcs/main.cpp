/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:17:43 by nbodin            #+#    #+#             */
/*   Updated: 2026/01/20 16:26:52 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void testComparisons()
{
    std::cout << "=== COMPARISON TESTS ===" << std::endl;
    
    // Positive integers
    Fixed a(3);
    Fixed b(5);
    Fixed c(5);  // Equal to b
    
    std::cout << "\n--- Positive integers (3, 5, 5) ---" << std::endl;
    std::cout << "a(3) > b(5): " << (a > b ? "TRUE" : "FALSE") << " (expect FALSE)" << std::endl;
    std::cout << "a(3) < b(5): " << (a < b ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "b(5) == c(5): " << (b == c ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "b(5) >= c(5): " << (b >= c ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "a(3) != b(5): " << (a != b ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Negative integers
    Fixed d(-2);
    Fixed e(-6);
    Fixed f(-6);  // Equal to e
    
    std::cout << "\n--- Negative integers (-2, -6, -6) ---" << std::endl;
    std::cout << "d(-2) > e(-6): " << (d > e ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "d(-2) < e(-6): " << (d < e ? "TRUE" : "FALSE") << " (expect FALSE)" << std::endl;
    std::cout << "e(-6) == f(-6): " << (e == f ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "e(-6) <= f(-6): " << (e <= f ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Positive vs Negative
    std::cout << "\n--- Positive vs Negative ---" << std::endl;
    std::cout << "a(3) > d(-2): " << (a > d ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "d(-2) < a(3): " << (d < a ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "a(3) != d(-2): " << (a != d ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Zero tests
    Fixed zero(0);
    Fixed pos(5);
    Fixed neg(-5);
    
    std::cout << "\n--- Zero tests ---" << std::endl;
    std::cout << "zero(0) == zero(0): " << (zero == Fixed(0) ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "pos(5) > zero(0): " << (pos > zero ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "neg(-5) < zero(0): " << (neg < zero ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "zero(0) >= neg(-5): " << (zero >= neg ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "zero(0) <= pos(5): " << (zero <= pos ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
}

void testFloats()
{
    std::cout << "\n=== FLOAT TESTS ===" << std::endl;
    
    // Positive floats
    Fixed a(3.5f);
    Fixed b(5.75f);
    Fixed c(5.75f);
    
    std::cout << "\n--- Positive floats (3.5, 5.75, 5.75) ---" << std::endl;
    std::cout << "a(3.5) < b(5.75): " << (a < b ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "b(5.75) == c(5.75): " << (b == c ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "a(3.5) != b(5.75): " << (a != b ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Negative floats
    Fixed d(-2.5f);
    Fixed e(-6.25f);
    Fixed f(-6.25f);
    
    std::cout << "\n--- Negative floats (-2.5, -6.25, -6.25) ---" << std::endl;
    std::cout << "d(-2.5) > e(-6.25): " << (d > e ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "e(-6.25) == f(-6.25): " << (e == f ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Positive vs Negative floats
    std::cout << "\n--- Positive vs Negative floats ---" << std::endl;
    std::cout << "a(3.5) > d(-2.5): " << (a > d ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "d(-2.5) < a(3.5): " << (d < a ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Zero float
    Fixed zero(0.0f);
    Fixed posFloat(2.5f);
    Fixed negFloat(-2.5f);
    
    std::cout << "\n--- Zero float tests ---" << std::endl;
    std::cout << "zero(0.0) == Fixed(0.0): " << (zero == Fixed(0.0f) ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "posFloat(2.5) > zero(0.0): " << (posFloat > zero ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "negFloat(-2.5) < zero(0.0): " << (negFloat < zero ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    
    // Epsilon tests
    Fixed epsilon(0.00390625f);  // 1/256
    Fixed almostZero(0.001f);    // Will round to 0.00390625
    
    std::cout << "\n--- Epsilon tests ---" << std::endl;
    std::cout << "epsilon value: " << epsilon << " (expect ~0.00390625)" << std::endl;
    std::cout << "almostZero(0.001f): " << almostZero << " (rounded to nearest epsilon)" << std::endl;
    std::cout << "epsilon > zero: " << (epsilon > zero ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
    std::cout << "epsilon == Fixed(0.00390625f): " << (epsilon == Fixed(0.00390625f) ? "TRUE" : "FALSE") << " (expect TRUE)" << std::endl;
}

void testArithmetic()
{
    std::cout << "\n=== ARITHMETIC TESTS ===" << std::endl;
    
    Fixed a(5);
    Fixed b(2);
    
    std::cout << "\n--- Basic arithmetic (5, 2) ---" << std::endl;
    std::cout << "a + b = " << (a + b) << " (expect 7)" << std::endl;
    std::cout << "a - b = " << (a - b) << " (expect 3)" << std::endl;
    std::cout << "a * b = " << (a * b) << " (expect 10)" << std::endl;
    std::cout << "a / b = " << (a / b) << " (expect 2.5)" << std::endl;
    
    Fixed c(3.5f);
    Fixed d(2.0f);
    
    std::cout << "\n--- Float arithmetic (3.5, 2.0) ---" << std::endl;
    std::cout << "c + d = " << (c + d) << " (expect 5.5)" << std::endl;
    std::cout << "c - d = " << (c - d) << " (expect 1.5)" << std::endl;
    std::cout << "c * d = " << (c * d) << " (expect 7)" << std::endl;
    std::cout << "c / d = " << (c / d) << " (expect 1.75)" << std::endl;
}

void testIncrement()
{
    std::cout << "\n=== INCREMENT/DECREMENT TESTS ===" << std::endl;
    
    Fixed a(5);
    std::cout << "\n--- Starting with a = " << a << " ---" << std::endl;
    
    std::cout << "++a = " << ++a << " (expect " << (5 + 0.00390625f) << ")" << std::endl;
    std::cout << "a = " << a << std::endl;
    
    std::cout << "a++ = " << a++ << " (expect previous value)" << std::endl;
    std::cout << "a = " << a << " (expect " << (5 + 2*0.00390625f) << ")" << std::endl;
    
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << " (back to ~5)" << std::endl;
}

void    testFt()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
}

int main()
{
    // testComparisons();
    // testFloats();
    // testArithmetic();
    // testIncrement();
    
    testFt();
    
    return 0;
}