

 

| Type        | Description                                                  | Finished |
| ----------- | ------------------------------------------------------------ | -------- |
| **Type 1**  | a variable is used without a definition                      | Finish   |
| **Type 2**  | a function is invoked without a definition                   | Finish   |
| **Type 3**  | a variable is redefined in the same scope                    | Finish   |
| **Type 4**  | a function is redefined (in the global scope, since we don’t have nested functions) | Finish   |
| **Type 5**  | unmatching types appear at both sides of the assignment operator (=) | Finish   |
| **Type 6**  | rvalue appears on the left-hand side of the assignment operator | Finish   |
| **Type 7**  | unmatching operands, such as adding an integer to a structure variable | Finish   |
| **Type 8**  | a function’s return value type mismatches the declared type  | Finish   |
| **Type 9**  | a function’s arguments mismatch the declared parameters (either types or numbers, or both) | Finish   |
| **Type 10** | applying indexing operator ([…]) on non-array type variables | Finish   |
| **Type 11** | applying function invocation operator (foo(…)) on non-function names | Finish   |
| **Type 12** | array indexing with a non-integer type expression            | Finish   |
| **Type 13** | accessing members of a non-structure variable (i.e., misuse the dot operator) | Finish   |
| **Type 14** | accessing an undefined structure member                      | Finish   |
| **Type 15** | redefine the same structure type                             |          |



test_11

test_15