#include <iostream>
#include <unordered_map>
#include <string>

// Data structure representing a Turing machine transition
struct Transition {
    std::string currentState;
    char currentSymbol;
    std::string nextState;
    char newSymbol;
    char moveDirection; // 'L' for left, 'R' for right

    Transition(const std::string& currState, char currSym, const std::string& nextState,
               char newSym, char moveDir)
        : currentState(currState), currentSymbol(currSym), nextState(nextState),
          newSymbol(newSym), moveDirection(moveDir) {}
};

// Function to simulate Turing machine on the input tape
bool simulateTuringMachine(char tape[], const char transitions[]) {
    std::unordered_map<std::string, Transition> transitionMap;

    // Parse transition function and populate transitionMap
    // Example: currentState,currentSymbol -> nextState,newSymbol,moveDirection

    char* token = strtok(const_cast<char*>(transitions), "\n");
    while (token != nullptr) {
        std::string currentState, nextState;
        char currentSymbol, newSymbol, moveDirection;
        sscanf(token, "%s,%c -> %s,%c,%c", currentState.data(), &currentSymbol,
               nextState.data(), &newSymbol, &moveDirection);
        transitionMap[currentState + currentSymbol] =
            Transition(currentState, currentSymbol, nextState, newSymbol, moveDirection);
        token = strtok(nullptr, "\n");
    }

    std::string currentState = "q0";
    int headIndex = 0;

    while (true) {
        char currentSymbol = tape[headIndex];

        // Check if a transition is defined for the current state and symbol
        auto it = transitionMap.find(currentState + currentSymbol);
        if (it == transitionMap.end()) {
            break; // Halt and reject input
        }

        Transition& transition = it->second;

        // Update current state
        currentState = transition.nextState;

        // Write new symbol to tape
        tape[headIndex] = transition.newSymbol;

        // Move head position
        if (transition.moveDirection == 'L') {
            headIndex--;
        } else if (transition.moveDirection == 'R') {
            headIndex++;
        }

        // Expand tape if necessary
        if (headIndex < 0) {
            headIndex = 0;
            char* newTape = new char[strlen(tape) + 2];
            strcpy(newTape + 1, tape);
            newTape[0] = '_'; // Blank symbol
            delete[] tape;
            tape = newTape;
        } else if (headIndex >= strlen(tape)) {
            char* newTape = new char[strlen(tape) + 2];
            strcpy(newTape, tape);
            newTape[strlen(tape)] = '_'; // Blank symbol
            newTape[strlen(tape) + 1] = '\0';
            delete[] tape;
            tape = newTape;
        }
    }

    // Check if the final state is an accepting state
    return currentState == "qaccept";
}

// Function to visualize Turing machine states and transitions
void visualizeTuringMachine(const char transitions[]) {
    // Implementation details for generating visual representation
}

int main() {
    char tape[] = "101011"; // Input tape
    char transitions[] =
        "q0,1 -> q0,1,R\n"
        "q0,0 -> q1,_,L\n"
        "q1,1 -> q2,_,R\n"
        "q1,0 -> q1,0,L\n"
        "q2,1 -> q2,1,R\n"
        "q2,0 -> q3,_,L\n"
        "q3,1 -> qreject,_,R\n"
        "q3,0 -> q3,0,L\n"
        "q3,_ -> qaccept,_,R"; // Transition function

    if (simulateTuringMachine(tape, transitions)) {
        std::cout << "Turing machine halted and accepted the input." << std::endl;
    } else {
        std::cout << "Turing machine halted and rejected the input." << std::endl;
    }

    visualizeTuringMachine(transitions);

    return 0;
}
