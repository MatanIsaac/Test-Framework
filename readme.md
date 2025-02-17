# <div align="center">Test Framework for C Projects</div>

## <div align="center">Overview</div>

This is a **simple, lightweight unit testing framework** for C programs, designed to log and validate test cases. It provides:

- **Structured test result logging** (pass/fail/other).
- **Timestamped logs** for test tracking.
- **Easy integration** into existing C projects.
- **Custom logging functions** to output messages.

---

## <div align="center">📌 Features</div>

✅ **Lightweight & Header-Only** - Minimal dependencies, easy to use in any C project.  
✅ **Log-Based Reporting** - Test results are formatted with timestamps for easy debugging.  
✅ **Customizable Logging** - Uses `logger.h` to format test output to `stdout` or `stderr`.  
✅ **Supports Different Test Outcomes** - `Pass`, `Fail`, and `Other` (for skipped, timeout, crash scenarios).  

---

## <div align="center">🚀 Getting Started</div>

### **1️⃣ Include the Framework**
Ensure your project includes:
```c
#include "test_framework.h"

2️⃣ Writing a Test Case

Each test case logs its name, status, and details:

void test_example() {
    log_test("Example Test", TEST_PASS, "This test passed successfully.");
}

3️⃣ Running Tests

In your main.c, call your test functions:

int main(void) {
    test_example();
    return 0;
}

4️⃣ Expected Output

A sample test output:

[LOG] File: test_framework.h | Line: 27 | Date: 2024-02-17 | Time: 15:45:23
    Test:   [Example Test]
    Result: [PASS]
    Details: [This test passed successfully.]

<div align="center">📂 Project Structure</div>

├── test_framework.h         # Test framework (header-only)
├── logger.h                 # Logging utilities
├── logger.c                 # Implementation of logging functions
├── example_code_to_test.h   # Utility functions for tests
├── example_code_to_test.c   # String operations (malloc, strdup, etc.)
├── main.c                   # Test runner
├── Makefile                 # Build system

<div align="center">⚙ Build & Run</div>
🔧 Compiling

This project is built using Makefile. Run:

make

▶ Running Tests

Execute the compiled test program:

./test

🧹 Cleaning Build Files

make clean

<div align="center">🛠 Test API Reference</div>
1️⃣ Logging Test Results

void log_test(const char* test_name, TestResultType result, const char* details);

    test_name: The name of the test.
    result: TEST_PASS, TEST_FAIL, or TEST_OTHER.
    details: Description of the test result.

Example:

log_test("Test Case 1", TEST_PASS, "Memory allocation worked correctly.");

2️⃣ Enum for Test Results

typedef enum {
    TEST_PASS,  // The test passed
    TEST_FAIL,  // The test failed
    TEST_OTHER  // Any other status (e.g., skipped, timeout, error)
} TestResultType;

3️⃣ Converting Test Results to Strings

const char* test_result_to_string(TestResultType result);

Returns "PASS", "FAIL", or "OTHER".
<div align="center">📝 Example Tests</div>

Example test for string functions:

void test_string_functions() {
    char* str = string_malloc(10);
    if (str) {
        log_test("Test_string_malloc", TEST_PASS, "Memory allocation successful.");
        free(str);
    } else {
        log_test("Test_string_malloc", TEST_FAIL, "Memory allocation failed.");
    }
}

<div align="center">📜 License</div>

This test framework is open-source. Feel free to modify and use it in your projects. Credits appreciated if you find it useful! 🚀