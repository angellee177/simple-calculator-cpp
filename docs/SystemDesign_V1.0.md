# System Design V1.0
## Functional Requirements
1. User be able to calculate the basic operator (i.e +, -, /, *).
2. User get the precise number as the result.
3. User can use parentheses to specify the order of operation
4. User can perform chain operator (i.e 2 + 3 * 4)
5. The system should allow clearing the current input and the last result.
6. The system should handle a single history entry, displaying the previous result.
7. The system should display a clear display of the current expression and the final result.

## Non-functional Requirements
1. **Reliability**: The system should be highly available, producing correct results for all valid input without crashing. It should handle edge cases like division by zero gracefully.
2. **Performance**: The calculator should provide near-instantaneous results, even for complex calculations with large number
3. **Usability**: The user interface (UI) should be intuitive and easy to use.
4. **Precision**: All calculations must use a high-precision numerical system to avoid the inherent limitations of standard floating-point arithmetic.
5. **Maintainability**: The code should be well-structured, easy to understand, and simple to modify for future feature additions (e.g., adding scientific functions).
6. **Testability**: The application logic (the calculator's engine) should be separated from the UI and thoroughly tested.

## API Layer (Library Protocol)
The definition of an API is a contract for communication between two different applications. While the most common API protocols use networks (like SOAP, gRPC, Http/Https,and WebSocket) for communication between a client and a remote server, this project will use a library protocol.

The C++ backend's core logic will be compiled into a native library that is directly embedded within the SwiftUI app bundle. This makes the "API" a set of public functions in the C++ header file, which the SwiftUI code can call directly. This approach eliminates the need for a separate cloud-based server, avoiding network latency and recurring hosting costs.

For more explanation about APIs, read [here](https://angellee177.hashnode.dev/what-is-api-exactly-things-i-wish-i-had-known-earlier#heading-a-text-based-formats)
### Public functions in the C++ API:
- `std:string evaluateExpression(const std::string& expression)`: Basically the `evaluateExpression(const std::string& expression)` function take the full mathematical expression as a string type, then return the calculation result as a string.
- `void clear()`: This `clear()` function is to resets the entire calculator state, including the current expression and result history.
- `void backspace()`: Delete the last character from the current expression.
- `std::string getExpression()`: Returns the string of the expression currently being typed by the user.
- `std::string getHistoryResult()`: Returns the previous calculated result for the history display.

## Deep Dive
### A. Precision & Data Expression
#### Problem:
Standard floating point (double, float) are not enough for a high-precision calculator due to their inability to represent certain numbers precisely, leading to rounding errors.
Handling custom user expressions requires a robust parsing mechanism.

#### Solution:
To improve the precision and Data Expression, `Double` or `Floating` return types are not enough, especially when handling custom user expression like `()`.
1. **Custom class for higher precision:** implement a `BigNumber` class in C++, this class will represent numbers as a string or an array of digits, allowing for arbitrary length and precision. All arithmetic operations(`+`, `-`, `/`, `*`) will be overload as methods within this class to handle the complex, digit-by-digit calculations. This ensure that precision is maintained regardless of the number's of size.
2. **Expression Parsing:** The `evaluateExpression` function will use a `two-stack` algorithm, one for numbers and one for operators to correctly parse and evaluate the users string input. This approach make sure we handling the order of operations and parentheses.
3. **Error Handling:** The `evaluateExpression` function will include logic to detect a division by zero and return a specific error string (e.g., "Error: Division by Zero"), or we can just simply return `undefined` on the UI side. This solution meets [the reliability requirements](SystemDesign_V1.0.md#non-functional-requirements).

### B. Performance & Memory Management
#### Problem:
To ensure instaneous results, the system must perform calculations efficiently and manage memory effectively to prevent crashes or slowdowns.

#### Solution:
1. **Leverage C++ Performance:** Using C++ for the core logic, to take the advantage of its low-level performance and efficient execution.
2. **Memory Management:** Using memory management in C++.

## High Level Design

## Footnotes
- `void`: function in C++ is being used when the function return nothing.
- `std::string&`: in c++ `std::string&`, means reference to a `std::string` object, it creates an alias for an existing `std::string` without creating a copy.
- **Arbitrary length:** Refers to data structure ability to hold a sequence of characters or digits of any size, limited only by the available system memory. This is crucial for high-precision calculator that needs to handle extremely large or small numbers without a predertemined size limit.
- **Algorithm:** in Computer Science context, Algorithm means step by step procedure for solving a computational problem that have finite time and space complexity.
- **Data Structure:** in Computer Science context, Data structure means a way to store and organize data in a computer so that it can be accessed and modified efficiently. Example of Data structure is Array, Linked List, Heap, Stack, Queue.
- **Heap:** A specialized tree-based data structure that satisfy Heap property (Structure properties and Order properties)
