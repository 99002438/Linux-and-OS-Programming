![cppcheck-action](https://github.com/99002438/Linux-and-OS-Programming/workflows/cppcheck-action/badge.svg?branch=master)
![C/C++ CI](https://github.com/99002438/Linux-and-OS-Programming/workflows/C/C++%20CI/badge.svg?branch=master)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d6d4b931311e42768db3580e6e05a5aa)](https://app.codacy.com/manual/99002438/Linux-and-OS-Programming?utm_source=github.com&utm_medium=referral&utm_content=99002438/Linux-and-OS-Programming&utm_campaign=Badge_Grade_Settings)

## Mini -Project

Reader- Writer Problem

## Problem Statement

In case a database to be shared among several processes, then this reader-writer problem takes place. Some of these processes may want only to read, some may want only to write or update the database. We distinguish this as reader and writer.If two readers access the shared data simultaneously, no adverse effects will result.
But if a writer and some other process access the database simultaneously, chaos may happen.

To ensure that these difficulties do not arise, we require that the writers have exclusive access to the shared database while writing to the database. This synchronisation problem is referred to as the readers-writers problem.

## Compiling the program:
gcc miniproject.c -pthread

## Running the program :
./a.out
