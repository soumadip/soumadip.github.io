#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>

// Data structure representing a non-terminal symbol
struct NonTerminal {
    std::string symbol;

    NonTerminal(const std::string& sym) : symbol(sym) {}
};

// Data structure representing a terminal symbol
struct Terminal {
    std::string symbol;

    Terminal(const std::string& sym) : symbol(sym) {}
};

// Data structure representing a production rule
struct ProductionRule {
    NonTerminal leftSide;
    std::vector<std::string> rightSide;

    ProductionRule(const NonTerminal& left, const std::vector<std::string>& right)
        : leftSide(left), rightSide(right) {}
};

// Function to parse the grammar using recursive descent parsing
bool parseTopDown(const std::vector<NonTerminal>& nonTerminals, const std::vector<Terminal>& terminals,
                  const std::vector<ProductionRule>& productionRules, const std::string& input) {
    // Implementation details for recursive descent parsing

    return false;
}

// Function to parse the grammar using bottom-up parsing
bool parseBottomUp(const std::vector<NonTerminal>& nonTerminals, const std::vector<Terminal>& terminals,
                   const std::vector<ProductionRule>& productionRules, const std::string& input) {
    // Implementation details for bottom-up parsing

    return false;
}

int main() {
    std::vector<NonTerminal> nonTerminals{
        // Implementation details for defining non-terminals
    };

    std::vector<Terminal> terminals{
        // Implementation details for defining terminals
    };

    std::vector<ProductionRule> productionRules{
        // Implementation details for defining production rules
    };

    std::string input = "input string";

    if (parseTopDown(nonTerminals, terminals, productionRules, input)) {
        std::cout << "Input string is accepted by the grammar (Top-Down Parsing)." << std::endl;
    } else {
        std::cout << "Input string is rejected by the grammar (Top-Down Parsing)." << std::endl;
    }

    if (parseBottomUp(nonTerminals, terminals, productionRules, input)) {
        std::cout << "Input string is accepted by the grammar (Bottom-Up Parsing)." << std::endl;
    } else {
        std::cout << "Input string is rejected by the grammar (Bottom-Up Parsing)." << std::endl;
    }

    return 0;
}
