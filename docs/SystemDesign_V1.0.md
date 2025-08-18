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
1. Reliability: THe system should be highly available, producing correct results for all valid input without crashing. It should handle edge cases like division by zero gracefully.
2. Performance: The calculator should provide near-instantaneous results, even for complex calculations with large number
3. Usability: The user interface (UI) should be intuitive and easy to use.
4. Precision: All calculations must use a high-precision numerical system to avoid the inherent limitations of standard floating-point arithmetic.
5. Maintainability: The code should be well-structured, easy to understand, and simple to modify for future feature additions (e.g., adding scientific functions).
6. Testability: The application logic (the calculator's engine) should be separated from the UI and thoroughly tested.

## API Layer

## Deep Dive

## High Level Design