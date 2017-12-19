/**
 * Header file of anagram generator
 * @file generator.h
 * @author Jakub Majzlik
 * @version 1.0
 */

#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <stdbool.h>

/**
 * @brief Generate anagram from string.
 * 
 * @param word String from which anagram will be generated.
 * @return true Generating of anagram went without problem.
 * @return false Coudn't alloc memory for temp string.
 */
bool generate_anagram(char **word);

#endif