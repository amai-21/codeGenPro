# CodeGenPro

### Author
 - Andy Mai

# Project Overview

"CodeGenPro" is a compiler written in C++ that scans, parses, semantically checks, and translates a custom language into the University of Missouri-St.Louis's (UMSL) Assembly language. For more information on UMSL's assembly language, please visit https://comp.umsl.edu/assembler/index for more information.

# Built With
 - C++

# Features
- **Binary Search Tree Feature (P0 Component)**
	Creates a binary search tree based on the number of characters in a string and performs level-order, pre-order, and post-order traversal on the BST.

- **Lexical Analyzer (Tokenizer)**
	Implements a deterministic finite automaton (DFA) to tokenize input source code. Recognizes custom-defined token types such as identifiers (b0, Z421, x1000), numbers (+0, +1000), and special symbols ('!', '"', "#").

- **Recursive Descent Parser**
	Builds a parse tree based on a grammar that is LL(k<=1). Parses valid program syntax and returns a structured and indented representation of sequences of statements and nested statements.

- **Static Semantics Checker**
	Traverses through the parse tree to ensure that variables are properly declared before usage. Maintains a symbol table to detect redefinitions and undeclared identifiers.

- **Code Generator**
	Traverses the parse tree to generate target VM accumulator assembly code. Produces output for nested expressions and control constructs.

# How to Run Locally
1.) **Clone the repository:**
	git clone https://github.com/amai-21/codeGenPro.git

2.) **Navigate to the P4 Directory**
	cd codeGenPro/P4

3.) **Compile the project**
	make

4.) **Run the project**
	./P4 [filename]

5.) **Check the output file with UMSL's virtual machine**
	./virtMach [filename].asm 

## License

This project is licensed under the [MIT License](LICENSE) - see the License file for details.



 
