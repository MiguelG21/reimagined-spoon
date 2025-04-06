#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

void solve1(std::string string) {
	std::stack<char> stack;
	for (int i = 0; i < string.length(); i++) {
		stack.push(string[i]);
	}
	for (int i = 0; i < string.length(); i++) {
		string[i] = stack.top();
		stack.pop();
	}
	std::cout << string;
}

void solve2(std::string string) {	
	std::stack<char> stack;
	for (char c : string) {
		if (c == ')') {
			if (!stack.empty() && stack.top() == '(') {
				stack.pop();
			}
			else {
				std::cout << "invalid";
				return;
			}
		}
		else {
			stack.push(c);
		}
		
	}
	if (!stack.empty()) {
		std::cout << "invalid string";
	}
	else {
		std::cout << "valid string";
	}
}

class StackUsingQueues {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
   
        int poppedElement = queue1.front();
        queue1.pop();

        std::swap(queue1, queue2);
        return poppedElement;
    }

    int top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }

        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int topElement = queue1.front();

        queue2.push(topElement);
        queue1.pop();

        std::swap(queue1, queue2);
        return topElement;
    }

    bool empty() const {
        return queue1.empty();
    }

    int size() const {
        return queue1.size();
    }
};

std::vector<int> nextGreaterElement(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> result(n, -1);
    std::stack<int> stack; // Stack to store indices

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && arr[stack.top()] < arr[i]) {
            int poppedIndex = stack.top();
            stack.pop();
            result[poppedIndex] = arr[i];
        }
        stack.push(i);
    }
    return result;
}

void solve5(const std::string& expression) {
    std::istringstream stream(expression);
    std::string token;
    std::stack<int> stack;
    std::vector<std::string> operators = { "+","-", "*", "/" };

    while (stream >> token) {
        auto it = std::find(operators.begin(), operators.end(), token);
        if (it == operators.end()) {
            stack.push(std::stoi(token));
        }
        else {
            int operand1 = stack.top();
            stack.pop();
            int operand2 = stack.top();
            stack.pop();
            
            int result;
            switch (token[0]) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand2 - operand1;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand1 == 0) {
                    std::cout << "Error Division by 0!";
                    return;
                }
                else {
                    result = operand2 / operand1;
                    break;
                }
            }
            stack.push(result);
        }
    }
    if (stack.size() == 1) {
        std::cout << stack.top();
    }
    else {
        std::cout << "Error in input";
    }
}
class QueueUsingStacks {
private:
    std::stack<int> stackEnqueue;
    std::stack<int> stackDequeue;

public:
    void enqueue(int x) {
        stackEnqueue.push(x);
    }

    int dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        // If stackDequeue is empty, transfer elements from stackEnqueue
        if (stackDequeue.empty()) {
            while (!stackEnqueue.empty()) {
                stackDequeue.push(stackEnqueue.top());
                stackEnqueue.pop();
            }
        }
        int frontElement = stackDequeue.top();
        stackDequeue.pop();
        return frontElement;
    }

    int peek() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        if (stackDequeue.empty()) {
            while (!stackEnqueue.empty()) {
                stackDequeue.push(stackEnqueue.top());
                stackEnqueue.pop();
            }
        }
        return stackDequeue.top();
    }

    bool empty() const {
        return stackEnqueue.empty() && stackDequeue.empty();
    }

    size_t size() const {
        return stackEnqueue.size() + stackDequeue.size();
    }
};

void solve7(int n) {
    if (n <= 0) {
        return;
    }

    std::queue<std::string> q;

    // Enqueue the first binary number (1)
    q.push("1");
    std::cout << q.front() << " ";

    // Generate and print binary numbers up to N
    for (int i = 1; i < n; ++i) {
        // Get the current binary number from the front of the queue
        std::string current = q.front();
        q.pop();

        // Generate the next two binary numbers by appending '0' and '1'
        std::string next1 = current + "0";
        std::string next2 = current + "1";

        // Enqueue the generated binary numbers
        q.push(next1);
        q.push(next2);

        // Print the next binary number (which is now at the front)
        std::cout << q.front() << " ";
    }
    std::cout << std::endl;
}

int main() {
	solve7(300);
	return 0;
}