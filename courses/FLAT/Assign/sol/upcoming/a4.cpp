#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <set>

// Data structure representing a state in an automaton
struct State {
    std::unordered_set<int> states;
    std::unordered_map<char, std::unordered_set<int>> transitions;

    State() {}
};

// Function to convert NFA to DFA using the powerset construction algorithm
std::vector<State> convertNFAtoDFA(const std::vector<State>& nfa) {
    std::vector<State> dfa;

    // Step 1: Create the initial state of the DFA containing the epsilon closure of the initial state of the NFA
    std::unordered_set<int> initialClosure = nfa[0].states;
    std::stack<int> dfsStack;
    std::unordered_set<int> visited;

    for (int state : initialClosure) {
        dfsStack.push(state);
        visited.insert(state);
    }

    while (!dfsStack.empty()) {
        int currentState = dfsStack.top();
        dfsStack.pop();

        for (auto& transition : nfa[currentState].transitions) {
            char symbol = transition.first;
            for (int nextState : transition.second) {
                if (symbol == '$') {
                    if (visited.find(nextState) == visited.end()) {
                        dfsStack.push(nextState);
                        visited.insert(nextState);
                        initialClosure.insert(nextState);
                    }
                }
            }
        }
    }

    dfa.push_back(State());
    dfa[0].states = initialClosure;

    // Step 2: Build the remaining states of the DFA
    std::queue<std::unordered_set<int>> unmarkedStates;
    unmarkedStates.push(initialClosure);

    std::unordered_map<std::unordered_set<int>, int> stateIndexMap;
    stateIndexMap[initialClosure] = 0;

    while (!unmarkedStates.empty()) {
        std::unordered_set<int> currentStateSet = unmarkedStates.front();
        unmarkedStates.pop();

        int currentStateIndex = stateIndexMap[currentStateSet];

        // Process transitions for each symbol
        for (auto& transition : nfa[currentStateSet.begin().operator*()].transitions) {
            char symbol = transition.first;
            std::unordered_set<int> nextStateSet;

            for (int currentState : currentStateSet) {
                for (int nextState : nfa[currentState].transitions[symbol]) {
                    nextStateSet.insert(nextState);
                    dfsStack.push(nextState);
                }
            }

            while (!dfsStack.empty()) {
                int currentState = dfsStack.top();
                dfsStack.pop();

                for (auto& transition : nfa[currentState].transitions) {
                    char symbol = transition.first;
                    for (int nextState : transition.second) {
                        if (symbol == '$') {
                            if (nextStateSet.find(nextState) == nextStateSet.end()) {
                                dfsStack.push(nextState);
                                nextStateSet.insert(nextState);
                            }
                        }
                    }
                }
            }

            // Check if the next state set is already in the DFA
            if (stateIndexMap.find(nextStateSet) == stateIndexMap.end()) {
                unmarkedStates.push(nextStateSet);
                stateIndexMap[nextStateSet] = dfa.size();
                dfa.push_back(State());
                dfa.back().states = nextStateSet;
            }

            int nextStateIndex = stateIndexMap[nextStateSet];
            dfa[currentStateIndex].transitions[symbol].insert(nextStateIndex);
        }
    }

    return dfa;
}

// Function to convert DFA to regular expression using state elimination technique
std::string convertDFAtoRegex(const std::vector<State>& dfa) {
    std::vector<std::vector<std::string>> regex(dfa.size(), std::vector<std::string>(dfa.size(), ""));

    // Initialize diagonal elements with the symbols corresponding to self-loops
    for (int i = 0; i < dfa.size(); ++i) {
        for (auto& transition : dfa[i].transitions) {
            char symbol = transition.first;
            auto& nextStates = transition.second;
            if (nextStates.find(i) != nextStates.end()) {
                regex[i][i] += symbol;
            }
        }
    }

    // Calculate regular expressions for the remaining elements using state elimination technique
    for (int k = 0; k < dfa.size(); ++k) {
        for (int i = 0; i < dfa.size(); ++i) {
            for (int j = 0; j < dfa.size(); ++j) {
                std::string& existingRegex = regex[i][j];
                std::string regex1 = regex[i][k];
                std::string regex2 = regex[k][j];
                if (!regex1.empty() && !regex2.empty()) {
                    if (!existingRegex.empty()) {
                        existingRegex = "(" + existingRegex + "+" + regex1 + regex2 + ")";
                    } else {
                        existingRegex = regex1 + regex2;
                    }
                }
            }
        }
    }

    return regex[0][dfa.size() - 1];
}

int main() {
    std::vector<State> nfa{
        // Implementation details for constructing the NFA
    };

    std::vector<State> dfa = convertNFAtoDFA(nfa);

    std::string regex = convertDFAtoRegex(dfa);

    return 0;
}
