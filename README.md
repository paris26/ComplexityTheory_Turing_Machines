# Maximum Consecutive Unique Sequence Algorithms

## Overview

This repository contains implementations of different algorithms for finding the longest sequence of numbers without adjacent duplicates from a given input array. The project compares three different approaches: Brute Force, Optimized Solution, and Optimal (Merge-based) Solution.

## Problem Description

Given an array of integers, find the longest possible sequence where no two adjacent numbers are the same. The algorithms handle various cases including:
- Sequences with single or multiple duplicates
- Already unique sequences
- Empty sequences
- Sequences with patterns
- Large random sequences

## Project Structure

```plaintext
├── BruteForceSequence.h/.cpp   # Brute force implementation
├── OptimizedSequence.h/.cpp    # Optimized solution using spacing technique
├── OptimalSequence.h/.cpp      # Optimal solution using merge-based approach
├── UniqueNumbers.h/.cpp        # Utility for unique number analysis
├── helper.h                    # Helper functions
└── main.cpp                    # Main program with test cases
