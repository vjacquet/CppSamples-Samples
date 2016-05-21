// Command
// C++11

// command.h - header file

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

using command = std::function<void()>;

class registry
{
	private:
		std::unordered_map<std::string, command> r;
		void invoke(std::string name)
		{
			r.at(name)();
		}

	public:
		void declare(std::string name, command&& cmd)
		{
			r[name] = cmd;
		}

		void operator()(std::string name)
		{
			invoke(name);
		}
};

// command.cpp - implementation file


// Encapsulate all the information needed to call a method at a later time.
// 
// The command pattern allows to construct general components that need to delegate, 
// sequence or execute method calls without the need to know the function or its parameters.
// Using a registry allows loose coupling and the invoke method allows bookkeeping 
// about command executions.
// 
// The `command` is an alias on 
// [`std::function`](cpp/utility/functional/function) so it can wrap any callable object.
// 
// The `registry` stores the commands in an [`std::unordered_map`](cpp/container/unordered_map)
// for O(1) lookup on average.

int main()
{
	registry r;
	r.declare("a", [=]() { std::cout << "Calling a\n"; });
	r.declare("b", [=]() { std::cout << "Calling b\n"; });

	r("a");
	r("b");
}
