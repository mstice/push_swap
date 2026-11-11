# push_swap
Grade achieved: 90% ✅

## 🎯 Objective
To minimise the number of operations made when sorting large datasets.

## ℹ️Description
#### Concepts: Algorithms and Data Structures
- A program to sort numbers with the least move complexity
- Goal: to sort 100 numbers in less than 700 moves, 500 in <5500 using two stacks
- Used a quicksort algorithm to solve this problem
- A few more optimisations could have been added:
    - Combining instructions for similar moves (i.e. an ra + rb instruction is the same as rr)
    - Implementing another sorting algorithm for when "chunks" of numbers become smaller (i.e. merge sort), as quicksort becomes less efficient with smaller sets of numbers

#### Allowed operations:
- **pa:** push top of stack b to stack a
- **pb:** same as pa on stack b
- **ra:** top element of stack a is placed at the bottom of the stack
- **rb:** same as ra on stack b
- **rr:** ra + rb
- **sa:** swap first two elements of stack a
- **sb:** same as sa on stack b
- **ss:** sa + sb
- **rra:** last element of stack a is placed at the top
- **rrb:** same as rra on stack b
- **rrr:** rra + rrb

> Achieved an average of 760 operations for a set of 100 integers, and 4900 operations for a set of 500 integers

## 🛠️ Usage
```bash
make
./push_swap 5 3 4 2 1
```

## 👥 Authors
Matilda Tice (Github: mstice, 42: mtice)  
<sub>Cover image by [Ayogun](https://github.com/ayogun/42-project-badges)</sub>
