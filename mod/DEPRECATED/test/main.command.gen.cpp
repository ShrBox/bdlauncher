// Generated by scripts/generate_command_definition.py

#include "main.command.h"

template <> class BDL::CustomCommand::CommandParameterProxy<TestDynEnum>
	: public CommandParameterProxy<std::string> {
public:
	inline static constexpr auto type = CommandParameterDataType::SOFT_ENUM;

	operator TestDynEnum() const noexcept { return {value}; }
};

template <> class BDL::CustomCommand::CommandParameterProxy<TestEnum> {
	TestEnum value;

public:
static auto fetch_tid() { return type_id<CommandRegistry, TestEnum>(); }
static constexpr auto parser = &CommandRegistry::fake_parse;
static constexpr auto type = CommandParameterDataType::NORMAL;
static constexpr auto enum_name = "TestEnum";

operator TestEnum() const noexcept { return value; }
};

struct TestCommand_0 : Command {
	CommandParameterProxy<int> num;
	CommandParameterProxy<float> flo;
	CommandParameterProxy<bool> flag;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		TestCommand context {origin, output};
		context.impl(num, flo, flag);
	}
};

struct Test2Command_0 : Command {
	CommandParameterProxy<AutomaticID<Dimension, int> > did;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		Test2Command context {origin, output};
		context.impl(did);
	}
};

struct Test2Command_1 : Command {
	CommandParameterProxy<std::string> str;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		Test2Command context {origin, output};
		context.impl(str);
	}
};

struct Test3Command_0 : Command {
	CommandParameterProxy<TestEnum> en;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		Test3Command context {origin, output};
		context.impl(en);
	}
};

struct Test3Command_1 : Command {
	CommandParameterProxy<int> v;
	CommandParameterProxy<TestDynEnum> en;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		Test3Command context {origin, output};
		context.impl(v, en);
	}
};

struct TestSelectorCommand_0 : Command {
	CommandParameterProxy<CommandSelector<Actor> > selector;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		TestSelectorCommand context {origin, output};
		context.impl(selector);
	}
};

struct TestJsonCommand_0 : Command {
	CommandParameterProxy<Json::Value> value;
	CommandParameterProxy<RelativeFloat> rf;
	virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
		TestJsonCommand context {origin, output};
		context.impl(value, rf);
	}
};

void register_commands() {
	auto &instance = CustomCommandRegistry::getInstance();
	instance.registerDynEnum<TestDynEnum>();
	{
		auto &item = instance.registerEnum<TestEnum>();
		item.addValue("a", TestEnum::A);
		item.addValue("b", TestEnum::B);
		item.addValue("c", TestEnum::C);
	}
	{
		auto &cmd = instance.registerCommand<TestCommand>();
		{
			auto &ovl = cmd.registerOverload<TestCommand_0>();
			ovl.addParameter<int>("num", false, offsetof(TestCommand_0, num));
			ovl.addParameter<float>("flo", false, offsetof(TestCommand_0, flo));
			ovl.addParameter<bool>("flag", false, offsetof(TestCommand_0, flag));
		}
	}
	{
		auto &cmd = instance.registerCommand<Test2Command>();
		{
			auto &ovl = cmd.registerOverload<Test2Command_0>();
			ovl.addParameter<AutomaticID<Dimension, int> >("did", false, offsetof(Test2Command_0, did));
		}
		{
			auto &ovl = cmd.registerOverload<Test2Command_1>();
			ovl.addParameter<std::string>("str", false, offsetof(Test2Command_1, str));
		}
	}
	{
		auto &cmd = instance.registerCommand<Test3Command>();
		{
			auto &ovl = cmd.registerOverload<Test3Command_0>();
			ovl.addParameter<TestEnum>("en", false, offsetof(Test3Command_0, en));
		}
		{
			auto &ovl = cmd.registerOverload<Test3Command_1>();
			ovl.addParameter<int>("v", false, offsetof(Test3Command_1, v));
			ovl.addParameter<TestDynEnum>("en", false, offsetof(Test3Command_1, en));
		}
	}
	{
		auto &cmd = instance.registerCommand<TestSelectorCommand>();
		{
			auto &ovl = cmd.registerOverload<TestSelectorCommand_0>();
			ovl.addParameter<CommandSelector<Actor> >("selector", false, offsetof(TestSelectorCommand_0, selector));
		}
	}
	{
		auto &cmd = instance.registerCommand<TestJsonCommand>();
		{
			auto &ovl = cmd.registerOverload<TestJsonCommand_0>();
			ovl.addParameter<Json::Value>("value", false, offsetof(TestJsonCommand_0, value));
			ovl.addParameter<RelativeFloat>("rf", false, offsetof(TestJsonCommand_0, rf));
		}
	}
}